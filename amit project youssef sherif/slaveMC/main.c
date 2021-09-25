
#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include "MCAL/Dio/Dio.h"
#include "MCAL/Dio/Dio_config.h"
#include "MCAL/SPI/slave.h"



int main(){
	Dio_init();
	SPI_SlaveInit();
	while(1){
		_delay_ms(10);
		char rec = SPI_SlaveRec();
		if(rec=='a'){
			PORTD ^=(1<<3);
		}
		if(rec=='b'){
			PORTC ^=(1<<2);
		}
	}
	return 0;

}
