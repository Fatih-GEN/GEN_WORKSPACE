/*
 * gen_display.c
 *
 *  Created on: Jan 19, 2022
 *
 */


#include "genemek.h"
/* include user header file*/
#include "gen_button.h"
#include "gen_buzzer.h"
#include "gen_canbus.h"
#include "gen_flash.h"
#include "gen_struct.h"
#include "gen_display.h"
/* include st header file*/
#include"gpio.h"
#include "tim.h"
#include "can.h"


#define data_on    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET)
#define data_off   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET)
#define latch_on   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET)
#define latch_off  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET)
#define clk_on     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET)
#define clk_off    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET)
#define oe_on      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET)
#define oe_off     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET)

#define led_on   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#define led_off   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);


void display_all(void)
{
	latch_on;
	data_on;

	clk_on;
}
void MBI5026_SendData(uint32_t data){
	uint8_t bit_index;
	//HAL_GPIO_WritePin(MBI5026_OE_PORT,MBI5026_OE_PIN,GPIO_PIN_SET);
//	oe_off;
	oe_on;


//	HAL_GPIO_WritePin(MBI5026_LE_PORT,MBI5026_LE_PIN,GPIO_PIN_RESET);
	latch_off;


	for (bit_index = 0;bit_index<32;bit_index++){

//		HAL_GPIO_WritePin(MBI5026_CLK_PORT,MBI5026_CLK_PIN,GPIO_PIN_RESET);
		clk_off;



		if (((data>>bit_index)&0x0001) == 0){

//			HAL_GPIO_WritePin(MBI5026_SDI_PORT,MBI5026_SDI_PIN,GPIO_PIN_RESET);
			data_off;

		}
		else {
//			HAL_GPIO_WritePin(MBI5026_SDI_PORT,MBI5026_SDI_PIN,GPIO_PIN_SET);
			data_on;

		}
//		__nop();
//		HAL_GPIO_WritePin(MBI5026_CLK_PORT,MBI5026_CLK_PIN,GPIO_PIN_SET);
		clk_on;

	}
//	HAL_GPIO_WritePin(MBI5026_LE_PORT,MBI5026_LE_PIN,GPIO_PIN_SET);
	latch_on;


//	HAL_GPIO_WritePin(MBI5026_OE_PORT,MBI5026_OE_PIN,GPIO_PIN_RESET);
//	oe_on;
	oe_off
	;
}

void MBI5026_Display(uint8_t _index){
	if (_index == 8){
		MBI5026_SendData(0x0001<<9);
	}
	else if (_index == 9){
		MBI5026_SendData(0x0001<<8);
	}
	else {

		MBI5026_SendData(0x0001<<_index);
	}
}

void MBI5026_Off(uint8_t _index){
	MBI5026_SendData(0xFFFF & (~(1<<_index)));
}

void num_18(void)
{
	l_num_1();
	r_num_8();
}

void num_17(void)
{
	l_num_1();
	r_num_7();
}

void num_16(void)
{
	l_num_1();
	r_num_6();
}

void num_15(void)
{
	l_num_1();
	r_num_5();
}

void num_14(void)
{
	l_num_1();
	r_num_4();
}

void num_13(void)
{
	l_num_1();
	r_num_3();
}

void num_12(void)
{
	l_num_1();
	r_num_2();
}


void num_11(void)
{
	l_num_1();
	r_num_1();
}

void num_10(void)
{
	l_num_1();
	r_num_0();
}

/*left display numbers*/
void l_num_9(void)
{
	 MBI5026_Display(25);
	 MBI5026_Display(26);
	 MBI5026_Display(27);
	 MBI5026_Display(28);
	 MBI5026_Display(29);
	 MBI5026_Display(31);
}

void l_num_8(void)
{
	 MBI5026_Display(25);
	 MBI5026_Display(26);
	 MBI5026_Display(27);
	 MBI5026_Display(28);
	 MBI5026_Display(29);
	 MBI5026_Display(30);
	 MBI5026_Display(31);
}



void l_num_7(void)
{
	 MBI5026_Display(25);
	 MBI5026_Display(26);
	 MBI5026_Display(27);
}

void l_num_6(void)
{
	MBI5026_Display(25);
	MBI5026_Display(27);
	MBI5026_Display(28);
	MBI5026_Display(29);
	MBI5026_Display(30);
	MBI5026_Display(31);
}


void l_num_5(void)
{
	MBI5026_Display(25);
	MBI5026_Display(27);
	MBI5026_Display(28);
	MBI5026_Display(29);
	MBI5026_Display(31);
}

void l_num_4(void)
{

	MBI5026_Display(25);
	MBI5026_Display(26);
	MBI5026_Display(28);
	MBI5026_Display(31);
}

void l_num_3(void)
{

	MBI5026_Display(25);
	MBI5026_Display(26);
	MBI5026_Display(27);
	MBI5026_Display(28);
	MBI5026_Display(29);
}
void l_num_2(void)
{

	MBI5026_Display(26);
	MBI5026_Display(27);
	MBI5026_Display(28);
	MBI5026_Display(29);
	MBI5026_Display(30);
}

void l_num_1(void)
{
	MBI5026_Display(26);
	MBI5026_Display(25);

}
void l_num_0(void)
{
	 MBI5026_Display(25);
	 MBI5026_Display(26);
	 MBI5026_Display(27);
	 MBI5026_Display(29);
	 MBI5026_Display(30);
	 MBI5026_Display(31);
}
/*right display numbers*/
void r_num_9(void)
{
	 MBI5026_Display(18);
	 MBI5026_Display(19);
	 MBI5026_Display(20);
	 MBI5026_Display(21);
	 MBI5026_Display(22);
	 MBI5026_Display(24);
}

void r_num_8(void)
{
	 MBI5026_Display(18);
	 MBI5026_Display(19);
	 MBI5026_Display(20);
	 MBI5026_Display(21);
	 MBI5026_Display(22);
	 MBI5026_Display(23);
	 MBI5026_Display(24);
}



void r_num_7(void)
{
	 MBI5026_Display(18);
	 MBI5026_Display(19);
	 MBI5026_Display(20);
}

void r_num_6(void)
{
	MBI5026_Display(18);
	MBI5026_Display(20);
	MBI5026_Display(21);
	MBI5026_Display(22);
	MBI5026_Display(23);
	MBI5026_Display(24);
}


void r_num_5(void)
{
	MBI5026_Display(18);
	MBI5026_Display(20);
	MBI5026_Display(21);
	MBI5026_Display(22);
	MBI5026_Display(24);
}

void r_num_4(void)
{

	MBI5026_Display(18);
	MBI5026_Display(19);
	MBI5026_Display(21);
	MBI5026_Display(24);
}

void r_num_3(void)
{

	MBI5026_Display(18);
	MBI5026_Display(19);
	MBI5026_Display(20);
	MBI5026_Display(21);
	MBI5026_Display(22);
}
void r_num_2(void)
{

	MBI5026_Display(19);
	MBI5026_Display(20);
	MBI5026_Display(21);
	MBI5026_Display(22);
	MBI5026_Display(23);
}

void r_num_1(void)
{
	MBI5026_Display(18);
	MBI5026_Display(19);

}

void r_num_0(void)
{
	 MBI5026_Display(18);
	 MBI5026_Display(19);
	 MBI5026_Display(20);
	 MBI5026_Display(22);
	 MBI5026_Display(23);
	 MBI5026_Display(24);
}
void display_down(void)
{
	MBI5026_Display(14);
	MBI5026_Display(15);
}

void display_up(void)
{
	MBI5026_Display(12);
	MBI5026_Display(13);
}
void display_non_service(void)
{
	MBI5026_Display(10);
	MBI5026_Display(8);
}
void display_mt(void) // bakım
{
	 MBI5026_Display(9); //0x09
}
void display_busy(void)
{
	MBI5026_Display(7);
	MBI5026_Display(11);
}
