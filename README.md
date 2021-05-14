# ESP32-MSGEQ7-FASTLED
Code for using the MSGEQ7 ic with ESP32 and displaying it on a LED Strip using FastLED, not to be confused with the default standard stuff you find online where people create VU meters and stuff

# PARTS USED
1. **DOIT ESP32 DEVKIT V1**
2. **Sparkfun Spectrum Analyzer** board (i have 1 MSGEQ7 IC at hand but not all the caps and resistors so im using this for now)
3. **WS2812B LED Strip** (Current length is 44 Led's, waiting for new longer strips to arrive)

# MSGEQ7 STATUS
**05.13.2021** - i got it up and running with some terrible noise levels on all 7 bands ranging from 100 up to 300! so i did 2 things to sort this.

1. The first step to remove this noise is to set some sort of “floor” level. The idea here is that we assume that anything below a certain level (our “floor”) is assumed to be noise, in which case we will reset that value to 0.

2. We sample each band 5 times and average them out.

so i got it down to 0 with some minor 1's or 2's (just be increasing the **floor** it can be removed but by doing that we also lose some response time)

# FASTLED STATUS
**05.14.2021** - Added some FastLED support to show a 7 pixel "graph" of the output from the MSGEQ7 where each pixel represents a frequency.

# BAND FREQUENCY
 * Band 0 - 63Hz
 * Band 1 - 160Hz
 * Band 2 - 400Hz
 * Band 3 - 1kHz
 * Band 4 - 2.5kHz
 * Band 5 - 6.25kHz
 * Band 6 - 16kHZ