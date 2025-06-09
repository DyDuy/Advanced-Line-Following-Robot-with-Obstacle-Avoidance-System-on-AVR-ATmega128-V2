#ifndef HC_SR04_H_
#define HC_SR04_H_
#include <avr/io.h>
#define TRIG PE6
#define ECHO PE7
#define BUZZER PB7
void init_hc_sr04(void);
uint16_t read_distance_cm(void);
#endif 
 
