/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    TareaRGB.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "DataTypeDefinitions.h"
#include "MK64F12.h"
#include "Colores.h"


int main(void) {
	/**Variable to capture the input value*/
	uint32 inputValue_sw1 = 0;
	uint32 inputValue_sw2 = 0;
	uint8 x = 1;
	uint8 temp = 0;

	Inicializacion();

    while(1) {
    	/**Reads all the GPIOC*/
		inputValue_sw1 = GPIOC->PDIR;
		/**Masks the GPIOC in the bit of interest*/
		inputValue_sw1 &= 0x40;
		inputValue_sw2 = GPIOA->PDIR;
		inputValue_sw2 &= 0x10;

		 if ((FALSE == inputValue_sw1) && (FALSE == inputValue_sw2)){
			temp = x;
		    x = 6;
			}else if(FALSE == inputValue_sw1){
			x++;
			if(6 == x){
				x = 1;
			}

		}else if(FALSE == inputValue_sw2){
			x--;
			if(0 == x){
				x = 5;
			}
		}

		switch(x){

		/**Green LED ON*/
		case 1:
			GreenLED_ON();
			break;

		/**Blue LED ON*/
		case 2:
			BlueLED_ON();
			break;

		/**Purple LED ON*/
		case 3:
			PurpleLED_ON();
			break;

		/**Red LED ON*/
		case 4:
			RedLED_ON();
			break;

		/**Yellow LED ON*/
		case 5:
			YellowLED_ON();
			break;

		/**White LED ON*/
		case 6:
			WhiteLED_ON();
			x = temp;
			break;

		default:
			break;

		}

    }
    return 0 ;
}




