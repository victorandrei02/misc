#include <FastLED.h>

#define LED_COUNT 60 // BlinkyTape has 60 LEDs!
struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB values.

#define PIN_BUTTON 10
#define PIN_IO_A   7
#define PIN_IO_B   11
#define PIN_SIGNAL 13
#define PIN_INPUT  10

unsigned int n;

unsigned int max_br = 255;

int p_rd = 0 * 256;
int p_gr = 1 * 256;
int p_bl = 2 * 256;

unsigned int red = 0;
unsigned int green = 0;
unsigned int blue = 0;

void setup() {

n = 0;

LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // this configures the BlinkyBoard - leave as is.
LEDS.showColor(CRGB(0, 0, 0)); // set the color for the strip all at once.
LEDS.setBrightness(max_br);
LEDS.show(); // you'll always need to call this function to make your changes happen.

}

void loop() {

if (n < 256) {
  red = 255 - n;
  green = n;
  blue = 0;
}
if (n >= 256 && n < 512) {
  red = 0;
  green = 511 - n;
  blue = n - 256;
}
if (n >= 512) {
  red = n - 512;
  green = 0;
  blue = 767 - n;
}

LEDS.showColor(CRGB(red, green, blue));

n++;
if (n >= 768) {
  n = 0;
}

delayMicroseconds(1);

}
