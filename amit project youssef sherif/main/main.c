/*

 *		to create new project for first time
 *      RightClick on the project then enter properties
 *      AVR ---> AVR Dude ---> programmer config -----> new ---> 3 wa7d mn t7t ---> ok
 *		Target Hardware ---> ATMega32  ---> 1600000
 *		C/C++ build ---> Settings ->>>> Generate Hex (first choice)
 *		Dio ---> MCAL layer
 *		VSS ---> ground
 *		VDD---> VCC power supply
 *		V0 --> potentiometer to control the brightness
 *		E---> enable ----> trigger high to low
 *		RW---> read&write  ----> deafult case ground (0 ---> write)
 *		RS----> register select ---> command or data 0 -> command 1-> data
 *		command ---> RW 0  RS 0
 *		Data ----> RW 0 RS 1
 *		E ---> Delay ---> 100ms
 *		4bit mood ---> send 4 by 4 not all 8 at one time
 *		LCD --> HAL layer ----> it uses MCAL (Dio)
 *
 */
#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#include "MCAL/Dio/Dio.h"
#include "MCAL/Dio/Dio_config.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include "HAL/LCD/lcd.h"
#include "MCAL/SPI/master/master.h"
#include "HAL/UART/uart.h"


volatile int ctr = 0;
volatile int ctr2 = 0;


void test(){
	Dio_write(Led0,High);
	Dio_write(Led1,High);
}

int main(){
	Dio_init();
	SPI_MasterInit();
	UART_init(103);
//	DDRA |= (1<<2);
	while(1){
		_delay_ms();

		unsigned char rec = UART_recieve();
//		if(rec=='a'){
//			PORTA ^= (1<<2);
//		}
		SPI_MasterTransmit(rec);
		_delay_ms(10);

	}

}
