/*
 * io.cpp
 *
 * Created: 18.10.2017 21:18:04
 *  Author: Flo
 */
 #include "io.h"
 io_pin::io_pin(volatile uint8_t* DDR, volatile uint8_t* PORT_OUT, volatile uint8_t* PORT_IN, uint8_t PIN, io_config config){
	 this->DDR=DDR;
	 this->PORT_OUT=PORT_OUT;
	 this->PORT_IN=PORT_IN;
	 this->PIN=PIN;
	 setconfig(config);
 }


 io_pin::~io_pin(){

 }
 bool io_pin::get(){
	switch(config){
		case ninvertInput:{
			if((((*PORT_IN)>>PIN) & 1)==1){
				return true;
			}else{
				return false;
			}
		}break;
		case invertInput:{
			if((((*PORT_IN)>>PIN) & 1)==1){
				return false;
			}else{
				return true;
			}
		}break;
		case ninvertOutput:{
			if((((*PORT_OUT)>>PIN) & 1)==1){
				return true;
			}else{
				return false;
			}
		}break;
		case invertOutput:{
			if((((*PORT_OUT)>>PIN) & 1)==1){
				return false;
			}else{
				return true;
			}
		}break;
	}
	return false;
 }
 void io_pin::set(bool state){
 	switch(config){
		case ninvertInput:{
			
		}break;
		case invertInput:{
			
		}break;
		case ninvertOutput:{
			if(state){
				*PORT_OUT |= 1<<PIN;
			}else{
				*PORT_OUT &= ~(1<<PIN);
			}
		}break;
		case invertOutput:{
			if(state){
				*PORT_OUT &= ~(1<<PIN);
			}else{
				*PORT_OUT |= 1<<PIN;
			}
		}break;
	}
 }
 void io_pin::setconfig(uint8_t config){
	this->config=(io_config)config;

	switch(config){
		case ninvertInput:{
			*DDR &= ~(1<<PIN);
			*PORT_OUT |= 1<<PIN;
		}break;
		case invertInput:{
			*DDR &= ~(1<<PIN);
			*PORT_OUT |= 1<<PIN;
		}break;
		case ninvertOutput:{
			*DDR |= 1<<PIN;
			*PORT_OUT &= ~(1<<PIN);
		}break;
		case invertOutput:{
			*DDR |= 1<<PIN;
			*PORT_OUT |= 1<<PIN;
		}
	}
 }
 io_config io_pin::getconfig(){
	 return config;
 }