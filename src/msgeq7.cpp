#include "msgeq7.h"

void MSGEQ7::begin(void)
{
	pinMode(_resetPin, OUTPUT);
	pinMode(_strobePin, OUTPUT);
	pinMode(_dataPin, INPUT);
	reset();
}

void MSGEQ7::reset(void)
{

}

void MSGEQ7::read(void)
{
    uint16_t tmpVal;

    // Pulse the reset signal to latch the current MSGEQ7 values
    digitalWrite(_resetPin, HIGH);
    digitalWrite(_resetPin, LOW);
    delayMicroseconds(80);        // Delay to meet the minimum reset-to-strobe time (72us)

    // Cycle through the MSGEQ7's seven spectrum band
    for (uint8_t iBand = 0; iBand < _NumBands; iBand++)
    {
        digitalWrite(_strobePin, LOW); // Read current band (then increment to next band)
        delayMicroseconds(40);         // Wait for the outputs to settle (min 36us)

        // Start Sampling
        tmpVal = 0;
        for (uint8_t iSample = 0; iSample < _NumSamples; iSample++)
        {
            tmpVal = tmpVal + analogRead(_dataPin); // Read & Store current values from MSGEQ7
        }
        _data[iBand] = tmpVal / _NumSamples;
        // End Sampling

        digitalWrite(_strobePin, HIGH);
        delayMicroseconds(40);
    }
}

void MSGEQ7::printBands(uint8_t time)
{
    static unsigned long msLastUpdate = millis();
    if (millis() - msLastUpdate > time)
    {
        for (int band = 0; band < 7; band++)
        {
            Serial.print(get(band));
            Serial.print("\t");
        }
        Serial.println();
        msLastUpdate = millis();
    }
}

void MSGEQ7::preProcess(void)
{
    // Filter out low-level noise
    for (uint8_t iBand = 0; iBand < _NumBands; iBand++)
    {
        // Filter out low-level noise
        if (_data[iBand] < _floor)
        {
            _data[iBand] = 0;
        }
        else
        {
            _data[iBand] = map(_data[iBand], _floor, 1023, 0, 255);
        }
    }
}

uint16_t MSGEQ7::get(uint8_t band)
// Read the data from the local data array
{
	// don't read out of bounds
	if (band >= _NumBands) return 0;

	return _data[band];
}
