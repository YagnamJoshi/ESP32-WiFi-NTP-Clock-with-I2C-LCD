#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char *ssid = "ID";
const char *password = "password";

const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";

// India Time Zone (IST)
const char *time_zone = "IST-5:30";

void printLocalTime() {
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time Error");
    return;
  }

  // Serial full info
  Serial.println(&timeinfo, "%A, %d %B %Y %H:%M:%S");

  // LCD display (SHORT format)
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(&timeinfo, "%H:%M:%S");   // Time

  lcd.setCursor(0, 1);
  lcd.print(&timeinfo, "%d/%m/%Y");   // Date
}

void setup() {
  Serial.begin(115200);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");

  // Set timezone + NTP
  configTzTime(time_zone, ntpServer1, ntpServer2);

  delay(2000);
}

void loop() {
  printLocalTime();
  delay(1000);
}
