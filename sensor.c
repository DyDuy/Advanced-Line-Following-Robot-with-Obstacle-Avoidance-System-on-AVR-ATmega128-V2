#include "sensor.h"
#include <avr/io.h>
void init_cam_bien_line(void)
{
	DDRF &= ~((1 << PF2) | (1 << PF1) | (1 << PF0));
	PORTF |= (1 << PF2) | (1 << PF1) | (1 << PF0);
}

CamBienLine doc_cam_bien_line(void)
{
	CamBienLine cb;

	cb.trai = (PINF & (1 << PF2)) ? 1 : 0;
	cb.giua = (PINF & (1 << PF1)) ? 1 : 0;
	cb.phai = (PINF & (1 << PF0)) ? 1 : 0;

	return cb;
}
uint8_t doc_gia_tri_line(void)
{
	CamBienLine cb = doc_cam_bien_line();
	return (cb.trai << 2) | (cb.giua << 1) | cb.phai;
}
