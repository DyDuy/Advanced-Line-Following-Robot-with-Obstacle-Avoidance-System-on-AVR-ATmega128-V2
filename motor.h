#ifndef MOTOR_H_
#define MOTOR_H_
#include <avr/io.h>
#define MOTOR_DDR  DDRA
#define MOTOR_PORT PORTA
#define IN1 PA1  
#define IN2 PA2   
#define IN3 PA3  
#define IN4 PA4   
#define LED_T PC0
#define LED_G PC1
#define LED_P PC2
#define LED_DDR DDRC
#define LED_PORT PORTC
void motor_init(void);
void motor_forward(void);     
void motor_backward(void);     
void motor_stop(void);         
void motor_turn_left(void);    
void motor_turn_right(void);   
#endif
