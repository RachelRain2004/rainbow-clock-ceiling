#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define NUM_LEDS 60

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Start time (12:00)
int current_hour = 0;
int current_minute = 0;

void setup() {
  strip.begin();
  strip.setBrightness(50); // Adjust brightness (0-255)
  strip.show();            // Initialize all LEDs to off
}

void loop() {
  // Minute hand: directly maps to LED index (0-59)
  int minute_led = current_minute;

  // Hour hand: maps 12 hours to 60 LEDs (5 LEDs per hour)
  int hour_led = (current_hour % 12) * 5;

  for (int i = 0; i < NUM_LEDS; i++) {
    if (i == hour_led && i == minute_led) {
      // Overlap: both hands on same LED → orange
      strip.setPixelColor(i, strip.Color(255, 128, 0));
    }
    else if (i == hour_led) {
      // Hour hand → red
      strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
    else if (i == minute_led) {
      // Minute hand → yellow
      strip.setPixelColor(i, strip.Color(255, 255, 0));
    }
    else {
      // Background → dim purple
      strip.setPixelColor(i, strip.Color(20, 0, 10));
    }
  }

  strip.show();

  // Advance simulated time
  current_minute++;
  if (current_minute >= 60) {
    current_minute = 0;
    current_hour = (current_hour + 1) % 24;
  }

  delay(1000); // 1 second = 1 simulated minute
}
