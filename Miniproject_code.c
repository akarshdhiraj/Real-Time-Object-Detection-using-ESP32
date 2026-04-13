#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 #define 
OLED_I2C_ADDRESS 0x3C#define
OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int trigPin = 5;
const int echoPin=18;void setup()
{
 Serial.begin(115200);
 if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS))
{
Serial.println(F("SSD1306 allocation failed"));
for (;;);
}
display.clearDisplay();
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 10);
display.println(F("HC-SR04 Ultrasonic Sensor"));
display.display();
delay(2000);
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
long duration = pulseIn(echoPin, HIGH);
float distance = duration * 0.034 / 2;
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 10);
display.print("Distance: ");
display.print(distance);
display.println(" cm");
display.display();
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
delay(1000);
}
