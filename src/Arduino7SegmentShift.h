// Arduino7SegmentShift_v101.h

#ifndef _Arduino7SegmentShift_V101_h
#define _Arduino7SegmentShift_V101_h

#include "Arduino.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//a = 1
//b = 2
//c = 4
//d = 8
//e = 16
//f = 32
//g = 64
//h = 128
#define _DIS_A 0x01
#define _DIS_B 0x02
#define _DIS_C 0x04
#define _DIS_D 0x08
#define _DIS_E 0x10
#define _DIS_F 0x20
#define _DIS_G 0x40
#define _DIS_H 0x80

//right2left
#define _DIG_0 0xFD
#define _DIG_1 0xEF
#define _DIG_2 0xF7
#define _DIG_3 0xFB

#define _DISPLAY_C 				0xC3
#define _DISPLAY_E 				0xCB
#define _DISPLAY_L				0xC2
#define _DISPLAY_O 				0xD7
#define _DISPLAY_P 				0x8F
#define _DISPLAY_S 				0x5B
#define _DISPLAY_T				0xCA
#define _DISPLAY_DP 			0x20
#define _DISPLAY_HYPHEN 		0x08
#define _DISPLAY_BAll_UP 		0xD8
#define _DISPLAY_BAll_DOWN		0x0F
#define _DIS_LOWER_LINE 		0x40
#define _DIS_UPPER_LINE			0x01
#define _DIS_LOWER_RIGHT_VER_LINE	0x10
#define _DIS_UPPER_RIGHT_VER_LINE	0x04
#define _DIS_UPPER_LEFT_VER_LINE	0x02
#define _DIS_LOWER_LEFT_VER_LINE	0x80

#define _BAll_DIS_DELAY 			150
#define _STEP_LOADING_DELAY_TIME	20
#define _VALUE_DIS_DELAY_TIME 		10

#define _DIS_DELAY_TIME		2

class Arduino7SegmentShift
{

public:
	Arduino7SegmentShift(uint8_t _clk_pin, uint8_t _data_pin, uint8_t _latch_pin);
	~Arduino7SegmentShift();

	void init7SegDis(void);
	void displayNumeral(uint16_t _num, uint16_t _digit);
	void displayHyphen(uint16_t _digit);
	void displayChar(uint16_t _char, uint16_t _digit);
	void displayCharWithDotAndValue(uint16_t _char, uint16_t _value);
	void timeDis(uint16_t _seconds, uint16_t _minutes);
	void valueDis(uint16_t _value);
	void valueDis2(uint16_t _value);
	void ballDisplay(void);
	void loadingDisplay(void);
	void clrBallDis(void);
	void clrLoadingDis(void);
	void ballUpDis(void);
	void ballDownDis(void);
	void disOff1(void);
	void disOff2(void);
	void sendSerialData(int16_t _register_count, int16_t *_p_value_array);
	void testDis(void);
	void loopTime(uint16_t _t);

private:
	uint8_t clk_pin;
	uint8_t data_pin;
	uint8_t latch_pin;

	uint8_t segment_dis[10]; // Definitions of the 7-bit values for displaying digits
	uint8_t next_ball_dis = 0;
	uint8_t next_value_dis = 0;
	uint8_t next_time_dis = 0;

	uint8_t next_step = 0;

	int16_t register_array[2]; // Array of numbers to pass to shift registers

	uint16_t ball_dis_time = _BAll_DIS_DELAY;
	uint16_t step_loading_delay_time = _STEP_LOADING_DELAY_TIME;
	uint16_t value_dis_time = _VALUE_DIS_DELAY_TIME;

	uint16_t last_value_dis = 0;

};

#endif //_Arduino7SegmentShift_V101_h
