#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <Wire.h>

#include "secrets.h"

#define UPDATE_INTERVAL_MINUTES 5

LiquidCrystal_I2C lcd(0x27, 16, 2);
HTTPClient http;

void wifi_init() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting to");
  lcd.setCursor(0, 1);
  lcd.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void lcd_init() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
}

void update_data() {
  http.begin(NEKOWEB_API_URL);
  int code = http.GET();

  if (code != 200) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.printf("API RESPONSE");
    lcd.setCursor(0, 1);
    lcd.print(code);
    return;
  }

  JsonDocument doc;
  deserializeJson(doc, http.getStream());

  int views = doc["views"];
  int followers = doc["followers"];
  int updates = doc["updates"];

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.printf("Views: %d", views);
  lcd.setCursor(0, 1);
  lcd.printf("Followers: %d", followers);
}

void setup() {
  Serial.begin(115200);
  lcd_init();
  wifi_init();
}

void loop() {
  update_data();
  delay(UPDATE_INTERVAL_MINUTES * 60 * 1000);
}