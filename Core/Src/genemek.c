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
//#include "gen_display.h"
/* include st header file*/
#include"gpio.h"
#include "tim.h"
#include "can.h"

gen_struct gen_s;


// task ların kaç saniyede bir işlem göreceği ms cinsinden buradan ayarlanır
#define BUTTON_INTERVAL   10 // interval in ms
#define CANBUS_INTERVAL   500 // 500 ms de bir tx işlemi için
#define FLASH_INTERVAL	5000 // 1 sn flash write read
// display için eklenecek





void gen_main(void)
{
	//uint8_t can_rx_buffer[8] = {0,0,0,0,0,0,0,0};
	uint8_t can_tx_buffer[8] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	 CAN_HandleTypeDef hcan;

	 CAN_TxHeaderTypeDef pTxHeader;
	 CAN_RxHeaderTypeDef pRxHeader;

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	gen_canbus_config();
	HAL_CAN_Start(&hcan);
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING); //enable interrupts
	gen_s.last_time_button 	= HAL_GetTick(); // burası mevcut ms yi verir
	gen_s.last_time_canbus  = HAL_GetTick(); // burası mevcut ms yi verir
	gen_s.last_time_flash 	= HAL_GetTick(); // burası mevcut ms yi verir



	while(1)
	{
//		num_10();
		gen_s.current_time = HAL_GetTick();

		// button işlemi her 10 ms de bir kontrol edilir
			 	  	  	  	  if(gen_s.current_time - gen_s.last_time_button > BUTTON_INTERVAL )
			 	  	  	  	  	  {
			 	  	  	  		  	  gen_s.last_time_button = HAL_GetTick(); // zamanı günceller
			 	  	  	  	  		  button_all();

			 	  	  	  	  	  }
			 	  	  	  	  if(gen_s.current_time - gen_s.last_time_canbus > CANBUS_INTERVAL )
			 	  	  	  	  	  	  {
			 	  	  	  		  	  	  gen_s.last_time_canbus= HAL_GetTick(); // zamanı günceller
//			 	  	  	  		  		  for(int _index =0; _index<25;_index++)
//			 	  	  	  		  		  {
			 	  	  	  		  			  gen_s.count2++;

//			 	  	  	  		  		num_18();








//			 	  	  	  		  		  }
//			 	  	  	  		  	  	  HAL_CAN_AddTxMessage(&hcan, &pTxHeader, can_tx_buffer, &gen_s.pTxMailbox); // tx fonksiyonu
			 	  	  	  		  	  	  gen_s.count3++;
			 	  	  	  	  	  	  }
			 	  	  	  	  if(gen_s.current_time - gen_s.last_time_flash > FLASH_INTERVAL )
			 	  	  	 	 	  	  	  	  	  	  {
			 	  	  	  		  	  	  gen_s.last_time_flash= HAL_GetTick(); // zamanı günceller
			 	  	  	  		  	  	  	  //GEN_nvm();
			 	  	  	  		  	  	  gen_s.count1++;
			 	  	  	  		  	  	  	  uint32_t Robot_Num_Flash_Add = 0x08001000;
			 	  	  	  		  	  	  	  uint32_t ID_NUM = *(__IO uint16_t*) (Robot_Num_Flash_Add);
			 	  	  	 	 	  	  	  	  	  	  }



	}


}
