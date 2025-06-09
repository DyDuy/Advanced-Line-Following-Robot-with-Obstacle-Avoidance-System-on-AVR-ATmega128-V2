#include "hc_sr04.h"
#include <util/delay.h>
#include <avr/io.h>
void init_hc_sr04(void) 
{
	DDRE |= (1 << TRIG);    
	DDRE &= ~(1 << ECHO);  
	DDRB |= (1 <<PB6); 
}
uint16_t read_distance_cm(void) 
{
	uint16_t count = 0;
	PORTE &= ~(1 << TRIG);
	_delay_us(2);
	PORTE |= (1 << TRIG);
	_delay_us(10);
	PORTE &= ~(1 << TRIG);
	while (!(PINE & (1 << ECHO)));
	while (PINE & (1 << ECHO)) 
	{
		_delay_us(1);
		count++;
		if (count > 3000) break; 
	}
	return count / 58;
}

