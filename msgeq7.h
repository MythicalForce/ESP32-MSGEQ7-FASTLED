#ifndef MSGEQ7H
#define MSGEQ7H

#include <Arduino.h>

/**
 * Band frequencies
 * 
 * Band 0 - 63Hz
 * Band 1 - 160Hz
 * Band 2 - 400Hz
 * Band 3 - 1kHz
 * Band 4 - 2.5kHz
 * Band 5 - 6.25kHz
 * Band 6 - 16kHZ
 */

/**
 *
 * @param ResetPin
 * @param StrobePin
 * @param LeftAudio
 * 
 */
class MSGEQ7
{
public:

    MSGEQ7(uint8_t resetPin, uint8_t strobePin, uint8_t dataPin): _NumBands(7), _NumSamples(5), _resetPin(resetPin), _strobePin(strobePin), _dataPin(dataPin), _floor(200) {};

    ~MSGEQ7(void) {};

    void begin(void);
    void reset(void);
    void read(void);
    void printBands(uint8_t time);
    void preProcess(void);
    uint16_t get(uint8_t band);

private:
    uint8_t _NumBands;
    uint8_t _NumSamples;
	uint8_t _resetPin;
	uint8_t _strobePin;
	uint8_t _dataPin;
    uint16_t _floor;

	uint16_t _data[7];
};

#endif
