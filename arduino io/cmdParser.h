/*
 * cmdParser.h
 *
 * Created: 09.10.2017 20:40:35
 *  Author: Flo
 */ 


#ifndef CMDPARSER_H_
#define CMDPARSER_H_
#include <stdbool.h>
#include <inttypes.h>
#include "uart.h"
#include "COMprotocol.h"
#include "list__array_uint8_t.h"
#include "avr/pgmspace.h"
#include "avr/portpins.h"
extern uint8_t InBufferUart0[100];
extern uint8_t InBufferUart0pointer;



#ifndef nullptr
#define nullptr NULL
#endif



int16_t CharArrayToInt(list_array_uint8_t_element* array);
list_array_uint8_t_element* intToCharArray(int16_t value);
list_array_uint8_t_element* intToCharArray(list_array_uint8_t_element* pre, int16_t value);
class cmdParser{
	public:
		void checkparser();
		void set_parser_flag();
		bool get_parser_flag();
		
	private:
		
		void resolve(list_array_uint8_t_element* cmdlist);
		void parse();
		bool match(list_array_uint8_t_element* cmd,const uint8_t* B, uint8_t size);
		bool parser_flag;



};

list_array_uint8_t_element* build_listElementFromProgmem(list_array_uint8_t_element* preElement, const uint8_t* inp, uint8_t inpSize);



#endif /* CMDPARSER_H_ */