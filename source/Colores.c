/*
 * Colores.c

 *
 *  Created on: 07/09/2017
 *      Author: Roberto
 */

#include "DataTypeDefinitions.h"
#include "MK64F12.h"

void delay(uint32 delay)
{
volatile uint32 counter;

for(counter=delay; counter > 0; counter--)
	{
	}
}

void GreenLED_ON(void){
	GPIOB->PDOR = 0x600000;
	GPIOE->PDOR = ~(0x4000000);
	delay(500000);
}

void BlueLED_ON(void){
	GPIOE->PDOR = 0x4000000;
	GPIOB->PDOR = 0x400000;
	delay(500000);
}

void PurpleLED_ON(void){
	GPIOE->PDOR = 0x4000000;
	GPIOB->PDOR = 0x0;
	delay(500000);
}

void RedLED_ON(void){
	GPIOE->PDOR = 0x4000000;
	GPIOB->PDOR = 0x200000;
	delay(500000);
}

void YellowLED_ON(void){
	GPIOB->PDOR = 0x200000;
	GPIOE->PDOR = ~(0x4000000);
	delay(500000);
}

void WhiteLED_ON(void){
	GPIOB->PDOR = 0x0;
	GPIOE->PDOR = 0x0;
	delay(500000);
}

void Inicializacion(void){
	/**Activating the GPIOB, GPIOC and GPIOE clock gating*/
	SIM->SCGC5 = 0x2E00;
	/**Pin control configuration of GPIOB pin22 and pin21 as GPIO*/
	PORTB->PCR[21] = 0x00000100;
	PORTB->PCR[22] = 0x00000100;
	/**Pin control configuration of GPIOC pin6 as GPIO with is pull-up resistor enabled*/
	PORTC->PCR[6] = 0x00000103;
	/**Pin control configuration of GPIOA pin4 as GPIO with is pull-up resistor enabled*/
	PORTA->PCR[4] = 0x00000103;
	/**Pin control configuration of GPIOE pin26 as GPIO*/
	PORTE->PCR[26] = 0x00000100;
	/**Assigns a safe value to the output pin21 of the GPIOB*/
	GPIOB->PDOR = 0x00200000;
	/**Assigns a safe value to the output pin22 of the GPIOB*/
	GPIOB->PDOR |= 0x00400000;
	/**Assigns a safe value to the output pin26 of the GPIOE*/
	GPIOE->PDOR |= 0x04000000;

	GPIOC->PDDR &= ~(0x40);
	GPIOA->PDDR &= ~(0x10);
	/**Configures GPIOB pin21 as output*/
	GPIOB->PDDR = 0x00200000;
	/**Configures GPIOB pin22 as output*/
	GPIOB->PDDR |= 0x00400000;
	/**Configures GPIOE pin26 as output*/
	GPIOE->PDDR |= 0x04000000;
}
