/*
 * sct.c
 *
 *  Created on: 7. 10. 2021
 *      Author: student
 */

#include <stdint.h>
#include "sct.h"
#include "main.h"

//static const uint32_t reg_values[4][10] =
//{

static const uint32_t reg_values[1][9] =
{
	 {
	 //----43215678---- @ LED
	 0b0000000100000000 << 16,  // 1
	 0b0000001000000000 << 16,  // 1+2
	 0b0000010000000000 << 16,  // 1+2+3
	 0b0000100000000000 << 16, //1+2+3+4
	 0b0000000010000000 << 16, // 1+2+3+4+5
	 0b0000000001000000 << 16,  // 1+2+3+4+5+6
	 0b0000000000100000 << 16,  // 1+2+3+4+5+6+7
	 0b0000000000010000 << 16,  // 1+2+3+4+5+6+8
	 },

};


void sct_init(void)
{

	sct_led(0);
}

void sct_led(uint32_t value)
{
	for(uint8_t i = 0; i < 32; i++)
	{
		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port,SCT_SDI_Pin,value & 1); // nasouvani hodnoty
		value >>=1;
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);
	}

	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin,1);
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin,0);

}

void sct_value(uint8_t led)
{
	uint32_t reg=0;

	reg |= reg_values[0][led];

	sct_led(reg);
}


