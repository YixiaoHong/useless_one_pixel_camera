#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

const int buttonPin = 8;     // the number of the pushbutton pin
const int greenLedPin =  13;      // the number of the LED pin
const int redLedPin =  12;      // the number of the LED pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(27,30);
  display.print("Hello, world!");

  // update display with all of the above graphics
  display.display();
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  display.clearDisplay();
  display.display();
  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);

  // display a line of text
  display.setTextSize(2.0);
  display.setTextColor(WHITE);
  display.setCursor(10,10);
  double readV = sensorValue*5.0/1024.0;
  double res = (50.0/readV-10.0)*1000.0;
  String str_v = String(readV);
  String str_res = String(res);
  display.print(str_res  + "\n   Ohm\n " + str_v  + " V");

  // update display with all of the above graphics
  display.display();
  delay(200);
}
