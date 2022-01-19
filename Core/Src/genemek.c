/*
 * genemek.c
 *
 *  Created on: Jan 19, 2022
 *      Author: fatih.colak
 */


#include "genemek.h"
/* include user header file*/
#include "gen_button.h"
#include "gen_buzzer.h"
#include "gen_canbus.h"
#include "gen_flash.h"
#include "gen_struct.h"
/* include st header file*/
#include"gpio.h"
#include "tim.h"
#include "can.h"

void gen_main(void)
{

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	while(1)
	{
		button_all();

	}
}
