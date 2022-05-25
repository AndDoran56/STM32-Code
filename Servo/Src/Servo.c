#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "Servo.h"

uint16_t cont_st = 0;
uint16_t pwm_st[5];

void ServoInt(void){

cont_st++;
	   if(cont_st > 200)
		  {
		     cont_st = 0;
		   }
            #ifdef use_servo_1
            if(cont_st < pwm_st[0]){
			   HAL_GPIO_WritePin(GPIOA, servo_1, SET);
		   }
		   else{
                HAL_GPIO_WritePin(GPIOA, servo_1, RESET);
                }
            #endif
            #ifdef use_servo_2
            if(cont_st < pwm_st[1]){
			   HAL_GPIO_WritePin(GPIOA, servo_2, SET);
		   }
		   else{
                HAL_GPIO_WritePin(GPIOA, servo_2, RESET);
                }
            #endif
            #ifdef use_servo_3
                if(cont_st < pwm_st[2]){
			   HAL_GPIO_WritePin(GPIOA, servo_3, SET);
		   }
		   else{
                HAL_GPIO_WritePin(GPIOA, servo_3, RESET);
                }
            #endif
            #ifdef use_servo_4
                if(cont_st < pwm_st[3]){
			   HAL_GPIO_WritePin(GPIOA, servo_4, SET);
		   }
		   else{
                HAL_GPIO_WritePin(GPIOA, servo_4, RESET);
                }
            #endif
            #ifdef use_servo_5
                if(cont_st < pwm_st[4]){
			   HAL_GPIO_WritePin(GPIOA, servo_5, SET);
		   }
		   else{
                HAL_GPIO_WritePin(GPIOA, servo_5, RESET);
                }
            #endif
}


long map_int(int16_t x, int16_t eMin, int16_t eMax, int16_t sMin, int16_t sMax){

       return(x -eMin)*(sMax-sMin)/(eMax-eMin)+sMin;
}

void servo_1_write(int16_t angle1){
      pwm_st[0] = map_int(angle1, 0, 180, v_min, v_max);
}
void servo_2_write(int16_t angle1){
      pwm_st[1] = map_int(angle1, 0, 180, v_min, v_max);
}
void servo_3_write(int16_t angle1){
      pwm_st[2] = map_int(angle1, 0, 180, v_min, v_max);
}
void servo_4_write(int16_t angle1){
      pwm_st[3] = map_int(angle1, 0, 180, v_min, v_max);
}
void servo_5_write(int16_t angle1){
      pwm_st[4] = map_int(angle1, 0, 180, v_min, v_max);
}
