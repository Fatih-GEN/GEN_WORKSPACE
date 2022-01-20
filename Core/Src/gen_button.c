/*
 * button.c
 *
 *  Created on: Jan 19, 2022
 *      Author: fatih.colak
 */



/* include user header file*/
#include "genemek.h"
#include "gen_button.h"
#include "gen_buzzer.h"
#include "gen_canbus.h"
#include "gen_flash.h"
#include "gen_struct.h"
/* include st header file*/
#include"gpio.h"
#include "tim.h"
#include "can.h"


#define button_press_time 100
#define led_yan_time      3000
#define display_time 	  1500

void menu(void)
{
	uint16_t display_count = 1500;
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 0 )  // basıldı demek
		{
			buzzer_on();
			HAL_Delay(button_press_time);
			buzzer_off();

//			led_on();
//			HAL_Delay(led_yan_time);
//			led_off();
			while(display_count>0)
			{
				display_up();
				display_down();
				display_count--;

			}

		}
}

void up(void)
{

	uint16_t display_count = 1500;

	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0 )
		{

			buzzer_on();
			HAL_Delay(button_press_time);
			buzzer_off();

			while(display_count>0)
			{
				display_up();
				display_count--;

			}

			led_on(); // basıldı demek
		}
}

void down(void)
{
	uint16_t display_count = 1500;
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 0 )
		{
			buzzer_on();
			HAL_Delay(button_press_time);
			buzzer_off();

			while(display_count>0)
			{
				display_down();
				display_count--;

			 }



			led_off(); // basıldı demek
		}
}

void button_all(void)
{
	menu();
	up();
	down();
}
