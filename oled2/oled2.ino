
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  
  for (int i = 0; i < 3; i++);
   display.clearDisplay();
  display.println(F("Ropivok ja"));
  display.display(); 
      display.clearDisplay();
       display.setCursor(10, 0);   
  delay(1000);
  display.println(F("*******"));
  display.display();  
   display.clearDisplay(); 
    display.setCursor(10, 0);    
  delay(1000);
  display.clearDisplay();
  display.println(F("Ropivok ja"));
    display.display();  
     display.clearDisplay(); 
      display.setCursor(10, 0);    
  delay(1000);
  display.clearDisplay();
   display.println(F("**********"));
    display.display();  
     display.clearDisplay(); 
      display.setCursor(10, 0);    
  delay(1000);
  display.clearDisplay();
   display.println(F("Ropivok ja"));
    display.display(); 
     display.clearDisplay(); 
      display.setCursor(10, 0);     
  delay(1000);
  display.clearDisplay(); display.println(F("********"));
    display.display();  
     display.clearDisplay(); 
      display.setCursor(10, 0);    
  delay(1000);
  display.clearDisplay();
   display.println(F("Ropivok ja"));
    display.display();  
     display.clearDisplay();  
     display.setCursor(10, 0);   
  delay(1000);
  display.clearDisplay();
   display.clearDisplay(); display.println(F("********"));
    display.display();   
     display.clearDisplay();
         display.setCursor(10, 0);  
  delay(1000);
 
}

void loop() {
  
 kiir("CIGU");
 
}



void kiir (String text) {
display.clearDisplay();
display.setCursor(0, 0);
display.print(text);
display.display();

}
