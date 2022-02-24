#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008, 7, 6, 5, 4, 3, 2, 1, HIGH);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);
  Serial.println("Ropivok ja");
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

}

void loop() {
  while (Serial.available() > 0) {
    byte adat = Serial.read();
    if (adat == 'r') {
      display.clearDisplay();
      display.setTextSize(1); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(40, 0);
      display.setCursor(40, 0);
      display.println(F("RED"));
      display.display();
      digitalWrite(9, HIGH);
    }
    if (adat == '0') {
      Serial.println("KI");
      digitalWrite(9, LOW);
      display.clearDisplay();
    }
    if (adat == 'g') {
      display.clearDisplay();
      display.setTextSize(1); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(40, 0);
      display.setCursor(40, 0);
      display.println(F("GREEN"));
      display.display();
      Serial.println("BE");
      digitalWrite(10, HIGH);
    }
    if (adat == '0') {
      Serial.println("KI");
      digitalWrite(10, LOW);
      display.clearDisplay();
    }
    if (adat == 'b') {
      display.clearDisplay();
      display.setTextSize(1); // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(40, 0);
      display.println(F("BLUE"));
      display.display();
      Serial.println("BE");
      digitalWrite(11, HIGH);
    }
    if (adat == '0') {
      Serial.println("KI");
      digitalWrite(11, LOW);
      display.clearDisplay();
  }
  }
}
