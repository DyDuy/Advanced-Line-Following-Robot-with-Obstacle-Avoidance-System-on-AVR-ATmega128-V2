#define F_CPU 7372800UL
#include "servo.h"
#include <util/delay.h>
void Servo_Init(void)
{
	DDRE |= (1 << PE3);
	TCCR3A = (1 << COM3A1) | (1 << WGM31);
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS31) | (1 << CS30);
	ICR3 = 2304; 
}
void Servo_SetAngle(uint8_t angle)
{
	if (angle > 180) angle = 180;
	OCR3A = 57 + ((uint16_t)angle * (288 - 57)) / 180;
}
