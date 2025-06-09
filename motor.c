#include "motor.h"
#include <util/delay.h>
void motor_init(void)
{
	MOTOR_DDR |= (1 << IN1) | (1 << IN2) | (1 << IN3) | (1 << IN4);
	LED_DDR |= (1 << LED_T) | (1 << LED_G) | (1 << LED_P);
	
	
}
void motor_forward(void)
{
	LED_PORT &= ~((1 << LED_T) | (1 << LED_P));
	
	
	MOTOR_PORT |= (1 << IN1);
	MOTOR_PORT &= ~(1 << IN2);
	
	
	MOTOR_PORT |= (1 << IN3);
	MOTOR_PORT &= ~(1 << IN4);

	LED_PORT |= (1 << LED_G);
}

void motor_backward(void) 
{   
	LED_PORT &=~((1<<LED_T)|(1<<LED_P));
	MOTOR_PORT |= (1 << IN2); 
	MOTOR_PORT &= ~(1 << IN1);

	MOTOR_PORT |= (1 << IN4); 
	MOTOR_PORT &= ~(1 << IN3);
	
	LED_PORT|=(1<<LED_G);
		
	
}
void motor_stop(void) 
{
	MOTOR_PORT &= ~((1 << IN1) | (1 << IN2) | (1 << IN3) | (1 << IN4));
	
	LED_PORT &=~((1<<LED_T)|(1<<LED_G)|(1<<LED_P));
}
void motor_turn_left(void)
 {	
	LED_PORT &=~((1<<LED_G)|(1<<LED_P));
	MOTOR_PORT |= (1 << IN1);
	MOTOR_PORT &= ~(1 << IN2);
	MOTOR_PORT &= ~(1 << IN3);
	MOTOR_PORT &= ~(1 << IN4);

	LED_PORT|=(1<<LED_T);
	_delay_ms(300);
	LED_PORT &=~(1<<LED_T);

	
}
void motor_turn_right(void) 
{	
	LED_PORT &=~((1<<LED_G)|(1<<LED_T));

	MOTOR_PORT |= (1 << IN3);
	MOTOR_PORT &= ~(1 << IN4);

	MOTOR_PORT &= ~(1 << IN1);
	MOTOR_PORT &= ~(1 << IN2);
	
	LED_PORT|=(1<<LED_P);
	_delay_ms(300);
	LED_PORT &=~(1<<LED_P);
	
	
}
