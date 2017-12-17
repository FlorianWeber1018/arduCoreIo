/*
 * io.h
 *
 * Created: 11.10.2017 19:30:35
 *  Author: Flo
 */ 
 

#ifndef IO_H_
#define IO_H_


#include <stdbool.h>
#include <inttypes.h>

enum io_config{ninvertInput=0, invertInput=1, ninvertOutput=2, invertOutput=3};

class io_pin{

	public:
	io_pin(volatile uint8_t* DDR, volatile uint8_t* PORT_OUT, volatile uint8_t* PORT_IN, uint8_t PIN, io_config config);
	~io_pin();
	bool get();
	void set(bool state);
	void setconfig(uint8_t);
	io_config getconfig();
	private:
	io_config config;
	volatile uint8_t* PORT_IN;
	volatile uint8_t* PORT_OUT;
	volatile uint8_t* DDR;
	uint8_t PIN;
};

struct  io_port{
	io_pin* pin[8];
};


#endif /* IO_H_ */