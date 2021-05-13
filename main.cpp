#include <Arduino.h>
#include "msgeq7.h"

#define DATA_PIN    34
#define RESET_PIN   27
#define STROBE_PIN  26

MSGEQ7 _MSGEQ7(RESET_PIN, STROBE_PIN, DATA_PIN);

void setup() 
{
  Serial.begin(115200);

  _MSGEQ7.begin();
}

void loop() 
{
  _MSGEQ7.read();
  _MSGEQ7.preProcess();
  _MSGEQ7.printBands(10);
}
