// I updated the WS2812 library and found a more
// detailed more effects 
// Thank you kitesurfer1404 for he libray and base code
// This is all his work ouside of some small details
// Change up to Rainbow alternation with fade on pin 9 for string of pico LEDS


int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

#include <WS2812FX.h>

#define LED_COUNT 30
#define LED_PIN 6

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  ws2812fx.init();
  ws2812fx.setBrightness(200);
  ws2812fx.setSpeed(200);
  ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
  ws2812fx.start();
}

void loop() {
  ws2812fx.service();
   // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 50 milliseconds to see the dimming effect
  delay(50);
}
