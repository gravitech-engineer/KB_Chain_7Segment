#include <KBChain_LED7SEG.h>

// Set Display1 for LED 7Segment
KBChain_7segment Display1 = KBChain_7segment();

// Set Display2 for LED 7Segment
KBChain_7segment Display2 = KBChain_7segment();

void setup() {
  
  // Set the I2C address to 0x70 for display1
  Display1.begin(0x70);
  
  // Set the I2C address to 0x71 for display2
  Display2.begin(0x71);
  
  // Set Brightness 0-15 for display1 
  Display1.setBrightness(15);   

  // Set Brightness 0-15 for display2 
  Display2.setBrightness(15);
}

void loop() {
  
  // print All
  Display1.print(8888, DEC);
  Display2.print(8888, DEC);
  Display1.drawColon(true);
  Display2.drawColon(true);
  Display1.writeDisplay();
  Display2.writeDisplay();
  delay(1000);

  // print a hex number
  Display1.print(0xABCD, HEX);
  Display1.writeDisplay();
  Display2.print(0xABCD, HEX);
  Display2.writeDisplay();
  delay(1000);

  // print a floating point 
  Display1.print(12.34);
  Display1.writeDisplay();
  Display2.print(12.34);
  Display2.writeDisplay();
  delay(1000);

  // Show Number
  uint16_t blinkcounter = 0;
  boolean drawDots = false;
  boolean Colons = false;
  for (uint16_t counter = 0; counter < 10000; counter += 1111)
  {

    if (counter < 1111) {
      drawDots = true;
      Colons = false;
    } else if (counter < 2222) {
      drawDots = false;
      Colons = true;
    } else if (counter < 3333) {
      drawDots = true;
      Colons = false;
    } else if (counter < 4444) {
      drawDots = false;
      Colons = true;
    } else if (counter < 5555) {
      drawDots = true;
      Colons = false;
    } else if (counter < 6666) {
      drawDots = false;
      Colons = true;
    } else if (counter < 7777) {
      drawDots = true;
      Colons = false;
    } else if (counter < 8888) {
      drawDots = false;
      Colons = true;
    } else if (counter < 9999) {
      drawDots = true;
      Colons = false;

    } else {
      drawDots = false;
      Colons = true;
    }

    Display1.writeDigitNum(0, (counter / 1000), drawDots);
    Display2.writeDigitNum(0, (counter / 1000), drawDots);
    Display1.writeDigitNum(1, (counter / 100) % 10, drawDots);
    Display2.writeDigitNum(1, (counter / 100) % 10, drawDots);
    Display1.drawColon(Colons);
    Display2.drawColon(Colons);
    Display1.writeDigitNum(3, (counter / 10) % 10, drawDots);
    Display2.writeDigitNum(3, (counter / 10) % 10, drawDots);
    Display1.writeDigitNum(4, counter % 10, drawDots);
    Display2.writeDigitNum(4, counter % 10, drawDots);

    Display1.writeDisplay();
    Display2.writeDisplay();
    delay(500);
  }  

    // print with print/println
    for (uint16_t counter = 0; counter < 9999; counter++) {
    Display1.println(counter);
    Display2.println(counter);
    Display1.writeDisplay();
    Display2.writeDisplay();
    delay(10);
  }  
} 
