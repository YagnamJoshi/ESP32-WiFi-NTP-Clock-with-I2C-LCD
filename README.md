# ⏰ ESP32 WiFi NTP Clock with I2C LCD

A simple digital clock using an ESP32, which fetches real-time data from NTP servers over WiFi and displays it on a 16x2 I2C LCD.

---

## 📌 Features

* 🌐 Syncs time using NTP (Network Time Protocol)
* 📶 Connects to WiFi automatically
* 🕒 Displays real-time clock (HH:MM:SS)
* 📅 Shows date (DD/MM/YYYY)
* 🇮🇳 Configured for Indian Standard Time (IST)
* 📟 Output on 16x2 I2C LCD
* 🖥️ Debug output via Serial Monitor

---

## 🧰 Hardware Required

* ESP32 Development Board
* 16x2 I2C LCD Display (address usually `0x27` or `0x3F`)
* Jumper wires

---

## 🔌 Wiring (ESP32 ↔ LCD)

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO 21   |
| SCL     | GPIO 22   |

---

## 📦 Libraries Used

Install the following libraries via Arduino IDE:

* `WiFi.h` (built-in for ESP32)
* `time.h` (built-in)
* `Wire.h` (built-in)
* `LiquidCrystal_I2C`

---

## ⚙️ Configuration

Update your WiFi credentials in the code:

```cpp
const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";
```

---

## 🌍 Time Configuration

The project uses NTP servers:

```cpp
const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
```

Time zone is set for India:

```cpp
const char *time_zone = "IST-5:30";
```

---

## ▶️ How It Works

1. ESP32 connects to WiFi
2. Fetches current time from NTP servers
3. Converts time to IST
4. Displays:

   * Line 1 → Time (HH:MM:SS)
   * Line 2 → Date (DD/MM/YYYY)
5. Updates every second

---

## 🖥️ Example Output

**LCD Display:**

```
12:45:08
04/05/2026
```

**Serial Monitor:**

```
Monday, 04 May 2026 12:45:08
```

---

## ⚠️ Troubleshooting

### LCD not displaying anything

* Try changing I2C address:

```cpp
LiquidCrystal_I2C lcd(0x3F, 16, 2);
```

### WiFi not connecting

* Double-check SSID and password
* Ensure 2.4GHz network (ESP32 doesn't support 5GHz)

### Time not updating

* Check internet connectivity
* Wait a few seconds after boot for sync

---

## 🚀 Future Improvements

* ⏰ Add alarm functionality
* 🌐 Auto timezone detection
* 📊 Add temperature/humidity sensor
* 🎨 Upgrade to OLED display UI
* 🔋 Battery backup with RTC module (DS3231)

---

## 📄 License

This project is open-source and free to use.

---

## 🙌 Credits

* ESP32 Arduino Core
* NTP servers: `pool.ntp.org`, `time.nist.gov`

---

## ⭐ If you like this project

Give it a star ⭐ and share it!

---
