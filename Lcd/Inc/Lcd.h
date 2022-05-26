#include "stm32f4xx_hal.h"

//Macros

#define TIEMPO_EN (int)1
#define NUM_PUERTOS (int)4

#define RS      GPIO_PIN_0
#define RW 		GPIO_PIN_1
#define E 		GPIO_PIN_2

#define D4 		GPIO_PIN_4
#define D5		GPIO_PIN_5
#define D6 		GPIO_PIN_6
#define D7		GPIO_PIN_7


//Prototipos

void inicializacion();
void comando(int codigo);
void habilitarComando();
void escribirLCD(char caracter);
void escribirLCD2(char* cadena);
void puertos();
void clear();
void establecerDireccion(int dir);

