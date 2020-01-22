// Using Ardiono IDE Select Board: WeMos board 

#include <Arduino.h>
#include <EasyButton.h>      
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>


#define BUTTON_UP 12
#define BUTTON_PRESS 14
#define BUTTON_DOWN 13
#define BUTTON_LEFT 0

int analogPin = A0;               
int analogValue = 0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

EasyButton ButtonUP(BUTTON_UP);
EasyButton ButtonPRESS(BUTTON_PRESS);
EasyButton ButtonDOWN(BUTTON_DOWN);
EasyButton ButtonLEFT(BUTTON_LEFT);

void initMyDisplay() {
  
  // Start I2C Communication SDA = 5 and SCL = 4 on Wemos Lolin with built-in SSD1306 OLED
  Wire.begin(5, 4);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation error"));
    for(;;);
  }
  delay(2000);
  display.setFont(&FreeSans9pt7b);
  display.setTextSize(1);             
  display.setTextColor(WHITE);       
}

void pressedButtonUP() {
  display.clearDisplay();
  display.setCursor(0,22);
  display.printf("UP");
  display.display();
}
void pressedButtonPRESS() {
  display.clearDisplay();
  display.setCursor(0,22);  
  display.printf("IN");
  display.display();
}
void pressedButtonDOWN() {
  display.clearDisplay();
  display.setCursor(0,22);
  display.println("DOWN");
  display.display();
}

void pressedButtonLEFT() {
  display.clearDisplay();
  display.setCursor(0,22);
  display.println("LEFT");
  display.display();
}

void setup() {
  
  ButtonUP.begin();
  ButtonLEFT.begin();
  ButtonDOWN.begin();
  ButtonPRESS.begin();
  
  Serial.begin(9600);  
  delay(10);

  initMyDisplay();
  
  display.clearDisplay();
  display.setCursor(0,20);
  display.print("READY");
  display.display();
  delay(1000);
 
  ButtonUP.onPressed(pressedButtonUP);
  ButtonPRESS.onPressed(pressedButtonPRESS);
  ButtonDOWN.onPressed(pressedButtonDOWN);
  ButtonLEFT.onPressed(pressedButtonLEFT);
}

void loop() { 
  ButtonUP.read();
  ButtonPRESS.read();
  ButtonDOWN.read();
  ButtonLEFT.read();  
}
