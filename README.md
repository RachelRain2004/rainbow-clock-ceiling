# Rainbow Clock Ceiling

### A Time-Responsive Ambient Lighting System

A creative electronics project that uses an **Arduino Uno** and a **NeoPixel RGB LED strip** to display the current time through color-coded ambient ceiling lighting — no screen, no digits, just light.

---
## Demo

| Time: 12:00 | Time: 12:01 |
|---|---|
| Hour & minute overlap → Orange | Hour → Red, Minute → Yellow |

---
## How It Works

The 60-LED NeoPixel strip is arranged around the ceiling perimeter, mimicking a clock face:

- **Red LED** → current hour position
- **Yellow LED** → current minute position
- **Orange LED** → when hour and minute overlap
- **Dim purple** → all other background LEDs

The Arduino updates the LED positions every second, simulating the passage of one minute per second (for demo purposes). The time starts at 12:00 and advances automatically.

---
## Components

| Component | Details |
|---|---|
| Arduino Uno | Microcontroller / brain of the system |
| NeoPixel LED Strip | 60 individually addressable RGB LEDs |
| Connecting Wires | For signal and power connections |
| Power Supply | Arduino's onboard 5V pin |

---
## Wiring
```
Arduino Pin 6  →  NeoPixel Data In
Arduino 5V     →  NeoPixel 5V
Arduino GND    →  NeoPixel GND
```

> For larger LED strips or higher brightness settings, use an external 5V power supply to avoid overloading the Arduino.

---
## Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Adafruit NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel)

### Installation

1. Clone this repository or download the `.ino` file
2. Open `rainbow_clock_ceiling.ino` in the Arduino IDE
3. Install the **Adafruit NeoPixel** library via **Tools → Manage Libraries**
4. Connect your hardware as described in the wiring section
5. Upload the sketch to your Arduino Uno

---
## Configuration

You can easily customize the behaviour by editing these values in the code:

```cpp
#define LED_PIN   6    // Change if using a different pin
#define NUM_LEDS  60   // Change to match your strip length

strip.setBrightness(50);  // 0 (off) to 255 (full brightness)

delay(1000);  // 1000ms = 1 simulated minute per second
              // Change to 60000 for real-time (1 min = 1 min)
```
---
## Future Scope

- Smartphone control via Bluetooth (HC-05) or Wi-Fi (ESP8266/ESP32)
- Real-time clock (RTC) module for accurate timekeeping
- Custom color themes and dynamic patterns
- Auto brightness adjustment based on ambient light
- Smart home integration with Alexa / Google Home

---
## Team

Built as a student project by:
- Gourinath K.R
- Sinta Maria Richard
- Varsha Rachel George
- Sreyas Sreekumar

---
