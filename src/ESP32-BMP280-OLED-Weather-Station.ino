/*************************************************
 * ESP32 BMP280 OLED Weather Station
 * Author: Milad Mohseni
 *
 * Features:
 * - Temperature Monitoring
 * - Pressure Monitoring
 * - Altitude Measurement
 * - Weather Trend Detection
 * - OLED Dashboard
 * - 3 LED Status Indicators
 * - High Temperature Alarm
 *************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

// =============================
// OLED CONFIGURATION
// =============================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1);

// =============================
// BMP280
// =============================

Adafruit_BMP280 bmp;

// =============================
// LED PINS
// =============================

#define GREEN_LED   15
#define ORANGE_LED   2
#define BLUE_LED     4

// =============================
// BUZZER
// =============================

#define BUZZER 14

// =============================
// VARIABLES
// =============================

float previousPressure = 0;

String trend = "Stable";

// =============================
// SETUP
// =============================

void setup()
{
  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  Wire.begin(21,22);

  if(!display.begin(
        SSD1306_SWITCHCAPVCC,
        0x3C))
  {
    while(true);
  }

  if(!bmp.begin(0x76))
  {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("BMP280 ERROR");
    display.display();

    while(true);
  }

  ledcAttach(BUZZER, 1000, 8);

  previousPressure =
      bmp.readPressure() / 100.0F;

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(15,20);
  display.println("BMP280");

  display.display();

  delay(2000);
}

// =============================
// LOOP
// =============================

void loop()
{
  // -------------------------
  // Read Sensor
  // -------------------------

  float temperature =
      bmp.readTemperature();

  float pressure =
      bmp.readPressure() / 100.0F;

  float altitude =
      bmp.readAltitude(1013.25);

  // -------------------------
  // Pressure Trend Detection
  // -------------------------

  if(pressure > previousPressure + 0.5)
  {
    trend = "Rising";
  }
  else if(pressure < previousPressure - 0.5)
  {
    trend = "Falling";
  }
  else
  {
    trend = "Stable";
  }

  previousPressure = pressure;

  // -------------------------
  // LED + Buzzer Logic
  // -------------------------

  if(temperature < 30)
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    ledcWriteTone(BUZZER, 0);
  }

  else if(temperature >= 30 &&
          temperature < 35)
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(ORANGE_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);

    ledcWriteTone(BUZZER, 0);
  }

  else
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);

    ledcWriteTone(BUZZER, 1500);
  }

  // -------------------------
  // OLED Dashboard
  // -------------------------

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(temperature,1);
  display.println(" C");

  display.print("Press:");
  display.print(pressure,1);
  display.println(" hPa");

  display.print("Alt: ");
  display.print(altitude,1);
  display.println(" m");

  display.println();

  display.print("Trend:");
  display.println(trend);

  // -------------------------
  // Status Text
  // -------------------------

  if(temperature < 30)
  {
    display.print("Status:NORMAL");
  }
  else if(temperature < 35)
  {
    display.print("Status:HOT");
  }
  else
  {
    display.print("Status:ALERT");
  }

  display.display();

  // -------------------------
  // Serial Monitor
  // -------------------------

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C   ");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.print(" hPa   ");

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.print(" m   ");

  Serial.print("Trend: ");
  Serial.println(trend);

  delay(2000);
}