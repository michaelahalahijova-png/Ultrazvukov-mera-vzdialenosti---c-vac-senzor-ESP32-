#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Ultrazvukové piny
#define TRIG_PIN 13
#define ECHO_PIN 12

// LED indikácia
#define LED_PIN 2

// I2C piny
#define SDA_PIN 14
#define SCL_PIN 15

void setup() {
   Serial.begin(115200);

   pinMode(TRIG_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);

   pinMode(LED_PIN, OUTPUT);
   digitalWrite(LED_PIN, LOW);


   Wire.begin(SDA_PIN, SCL_PIN);

   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
     Serial.println("OLED sa nespustil!");
     while (true);
   }

   display.clearDisplay();
   display.setTextSize(2);
   display.setTextColor(SSD1306_WHITE);
   display.setCursor(0, 0);
   display.println("Spustam...");
   display.display();
   delay(1000);
}

float getDistance() {
   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(2);

   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);

   long duration = pulseIn(ECHO_PIN, HIGH, 30000);
   return duration * 0.0343 / 2;
}

void loop() {
   float distance = getDistance();

   display.clearDisplay();
   display.setTextSize(2);
   display.setCursor(0, 0);

   if (distance <= 0 || distance > 400) {
     display.println("Mimo");
     display.println("rozsah");
     digitalWrite(LED_PIN, LOW);
   } else {
     display.print(distance, 1);
     display.println(" cm");

     if (distance <= 10) {
       digitalWrite(LED_PIN, HIGH);
     } else {
       digitalWrite(LED_PIN, LOW);
     }
   }

   display.display();
   delay(200);
}
