#ifndef SENSOR_H_
#define SENSOR_H_
#include <stdint.h>
typedef struct 
{
	uint8_t trai;
	uint8_t giua;
	uint8_t phai;
} CamBienLine;
void init_cam_bien_line(void);
CamBienLine doc_cam_bien_line(void);
uint8_t doc_gia_tri_line(void);
#endif /* SENSOR_H_ */
