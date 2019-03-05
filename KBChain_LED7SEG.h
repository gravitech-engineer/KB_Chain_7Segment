/****************************************************** 
  This is a library for KBChain_LED7SEG
  Selectable I2C addresses 0x70, 0x71 For 7Segment
  1. ADDR Not jump I2C addresses 0x70
  2. ADDR jump I2C addresses 0x71

 *******************************************************/
#include <Wire.h>

#ifndef KBChain_LED7SEG_h
#define KBChain_LED7SEG_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_BLINK_2HZ  1
#define HT16K33_BLINK_1HZ  2
#define HT16K33_BLINK_HALFHZ  3
#define HT16K33_CMD_BRIGHTNESS 0xE0

#define SEVENSEG_DIGITS 5

#define BYTE 0
#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

// HT16K33 controller
class KBChain_LED7SEG {
 public:
  KBChain_LED7SEG(void);
  void begin(uint8_t _addr);
  void setBrightness(uint8_t b);
  void blinkRate(uint8_t b);
  void writeDisplay(void);
  void clear(void);

  uint16_t displaybuffer[8]; 

  void init(uint8_t a);
 protected:
  uint8_t i2c_addr;
};

// LED 7 Segment
class KBChain_7segment : public KBChain_LED7SEG {
 public:
  KBChain_7segment(void);
  size_t write(uint8_t c);

  void print(char, int = BYTE);
  void print(unsigned char, int = BYTE);
  void print(int, int = DEC);
  void print(unsigned int, int = DEC);
  void print(long, int = DEC);
  void print(unsigned long, int = DEC);
  void print(double, int = 2);
  void println(char, int = BYTE);
  void println(unsigned char, int = BYTE);
  void println(int, int = DEC);
  void println(unsigned int, int = DEC);
  void println(long, int = DEC);
  void println(unsigned long, int = DEC);
  void println(double, int = 2);
  void println(void);
  
  void writeDigitRaw(uint8_t x, uint8_t bitmask);
  void writeDigitNum(uint8_t x, uint8_t num, boolean dot = false);
  void drawColon(boolean state);
  void drawL3(boolean state);
  void printNumber(long, uint8_t = 2);
  void printFloat(double, uint8_t = 2, uint8_t = DEC);
  void printError(void);

  void writeColon(void);
    
 private:
  uint8_t position;
};
#endif // KBChain_LED7SEG

