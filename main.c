#define F_CPU 16000000UL
#include "motor.h"
#include "sensor.h"
#include "servo.h"
#include "hc_sr04.h"
#include <util/delay.h>

#define set_dis  12

uint16_t distance_L, distance_R;
uint16_t distance_F;
uint8_t line;
int huong_truoc_do = 0;

void check_dis();
void check_side();
void loop();
uint16_t doc_khoang_cach(uint8_t goc) 
{
	Servo_SetAngle(goc);      
	_delay_ms(250);           
	return read_distance_cm(); 
}
void check_dis() 
{
	
	if ((distance_L >= distance_R)|| (distance_L < set_dis) && (distance_R < set_dis))
	{
		motor_backward(); _delay_ms(100);
		motor_turn_left(); _delay_ms(500);
		motor_forward(); _delay_ms(500);
		motor_turn_right(); _delay_ms(300);
		motor_forward(); _delay_ms(600);
		motor_turn_right(); _delay_ms(400);
	} 
	else if(distance_L<distance_R)
	{   
		motor_backward(); _delay_ms(100);
		motor_turn_right(); _delay_ms(500);
		motor_forward(); _delay_ms(600);
		motor_turn_left(); _delay_ms(500);
		motor_forward(); _delay_ms(600);
		motor_turn_left(); _delay_ms(400);
	}
}

void check_side() 
{
	motor_stop();
    PORTB |= (1 << PB6); _delay_ms(300);
	
	distance_L = doc_khoang_cach(150);

	Servo_SetAngle(100); _delay_ms(300);

	
	distance_R = doc_khoang_cach(50);

	Servo_SetAngle(100); _delay_ms(300);
    PORTB &= ~(1 <<PB6); _delay_ms(300);
	check_dis();
}

void loop() 
{
	if (line == 0b010) 
	{
		motor_forward();
		huong_truoc_do = 0;
		if (distance_F < set_dis) 
		{check_side();}
	}
	else if (line == 0b111 || line == 0b110 || line == 0b100 || line == 0b101) {motor_turn_left(); huong_truoc_do = 1;}
	else if (line == 0b011 || line == 0b001) {motor_turn_right(); huong_truoc_do = 2;}
	else if (line == 0b000) 
	{
	if (huong_truoc_do == 1) {motor_turn_left();} else if (huong_truoc_do == 2) {motor_turn_right();} else if(huong_truoc_do==0) { motor_backward();}else{ motor_stop();}
	}
}

int main(void) 
{
	motor_init();
	init_cam_bien_line();
	init_hc_sr04();
	Servo_Init();
	motor_stop();
	_delay_ms(2000);

	Servo_SetAngle(100); _delay_ms(300);

	while (1) 
	{   
		line = doc_gia_tri_line();
		distance_F = read_distance_cm();
		loop();
		_delay_ms(50);
	}
}
