#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 18 - Serial clock out (SCLK)
// pin 23 - Serial data out (DIN)
// pin 19 - Data/Command select (D/C)
// pin 5 - LCD chip select (CS)
// pin 14 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(18, 23, 19, 5, 14);
// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

void drawOpenedEyes(){
  display.clearDisplay();
  display.drawRoundRect(15, 10, 20, 20, 5, BLACK);
  display.fillRoundRect(15, 10, 20, 20, 5, BLACK);
  display.drawRoundRect(50, 10, 20, 20, 5, BLACK);
  display.fillRoundRect(50, 10, 20, 20, 5, BLACK);
  display.display();
}

void drawClosedEyes(){
  display.clearDisplay();
  display.drawRoundRect(15, 20, 20, 3, 5, BLACK);
  display.fillRoundRect(15, 20, 20, 3, 5, BLACK);
  display.drawRoundRect(50, 20, 20, 3, 5, BLACK);
  display.fillRoundRect(50, 20, 20, 3, 5, BLACK);
  display.display();
}

void drawLeftEyes(){
  display.clearDisplay();
  display.drawRoundRect(8, 10, 20, 20, 5, BLACK);
  display.fillRoundRect(8, 10, 20, 20, 5, BLACK);
  display.drawRoundRect(43, 10, 20, 20, 5, BLACK);
  display.fillRoundRect(43, 10, 20, 20, 5, BLACK);
  display.display();
}

void drawFearEyes(){
  display.clearDisplay();
  display.drawRoundRect(15, 10, 20, 10, 50, BLACK);
  display.fillRoundRect(15, 10, 20, 10, 50, BLACK);
  display.drawRoundRect(50, 10, 20, 15, 50, BLACK);
  display.fillRoundRect(50, 10, 20, 15, 50, BLACK);
  display.display();
}

void blinkEyes(){
  delay(2000);
  drawClosedEyes();
  delay(1000);
  drawOpenedEyes();
}

void displaySetup(void) {
  display.begin();
  display.setContrast(60);
  display.clearDisplay();

  drawOpenedEyes();
}
