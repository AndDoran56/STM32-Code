#include "stm32f4xx_hal.h"

#define v_min 5
#define v_max 25
#define servo_1 GPIO_PIN_6
#define use_servo_1

void ServoInt(void);
long map_int(int16_t x, int16_t eMin, int16_t eMax, int16_t sMin, int16_t sMax);
void servo_1_write(int16_t angle1);
void servo_2_write(int16_t angle1);
void servo_3_write(int16_t angle1);
void servo_4_write(int16_t angle1);
void servo_5_write(int16_t angle1);

