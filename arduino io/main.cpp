/*
 * arduino io.cpp
 *
 * Created: 11.10.2017 19:24:10
 * Author : Flo
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "cmdParser.h"
#include "io.h"
#include "cmdHandler.h"
#include <util/delay.h>
AnalogDigitalConverter myADC;
cmdParser myParser;
io_port* io0;
io_port* io1;
io_port* io2;
io_port* io3;
io_port* io4;


int main(void)
{
	init_ADC();
	init_io();
	init_UART0();
	sei();
	/*
	InBufferUart0[0]='i';
	InBufferUart0[1]='o';
	InBufferUart0[2]=space;
	InBufferUart0[3]='g';
	InBufferUart0[4]='e';
	InBufferUart0[5]='t';
	InBufferUart0[6]=space;
	InBufferUart0[7]='c';
	InBufferUart0[8]='o';
	InBufferUart0[9]='n';
	InBufferUart0[10]='f';
	InBufferUart0[11]='i';
	InBufferUart0[12]='g';
	InBufferUart0[13]=space;
	InBufferUart0[14]='i';
	InBufferUart0[15]='o';
	InBufferUart0[16]='0';
	InBufferUart0[17]=space;
	InBufferUart0[18]=eot;
	InBufferUart0pointer=19;
	myParser.set_parser_flag();
	*/
	
	while(1){
		myParser.checkparser();
	}
	
}
void init_io(){
	io_config init_config=invertOutput;
	//__________________________________________________________________________________
	//pins noch anzupassen
	io0 = new io_port;
	io0->pin[0]=new io_pin(&DDRC, &PORTC, &PINC, 1, init_config);
	io0->pin[1]=new io_pin(&DDRC, &PORTC, &PINC, 3, init_config);
	io0->pin[2]=new io_pin(&DDRC, &PORTC, &PINC, 5, init_config);
	io0->pin[3]=new io_pin(&DDRC, &PORTC, &PINC, 7, init_config);
	io0->pin[4]=new io_pin(&DDRA, &PORTA, &PINA, 6, init_config);
	io0->pin[5]=new io_pin(&DDRA, &PORTA, &PINA, 4, init_config);
	io0->pin[6]=new io_pin(&DDRA, &PORTA, &PINA, 2, init_config);
	io0->pin[7]=new io_pin(&DDRA, &PORTA, &PINA, 0, init_config);
	
	io1 = new io_port;
	io1->pin[0]=new io_pin(&DDRC, &PORTC, &PINC, 0, init_config);
	io1->pin[1]=new io_pin(&DDRC, &PORTC, &PINC, 2, init_config);
	io1->pin[2]=new io_pin(&DDRC, &PORTC, &PINC, 4, init_config);
	io1->pin[3]=new io_pin(&DDRC, &PORTC, &PINC, 6, init_config);
	io1->pin[4]=new io_pin(&DDRA, &PORTA, &PINA, 7, init_config);
	io1->pin[5]=new io_pin(&DDRA, &PORTA, &PINA, 5, init_config);
	io1->pin[6]=new io_pin(&DDRA, &PORTA, &PINA, 3, init_config);
	io1->pin[7]=new io_pin(&DDRA, &PORTA, &PINA, 1, init_config);
	//__________________________________________________________________________________
	io2 = new io_port;
	io2->pin[0]=new io_pin(&DDRD, &PORTD, &PIND, 7, init_config);
	io2->pin[1]=new io_pin(&DDRG, &PORTG, &PING, 1, init_config);
	io2->pin[2]=new io_pin(&DDRL, &PORTL, &PINL, 7, init_config);
	io2->pin[3]=new io_pin(&DDRL, &PORTL, &PINL, 5, init_config);
	io2->pin[4]=new io_pin(&DDRL, &PORTL, &PINL, 3, init_config);
	io2->pin[5]=new io_pin(&DDRL, &PORTL, &PINL, 1, init_config);
	io2->pin[6]=new io_pin(&DDRB, &PORTB, &PINB, 3, init_config);
	io2->pin[7]=new io_pin(&DDRB, &PORTB, &PINB, 1, init_config);
	io3 = new io_port;
	io3->pin[0]=new io_pin(&DDRG, &PORTG, &PING, 2, init_config);
	io3->pin[1]=new io_pin(&DDRG, &PORTG, &PING, 0, init_config);
	io3->pin[2]=new io_pin(&DDRL, &PORTL, &PINL, 6, init_config);
	io3->pin[3]=new io_pin(&DDRL, &PORTL, &PINL, 4, init_config);
	io3->pin[4]=new io_pin(&DDRL, &PORTL, &PINL, 2, init_config);
	io3->pin[5]=new io_pin(&DDRL, &PORTL, &PINL, 0, init_config);
	io3->pin[6]=new io_pin(&DDRB, &PORTB, &PINB, 2, init_config);
	io3->pin[7]=new io_pin(&DDRB, &PORTB, &PINB, 0, init_config);
	//pins noch anzupassen
	io4 = new io_port;
	io4->pin[0]=new io_pin(&DDRH, &PORTH, &PINH, 5, init_config);
	io4->pin[1]=new io_pin(&DDRH, &PORTH, &PINH, 6, init_config);
	io4->pin[2]=new io_pin(&DDRE, &PORTE, &PINE, 4, init_config);
	io4->pin[3]=new io_pin(&DDRE, &PORTE, &PINE, 5, init_config);
	io4->pin[4]=new io_pin(&DDRG, &PORTG, &PING, 5, init_config);
	io4->pin[5]=new io_pin(&DDRE, &PORTE, &PINE, 3, init_config);
	io4->pin[6]=new io_pin(&DDRH, &PORTH, &PINH, 3, init_config);
	io4->pin[7]=new io_pin(&DDRH, &PORTH, &PINH, 4, init_config);
	//__________________________________________________________________________________
}
void init_ADC(){
	
}
ISR (ADC_vect){
	myADC.sample();
}
int16_t freeRam () {
	extern int __heap_start, *__brkval;
	int v;
	return (int16_t) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}