# ESP32 BMP280 OLED Weather Station

An ESP32-based weather monitoring station using a BMP280 sensor and SSD1306 OLED display for real-time temperature, atmospheric pressure, altitude, and weather trend monitoring with visual and audible status indicators.

---

## Overview

This project demonstrates environmental sensing and real-time monitoring using the BMP280 sensor and ESP32.

The system continuously measures:

- Temperature
- Atmospheric Pressure
- Altitude

Sensor data is displayed on an SSD1306 OLED screen and analyzed to determine pressure trends.

Visual status indicators are provided using three LEDs, while a buzzer activates when a critical temperature threshold is exceeded.

---

## Features

- Real-time temperature monitoring
- Atmospheric pressure measurement
- Altitude calculation
- Weather trend detection
- SSD1306 OLED dashboard
- Green / Orange / Blue status LEDs
- High-temperature audible alarm
- Serial monitor diagnostics
- I2C sensor communication
- ESP32 compatible

---

## Hardware Components

| Component | Quantity |
|------------|------------|
| ESP32 Development Board | 1 |
| BMP280 Pressure Sensor | 1 |
| SSD1306 OLED Display | 1 |
| Green LED | 1 |
| Orange LED | 1 |
| Blue LED | 1 |
| Passive Buzzer | 1 |
| 220Ω Resistors | 3 |
| Jumper Wires | Several |

---

## System Architecture


BMP280
   |
   v
ESP32
   |
   +---- OLED Dashboard
   |
   +---- LED Indicators
   |
   +---- Buzzer Alarm


---

## Pin Configuration

### BMP280 Sensor

| BMP280 Pin | ESP32 Pin |
|------------|------------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |
| CS | Not Connected |
| SDO | Not Connected |

---

### OLED Display

| OLED Pin | ESP32 Pin |
|------------|------------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### LEDs

| Device | GPIO |
|------------|------------|
| Green LED | GPIO15 |
| Orange LED | GPIO2 |
| Blue LED | GPIO4 |

---

### Passive Buzzer

| Device | GPIO |
|------------|------------|
| Buzzer | GPIO14 |

---

## OLED Dashboard

The OLED displays live environmental information.

Example:

```text
Temp: 27.4 C
Press:1008.3 hPa
Alt: 31.2 m

Trend: Stable
Status:NORMAL
```

---

## Weather Trend Detection

The system compares the current pressure reading with the previous reading.

### Rising Pressure

```text
Current Pressure > Previous Pressure
```

OLED:

```text
Trend: Rising
```

Often associated with improving weather conditions.

---

### Stable Pressure

```text
Pressure Difference ≈ 0
```

OLED:

```text
Trend: Stable
```

---

### Falling Pressure

```text
Current Pressure < Previous Pressure
```

OLED:

```text
Trend: Falling
```

May indicate changing weather conditions.

---

## Temperature Status Logic

### NORMAL

Condition:

```text
Temperature < 30°C
```

Actions:

```text
Green LED ON
Orange LED OFF
Blue LED OFF
Buzzer OFF
```

OLED:

```text
Status:NORMAL
```

---

### HOT

Condition:

```text
30°C ≤ Temperature < 35°C
```

Actions:

```text
Green LED OFF
Orange LED ON
Blue LED OFF
Buzzer OFF
```

OLED:

```text
Status:HOT
```

---

### ALERT

Condition:

```text
Temperature ≥ 35°C
```

Actions:

```text
Green LED OFF
Orange LED OFF
Blue LED ON
Buzzer ON
```

OLED:

```text
Status:ALERT
```

---

## How It Works

### Step 1

The BMP280 measures:

- Temperature
- Pressure

---

### Step 2

The ESP32 calculates:

```text
Altitude
```

using atmospheric pressure readings.

---

### Step 3

The current pressure is compared to the previous pressure reading.

This determines whether the trend is:

```text
Rising
Stable
Falling
```

---

### Step 4

Temperature thresholds control:

```text
LED Indicators
Buzzer Alarm
```

---

### Step 5

All information is displayed on the OLED dashboard.

---

## Serial Monitor Output

Example:

```text
Temperature: 27.4 C
Pressure: 1008.3 hPa
Altitude: 31.2 m
Trend: Stable
```

---

## Required Libraries

Install the following libraries:

### Adafruit BMP280 Library

```text
Adafruit BMP280 Library
```

### Adafruit Unified Sensor

```text
Adafruit Unified Sensor
```

### Adafruit SSD1306

```text
Adafruit SSD1306
```

### Adafruit GFX

```text
Adafruit GFX
```

---

## Installation

Clone repository:

```bash
git clone https://github.com/your-username/ESP32-BMP280-OLED-Weather-Station.git
```

Open:

```text
src/ESP32_BMP280_OLED_Weather_Station.ino
```

Compile and upload to the ESP32.

---

## Wiring Images

### Physical Wiring

```text
docs/wiring.png
```

---

### Circuit Diagram

```text
docs/circuit_diagram.png
```

---

### OLED Active State

```text
docs/oled_active.png
```

---

## Demo Video

Included in:

```text
docs/demo_video.mp4
```

Suggested demonstration:

1. System startup
2. OLED initialization
3. Live environmental readings
4. Pressure trend updates
5. Temperature increase test
6. LED state transitions
7. Buzzer activation
8. Final dashboard overview

---

## Engineering Concepts Demonstrated

- Embedded Systems Programming
- Environmental Sensing
- I2C Communication
- OLED Display Interfaces
- Sensor Data Processing
- Pressure Trend Analysis
- Altitude Estimation
- State-Based Logic
- Real-Time Monitoring
- Event-Driven Embedded Design

---

## Real-World Applications

- Portable Weather Stations
- Environmental Monitoring
- Smart Agriculture
- Greenhouse Monitoring
- Educational Laboratories
- Atmospheric Research
- IoT Sensor Nodes
- Altitude Measurement Systems

---

## Future Improvements

Potential upgrades:

- Wi-Fi Dashboard
- MQTT Integration
- Blynk Monitoring
- SD Card Logging
- RTC Time Stamping
- Historical Data Storage
- Cloud Upload
- OpenWeather API Integration
- Battery Operation
- Deep Sleep Power Saving
- Multi-Sensor Environmental Station

---

## Repository Structure

```text
ESP32-BMP280-OLED-Weather-Station
│
├── docs
│   ├── wiring.png
│   ├── circuit_diagram.png
│   ├── oled_active.png
│   └── demo_video.mp4
│
├── src
│   └── ESP32_BMP280_OLED_Weather_Station.ino
│
├── LICENSE
│
└── README.md
```

---

## Author

Milad Mohseni

Embedded Systems & IoT Engineer

Areas of Interest:

- Embedded Systems
- IoT Applications
- ESP32 Development
- Sensor Interfacing
- Firmware Engineering
- Real-Time Monitoring Systems

GitHub:

Milad-Mohseni-Eng

---

## License

This project is licensed under the MIT License.
