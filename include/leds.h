#include <Arduino.h>
#include <FastLED.h>

#define MAX_LED   44
#define LED_PIN   23
#define CHIPSET   WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  128

CRGB leds[MAX_LED];

static uint8_t bandHue[7] = { HUE_PURPLE, HUE_PINK, HUE_RED, HUE_YELLOW, HUE_GREEN, HUE_AQUA, HUE_BLUE };

namespace _LED
{
    void begin()
    {
        FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, MAX_LED).setCorrection(TypicalLEDStrip);
        FastLED.setBrightness(BRIGHTNESS);

        FastLED.setDither(0);
        FastLED.show();
    }
}