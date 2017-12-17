/*
 * UART.cpp
 *
 * Created: 08.10.2017 19:06:26
 *  Author: Flo
 */ 
 #include "uart.h"
 #include <stdbool.h>

uint8_t InBufferUart0[100];
uint8_t InBufferUart0pointer=0;

extern cmdParser myParser;

 void init_UART0(){

	 uint16_t baud = F_CPU / (BAUD * 16L) -1;
	 UBRR0H = (uint8_t) (baud >> 8);
	 UBRR0L = (uint8_t) baud;
	 UCSR0B = UCSR0B_std;
	 UCSR0C = UCSR0C_std;

 }
 //initiate serial communication on pins
 void init_UART1(){
	 
	 uint16_t baud = F_CPU / (BAUD * 16L) -1;
	 UBRR1H = (uint8_t) (baud >> 8);
	 UBRR1L = (uint8_t) baud;
	 UCSR1B = UCSR1B_std;
	 UCSR1C = UCSR1C_std;
}
ISR(USART0_RX_vect){
	InBufferUart0[InBufferUart0pointer] = UDR0;
	InBufferUart0pointer++;

	if(InBufferUart0[InBufferUart0pointer-1]==eot){
		myParser.set_parser_flag();
	}
}
ISR(USART1_RX_vect){
	 uint8_t temp= UDR1;
}
uint8_t serial_out0(uint8_t data){
	 while (!(UCSR0A & (1<<UDRE0)))  // warten bis Senden moeglich
	 {
		 asm("nop");
	 }
	 
	 UDR0 = data;                    //sende Zeichen
	 
	 return 0;
}
void serial_out0(list_array_uint8_t_element* firstElement, uint8_t sepchar){
	while(1){
		serial_out0(firstElement->data, firstElement->data_size);
		if(firstElement->post!=nullptr){
			serial_out0(sepchar);
			firstElement=firstElement->post;
		}else{
			break;
		}
	}
}
void serial_out0(list_array_uint8_t_element* firstElement){
	serial_out0(firstElement, space);
}
uint8_t serial_out0(uint8_t* data, uint8_t count){
for(uint8_t i=0; i<count;i++){
	while (!(UCSR0A & (1<<UDRE0)))  // warten bis Senden moeglich
		{
			asm("nop");
		}
		UDR0 = data[i];                    //sende Zeichen
}	
	return 0;
}
uint8_t serial_out1(uint8_t data){
	 while (!(UCSR0A & (1<<UDRE0)))  // warten bis Senden moeglich
	 {
		 asm("nop");
	 }
	 
	 UDR1 = data;                    //sende Zeichen
	 
	 return 0;
}