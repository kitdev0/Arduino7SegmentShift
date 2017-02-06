#include "Arduino7SegmentShift.h"

//Define your 7 Segment hardware pin
#define _PIN_SEGMENT_CLK    6
#define _PIN_SEGMENT_DATA	  5
#define _PIN_SEGMENT_LATCH	4

//Creat object
ARDUINO_7SEGMENT_SHIFT display(_PIN_SEGMENT_CLK, _PIN_SEGMENT_DATA, _PIN_SEGMENT_LATCH);

void setup()
{
  //Need to initial
  display.init7SegDis();

  //Set to off display
  display.disOff1();

  //Loading Display
  display.displayHyphen(_DIG_3);
  delay(300);
  display.displayHyphen(_DIG_3 & _DIG_2);
  delay(300);
  display.displayHyphen(_DIG_3 & _DIG_2 & _DIG_1);
  delay(300);
  display.displayHyphen(_DIG_3 & _DIG_2 & _DIG_1 & _DIG_0);
  delay(300);
}

void loop()
{
  display.valueDis(1234);
}
