#include "stm32f4xx_hal.h"

#define COMMON_CATHODE 1
#define COMMON_ANODE 0
#define Led_Puerto GPIOA
#define Led_Pin_R GPIO_PIN_4
#define Led_Pin_G GPIO_PIN_5
#define Led_Pin_B GPIO_PIN_6

void RGBLedInt(void);
void rgb_write_value(int RedValue, int GreenValue, int BlueValue, int LedType);
void red_channel_write(int data_red, int LEDType);
void green_channel_write(int data_green, int LEDType);
void blue_channel_write(int data_blue, int LEDType);
long map_int(int valor, int entradaMin, int entradaMax, int salidaMin, int salidaMax);
