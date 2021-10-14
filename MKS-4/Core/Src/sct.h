/*
 * sct.h
 *
 *  Created on: 14. 10. 2021
 *      Author: xvyw888
 */

#ifndef SCT_H_
#define SCT_H_

#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0) 	 /*PB5*/
#define sct_sdi(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0) 	 /*PB4*/
#define sct_clk(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)   /*PB3*/
#define sct_noe(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0) /*PB10*/

void sct_init(void); /*inicialization*/
void sct_led(uint32_t value);
void sct_value(uint16_t value, uint8_t led); /*def. of value */

#endif





