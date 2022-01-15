/*
 * Button_Toggle_LED.c
 *
 * Created: 1/10/2022 1:46:40 AM
 * Author : Abdelrhman Elsawy
 */ 

#include "../LIB/Typedef.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/BTN/Button.h"

BTN_t button = {PORTC,PIN4};
LED_t led = {PORTB,PIN5};
	
int main(void)
{	
	BTN_u8Init(button);
	LED_u8Init(led);

	while (1)
	{		
		uint8_t u8BTNStatu ;
		if (( BTN_u8IsPressed ( button,&u8BTNStatu ) == STD_TYPES_OK ) && ( u8BTNStatu == HIGH ))
		{
			LED_u8Toggle (led);
			while (( BTN_u8IsPressed ( button,&u8BTNStatu ) == STD_TYPES_OK ) && ( u8BTNStatu == HIGH )){}
		}
	}
}
