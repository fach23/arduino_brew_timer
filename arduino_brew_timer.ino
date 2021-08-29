#include "timer.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pictures.h"

// Display instance (OLED Display I2C 0.96 LCD 128X64 SSD1306)
#define SCREEN_WIDTH 128  // display width, in pixels
#define SCREEN_HEIGHT 64  // display height, in pixels
#define SCREEN_RESET 4    // reset pin
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_RESET);

// Digital Input Signal (1-Bit AC 220V Optokoppler Isolation Modul)
#define BREWING_SIGNAL 2

// Timer instance
BrewTimer::Timer timer;

// Function which draws time on display.
void drawTime(BrewTimer::Timer & timer) 
{  
  display.clearDisplay();

  const unsigned long time = timer.elapsedTime();

  if (time < 10000) {
    display.setCursor(47, 13); 
  }
  else {
    display.setCursor(28, 13);           
  }

  display.println(time / 1000);
  display.display();
}

// Function which draws a screen saver on display.
void drawScreenSaver() 
{
  display.clearDisplay();
  display.drawBitmap(0, 0, tired_smilie, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();  
}

// Function which draws a coffe cup on display.
void drawCoffeeCup() 
{
  display.clearDisplay();
  display.drawBitmap(0, 0, coffee_cup, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();  
}

// Arduino Setup Function
void setup()
{ 
  // prepare input
  pinMode(BREWING_SIGNAL, INPUT);
  
  // prepare display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.setTextSize(6);
  drawScreenSaver();
}

// Arduino Loop Function
void loop()
{ 
  // read input signal
  bool brewing = digitalRead(BREWING_SIGNAL) == LOW;
  
  // brew timer logic
  if (brewing)
  {
    if (!timer.active())
    {
      timer.start();   
    }

    timer.update();
    
    drawTime(timer);
  }
  else
  {
    if (timer.active())
    {
      if (timer.elapsedTime() > 10000)
      {
        delay(1000);
        drawCoffeeCup();
        delay(5000);
      }
      
      timer.stop();
    }
    else 
    {
      drawScreenSaver();
    }
  }  
}
