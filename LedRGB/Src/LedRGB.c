#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "LedRGB.h"
#include<stdbool.h>

long contador = 0;
long red, green, blue;

void RGBLedInt(void){

contador = contador + 5;
   if(contador > 256){
       contador = 0;
       }
   if(contador < red){
HAL_GPIO_WritePin(Led_Puerto, Led_Pin_R, SET);
   }
   else {
       HAL_GPIO_WritePin(Led_Puerto, Led_Pin_R, RESET);
   }
   if(contador < green){
HAL_GPIO_WritePin(Led_Puerto, Led_Pin_G, SET);
   }
   else {
       HAL_GPIO_WritePin(Led_Puerto, Led_Pin_G, RESET);
   }

   if(contador < blue){
HAL_GPIO_WritePin(Led_Puerto, Led_Pin_B, SET);
   }
   else {
       HAL_GPIO_WritePin(Led_Puerto, Led_Pin_B, RESET);
   }
}

long map_int(int valor, int entradaMin, int entradaMax, int salidaMin, int salidaMax){
   return((((valor-entradaMin)*(salidaMax-salidaMin))/(entradaMax-entradaMin))+salidaMin);
}

void rgb_write_value(int RedValue, int GreenValue, int BlueValue, int LedType){
	int A_LedRed,A_LedGreen,A_LedBlue;
	int C_LedRed,C_LedGreen,C_LedBlue;
     switch(LedType)
   {
      case 0:
      A_LedRed = map_int(RedValue, 0, 255, 255, 0);                // Conversion del valor red
      A_LedGreen = map_int(GreenValue, 0, 255, 255, 0);                // Conversion del valor green
      A_LedBlue = map_int(BlueValue, 0, 255, 255, 0);                // Conversion del valor blue
      if(A_LedRed > 254){
         red = 256;
      }else{
         red = A_LedRed;
      }
      if(A_LedGreen > 254){
         green = 256;
      }else{
         green = A_LedGreen;
      }
      if(A_LedBlue > 254){
         blue = 256;
      }else{
         blue = A_LedBlue;
      }
      break;
      
      case 1:
      C_LedRed = map_int(RedValue, 0, 255, 0, 255);                // Conversion del valor red
      C_LedGreen = map_int(GreenValue, 0, 255, 0, 255);                // Conversion del valor green
      C_LedBlue = map_int(BlueValue, 0, 255, 0, 255);                // Conversion del valor blue
      red = C_LedRed;
      green = C_LedGreen;
      blue = C_LedBlue;
      break;
   }
}

void red_channel_write(int data_red, int LEDType)
{
	int A_red,C_red;

   switch(LEDType)
   {
      case 0:
      A_red = map_int(data_red, 0, 255, 255, 0);                    // Conversion del valor red
      if(A_red > 254){
         red = 256;
      }else{
         red = A_red;
      }
      break;

      case 1:
      C_red = map_int(data_red, 0, 255, 0, 255);                    // Conversion del valor red
      red = C_red;
      break;
   }
}

void green_channel_write(int data_green, int LEDType)
{
	int C_green,A_green;
   switch(LEDType)
   {
      case 0:
      A_green = map_int(data_green, 0, 255, 255, 0);                // Conversion del valor green
      if(A_green > 254){
         green = 256;
      }
      else{
         green = A_green;
      }
      break;

      case 1:
      C_green = map_int(data_green, 0, 255, 0, 255);                // Conversion del valor green
      green = C_green;
      break;
   }
}

void blue_channel_write(int data_blue, int LEDType)
{
	int C_blue,A_blue;
   switch(LEDType)
   {
      case 0:
      A_blue = map_int(data_blue, 0, 255, 255, 0);                  // Conversion del valor blue
      if(A_blue > 254){
         blue = 256;
      }
      else{
         blue = A_blue;
      }
      break;

      case 1:
      C_blue = map_int(data_blue, 0, 255, 0, 255);                  // Conversion del valor blue
      blue = C_blue;
      break;
   }
}

