#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "led.h"
#include "stdio.h"
#include "stdbool.h"


//Variables
int mLcdPuertos[NUM_PUERTOS]={0};
bool mDatosPuertos[NUM_PUERTOS]={0};

//Inicializacion

void puertos(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};


  __HAL_RCC_GPIOD_CLK_ENABLE();

GPIO_InitStruct.Pin = GPIO_PIN_4;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

GPIO_InitStruct.Pin = GPIO_PIN_5;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

GPIO_InitStruct.Pin = GPIO_PIN_6;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

GPIO_InitStruct.Pin = GPIO_PIN_7;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

void inicializacion(){


	mLcdPuertos[0] = D4;
	mLcdPuertos[1] = D5;
	mLcdPuertos[2] = D6;
	mLcdPuertos[3] = D7;

	GPIO_InitTypeDef GPIO_InitStruct = {0};


  __HAL_RCC_GPIOD_CLK_ENABLE();


  GPIO_InitStruct.Pin = RS;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RW;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = E;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  puertos();

  HAL_GPIO_WritePin(GPIOD, RS, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, RW, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, D4, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, D5, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, D6, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, D7, GPIO_PIN_RESET);

  comando(0x02);
  HAL_Delay(1);
  comando(0x28);
  HAL_Delay(1);
  comando(0x14);
  HAL_Delay(1);
  comando(0x0C);
  HAL_Delay(1);
  comando(0x01);
  HAL_Delay(1);

}

//comando

void comando(int codigo){

	HAL_GPIO_WritePin(GPIOD, RS, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, RW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);

	puertos();

	for(int iteraciones = 0; iteraciones <2; iteraciones++){

		for(int indx = 0;indx < NUM_PUERTOS; indx++){


			mDatosPuertos[indx] =  ((codigo & 0x80) == 0x80) ? SET : RESET;
			HAL_GPIO_WritePin(GPIOD, mLcdPuertos[NUM_PUERTOS -1 - indx], mDatosPuertos[indx]);
			codigo<<=1;
		}

		habilitarComando();

	}

}

void habilitarComando(){

	HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_SET);
	HAL_Delay(TIEMPO_EN);
	HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);
	HAL_Delay(TIEMPO_EN);
}

void establecerDireccion(int dir){

	dir = dir | 0x80;
	HAL_GPIO_WritePin(GPIOD, RS, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, RW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);

	puertos();


	for(int iteraciones = 0; iteraciones <2; iteraciones++){

		for(int indx = 0;indx < NUM_PUERTOS; indx++){


			HAL_GPIO_WritePin(GPIOD, mLcdPuertos[NUM_PUERTOS - 1 - indx], ((dir & 0x80) == 0x80)? SET : RESET);
			dir<<=1;
		}

		habilitarComando();

	}

}

void escribirLCD(char caracter){

	HAL_GPIO_WritePin(GPIOD, RS, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, RW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);

	puertos();

	for(int iteraciones = 0; iteraciones <2; iteraciones++){

			for(int indx = 0;indx < NUM_PUERTOS; indx++){


			HAL_GPIO_WritePin(GPIOD, mLcdPuertos[NUM_PUERTOS - 1 - indx], ((caracter & 0x80) == 0x80)? SET : RESET);
				caracter<<=1;
			}

			habilitarComando();

		}


}

void escribirLCD2(char* cadena){

	HAL_GPIO_WritePin(GPIOD, RS, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, RW, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);

		puertos();

		char caracter = 0;

		for(int indxTxt = 0;cadena[indxTxt] != '\0';indxTxt++){

			caracter = cadena[indxTxt];

			for(int iteraciones = 0; iteraciones <2; iteraciones++){

						for(int indx = 0;indx < NUM_PUERTOS; indx++){


						HAL_GPIO_WritePin(GPIOD, mLcdPuertos[NUM_PUERTOS - 1 - indx], ((caracter & 0x80) == 0x80)? SET : RESET);
							caracter<<=1;
						}

						habilitarComando();

					}


}

}

void clear(){

	HAL_GPIO_WritePin(GPIOD, RS, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, RW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, E, GPIO_PIN_RESET);

	for(int i = 0; i <2; i++){

		if(i == 0){

			GPIOD->ODR &= ~0x00F0;

		}

		if(i == 1){

			GPIOD->ODR |= 0x0010;


				}

		habilitarComando();


	}
}












