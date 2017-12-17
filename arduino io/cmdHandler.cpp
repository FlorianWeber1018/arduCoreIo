/*
 * cmdHandler.cpp
 *
 * Created: 18.10.2017 19:25:14
 *  Author: Flo
 */
 #include "cmdHandler.h"
 #include <avr/io.h>
 #include "uart.h"
 #include "cmdParser.h"
 bool cmdHandler__io(){
	return true;
 }
 bool cmdHandler__io_set(){
	return true;
 }
 bool cmdHandler__io_set_value(){
	return true;
 }
 bool cmdHandler__io_set_value_io0(int16_t num){
	for(uint8_t i=0;i<8;i++){
		if((((uint8_t)num) & (1<<i)) == (1<<i)){
			io0->pin[i]->set(true);
		}else{
			io0->pin[i]->set(false);
		}
	}
	if(cmdHandler__io_get_value_io0()){
		return true;
	}
	return false;
 }
 bool cmdHandler__io_set_value_io1(int16_t num){
	for(uint8_t i=0;i<8;i++){
		if((((uint8_t)num) & (1<<i)) == (1<<i)){
			io1->pin[i]->set(true);
			}else{
			io1->pin[i]->set(false);
		}
	}
	if(cmdHandler__io_get_value_io1()){
		return true;
	}
	return false;
 }
 bool cmdHandler__io_set_value_io2(int16_t num){
	for(uint8_t i=0;i<8;i++){
		if((((uint8_t)num) & (1<<i)) == (1<<i)){
			io2->pin[i]->set(true);
			}else{
			io2->pin[i]->set(false);
		}
	}
	if(cmdHandler__io_get_value_io2()){
		return true;
	}
	return false;
 }
 bool cmdHandler__io_set_value_io3(int16_t num){
	for(uint8_t i=0;i<8;i++){
		if((((uint8_t)num) & (1<<i)) == (1<<i)){
			io3->pin[i]->set(true);
			}else{
			io3->pin[i]->set(false);
		}
	}
	if(cmdHandler__io_get_value_io3()){
		return true;
	}
	return false;
 }
 bool cmdHandler__io_set_value_io4(int16_t num){
	 for(uint8_t i=0;i<8;i++){
		 if((((uint8_t)num) & (1<<i)) == (1<<i)){
			 io4->pin[i]->set(true);
			 }else{
			 io4->pin[i]->set(false);
		 }
	 }
	 if(cmdHandler__io_get_value_io4()){
		 return true;
	 }
	 return false;
 }
 bool cmdHandler__io_set_value_io0_true(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 && ((io0->pin[pinnum]->getconfig()==ninvertOutput)||(io0->pin[pinnum]->getconfig()==invertOutput))){
		io0->pin[pinnum]->set(true);
		if(cmdHandler__io_get_value_io0(pinnum)){
			return true;
		}
		return false;
	}
	return true;
 }
 bool cmdHandler__io_set_value_io0_false(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 && ((io0->pin[pinnum]->getconfig()==ninvertOutput)||(io0->pin[pinnum]->getconfig()==invertOutput))){
		io0->pin[pinnum]->set(false);
		if(cmdHandler__io_get_value_io0(pinnum)){
			return true;
		}
		return false;
	}
	return true;
 }
 bool cmdHandler__io_set_value_io1_true(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 && ((io1->pin[pinnum]->getconfig()==ninvertOutput)||(io1->pin[pinnum]->getconfig()==invertOutput))){
		io1->pin[pinnum]->set(true);
		if(cmdHandler__io_get_value_io1(pinnum)){
			return true;
		}
		return false;
	}
	return true;
 }
 bool cmdHandler__io_set_value_io1_false(int16_t pinnum){
 	if(pinnum >= 0 && pinnum <= 7 && ((io1->pin[pinnum]->getconfig()==ninvertOutput)||(io1->pin[pinnum]->getconfig()==invertOutput))){
	 	io1->pin[pinnum]->set(false);
	 	if(cmdHandler__io_get_value_io1(pinnum)){
		 	return true;
	 	}
	 	return false;
 	}
	return true;
 }
 bool cmdHandler__io_set_value_io2_true(int16_t pinnum){
 	if(pinnum >= 0 && pinnum <= 7 && ((io2->pin[pinnum]->getconfig()==ninvertOutput)||(io2->pin[pinnum]->getconfig()==invertOutput))){
	 	io2->pin[pinnum]->set(true);
	 	if(cmdHandler__io_get_value_io2(pinnum)){
		 	return true;
	 	}
	 	return false;
 	}
	return true;
 }
 bool cmdHandler__io_set_value_io2_false(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 && ((io2->pin[pinnum]->getconfig()==ninvertOutput)||(io2->pin[pinnum]->getconfig()==invertOutput))){
		io2->pin[pinnum]->set(false);
		if(cmdHandler__io_get_value_io2(pinnum)){
			return true;
		}
		return false;
	}
	return true;
 }
 bool cmdHandler__io_set_value_io3_true(int16_t pinnum){
 	if(pinnum >= 0 && pinnum <= 7 && ((io3->pin[pinnum]->getconfig()==ninvertOutput)||(io3->pin[pinnum]->getconfig()==invertOutput))){
	 	io3->pin[pinnum]->set(true);
	 	if(cmdHandler__io_get_value_io3(pinnum)){
		 	return true;
	 	}
	 	return false;
 	}
	return true;
 }
 bool cmdHandler__io_set_value_io3_false(int16_t pinnum){
 	if(pinnum >= 0 && pinnum <= 7 && ((io3->pin[pinnum]->getconfig()==ninvertOutput)||(io3->pin[pinnum]->getconfig()==invertOutput))){
	 	io3->pin[pinnum]->set(false);
		if(cmdHandler__io_get_value_io3(pinnum)){
		 	return true;
	 	}
		return false;
 	}
	return true;
 }
 bool cmdHandler__io_set_value_io4_true(int16_t pinnum){
	 if(pinnum >= 0 && pinnum <= 7 && ((io4->pin[pinnum]->getconfig()==ninvertOutput)||(io4->pin[pinnum]->getconfig()==invertOutput))){
		 io4->pin[pinnum]->set(true);
		 if(cmdHandler__io_get_value_io4(pinnum)){
			 return true;
		 }
		 return false;
	 }
	 return true;
 }
 bool cmdHandler__io_set_value_io4_false(int16_t pinnum){
	 if(pinnum >= 0 && pinnum <= 7 && ((io4->pin[pinnum]->getconfig()==ninvertOutput)||(io4->pin[pinnum]->getconfig()==invertOutput))){
		 io4->pin[pinnum]->set(false);
		 if(cmdHandler__io_get_value_io4(pinnum)){
			 return true;
		 }
		 return false;
	 }
	 return true;
 }





 bool cmdHandler__io_set_config(){
	return true;
 }
 bool cmdHandler__io_set_config_io0(int16_t pin_config){
	uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	uint8_t config = (uint8_t)(pin_config & 0x00FF);
	if(config>3){
		return true;
	}
	if((pin > 7) && (pin != 255)){
		return true;
	}
	if(pin==0xFF){
		for(uint8_t i=0;i<8;i++){
			io0->pin[i]->setconfig(config);
		}
		if(cmdHandler__io_get_config_io0()){
			return true;
		}
		return false;
	}else{
		io0->pin[pin]->setconfig(config);
		if(cmdHandler__io_get_config_io0(pin)){
			return true;
		}
		return false;
	}
 }
 bool cmdHandler__io_set_config_io1(int16_t pin_config){
	uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	uint8_t config = (uint8_t)(pin_config & 0x00FF);
	if(config>3){
		return true;
	}
	if((pin > 7) && (pin != 255)){
		return true;
	}
	if(pin==0xFF){
		for(uint8_t i=0;i<8;i++){
			io1->pin[i]->setconfig(config);
		}
		if(cmdHandler__io_get_config_io1()){
			return true;
		}
		return false;
	}else{
		io1->pin[pin]->setconfig(config);
		if(cmdHandler__io_get_config_io1(pin)){
			return true;
		}
		return false;
	}
 }
 bool cmdHandler__io_set_config_io2(int16_t pin_config){
	uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	uint8_t config = (uint8_t)(pin_config & 0x00FF);
	if(config>3){
		return true;
	}
	if((pin > 7) && (pin != 255)){
		return true;
	}
	if(pin==0xFF){
		for(uint8_t i=0;i<8;i++){
			io2->pin[i]->setconfig(config);
		}
		if(cmdHandler__io_get_config_io2()){
			return true;
		}
		return false;
	}else{
		io2->pin[pin]->setconfig(config);
		if(cmdHandler__io_get_config_io2(pin)){
			return true;
		}
		return false;
	}
 }
 bool cmdHandler__io_set_config_io3(int16_t pin_config){
	uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	uint8_t config = (uint8_t)(pin_config & 0x00FF);
	if(config>3){
		return true;
	}
	if((pin > 7) && (pin != 255)){
		return true;
	}
	if(pin==0xFF){
		for(uint8_t i=0;i<8;i++){
			io3->pin[i]->setconfig(config);
		}
		if(cmdHandler__io_get_config_io3()){
			return true;
		}
		return false;
	}else{
		io3->pin[pin]->setconfig(config);
		if(cmdHandler__io_get_config_io3(pin)){
			return true;
		}
		return false;
	}
 }
 bool cmdHandler__io_set_config_io4(int16_t pin_config){
	 uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	 uint8_t config = (uint8_t)(pin_config & 0x00FF);
	 if(config>3){
		 return true;
	 }
	 if((pin > 7) && (pin != 255)){
		 return true;
	 }
	 if(pin==0xFF){
		 for(uint8_t i=0;i<8;i++){
			 io4->pin[i]->setconfig(config);
		 }
		 if(cmdHandler__io_get_config_io4()){
			 return true;
		 }
		 return false;
		 }else{
		 io4->pin[pin]->setconfig(config);
		 if(cmdHandler__io_get_config_io4(pin)){
			 return true;
		 }
		 return false;
	 }
 }
 bool cmdHandler__io_set_config_adc0(int16_t pin_config){
	uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	uint8_t config = (uint8_t)(pin_config & 0x00FF);
	if(pin==0xFF){
		for(uint8_t i=0;i<8;i++){
			if(myADC.setconfig(i, config)){
				return true;
			}
		}
		if(cmdHandler__io_get_config_adc0()){
			return true;
		}
		return false;
	}else{
		myADC.setconfig(pin, config);
		if(cmdHandler__io_get_config_adc0(pin)){
			return true;
		}
		return false;
	}
 }
 bool cmdHandler__io_set_config_adc1(int16_t pin_config){
	uint8_t pin = (uint8_t)((pin_config & 0xFF00 ) >> 8);
	uint8_t config = (uint8_t)(pin_config & 0x00FF);
	if(pin==0xFF){
		for(uint8_t i=0;i<8;i++){
			if(myADC.setconfig(i + 8, config)){
				return true;
			}
		}
		if(cmdHandler__io_get_config_adc1()){
			return true;
		}
		return false;
	}else{
		myADC.setconfig(pin + 8, config);
		if(cmdHandler__io_get_config_adc1(pin)){
			return true;
		}
		return false;
	}
 }








 bool cmdHandler__io_get(){
	return true;
 }
 bool cmdHandler__io_get_config(){
	return true;
 }
 bool cmdHandler__io_get_config_io0(){
 	 bool firstElement=true;
	 for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
		}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_config_io0(i)){
			return true;
		}
	 }
	 return false;
 }
 bool cmdHandler__io_get_config_io0(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 ){
		int16_t resultInt=0;
		resultInt=io0->pin[pinnum]->getconfig();
		list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io0, cmd_io0_size);
		tempElement = intToCharArray(tempElement, pinnum);
		tempElement = intToCharArray(tempElement, resultInt);
		serial_out0(m_list, ':');
		delete m_list;
		return false;
	}else{
		return true;
	}
 }
 bool cmdHandler__io_get_config_io1(){
	 bool firstElement=true;
	 for(int8_t i=0;i<8;i++){
		 if(firstElement){
			 firstElement=false;
		 }else{
			 serial_out0(space);
		 }
		 if(cmdHandler__io_get_config_io1(i)){
			 return true;
		 }
	 }
	 return false;
 }
 bool cmdHandler__io_get_config_io1(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 ){
		int16_t resultInt=0;
		resultInt=io1->pin[pinnum]->getconfig();
		list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io1, cmd_io1_size);
		tempElement = intToCharArray(tempElement, pinnum);
		tempElement = intToCharArray(tempElement, resultInt);
		serial_out0(m_list, ':');
		delete m_list;
		return false;
	}else{
		return true;
	}
 }
 bool cmdHandler__io_get_config_io2(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_config_io2(i)){
			return true;
		}
	}
	return false;
 }
 bool cmdHandler__io_get_config_io2(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 ){
		int16_t resultInt=0;
		resultInt=io2->pin[pinnum]->getconfig();
		list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io2, cmd_io2_size);
		tempElement = intToCharArray(tempElement, pinnum);
		tempElement = intToCharArray(tempElement, resultInt);
		serial_out0(m_list, ':');
		delete m_list;
		return false;
	}else{
		return true;
	}
 }
 bool cmdHandler__io_get_config_io3(){
	 bool firstElement=true;
	 for(int8_t i=0;i<8;i++){
		 if(firstElement){
			 firstElement=false;
			 }else{
			 serial_out0(space);
		 }
		 if(cmdHandler__io_get_config_io3(i)){
			 return true;
		 }
	 }
	 return false;
 }
 bool cmdHandler__io_get_config_io3(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 ){
		int16_t resultInt=0;
		resultInt=io3->pin[pinnum]->getconfig();
		list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io3, cmd_io3_size);
		tempElement = intToCharArray(tempElement, pinnum);
		tempElement = intToCharArray(tempElement, resultInt);
		serial_out0(m_list, ':');
		delete m_list;
		return false;
		}else{
		return true;
	}
 }
 bool cmdHandler__io_get_config_io4(){
	 bool firstElement=true;
	 for(int8_t i=0;i<8;i++){
		 if(firstElement){
			 firstElement=false;
			 }else{
			 serial_out0(space);
		 }
		 if(cmdHandler__io_get_config_io4(i)){
			 return true;
		 }
	 }
	 return false;
 }
 bool cmdHandler__io_get_config_io4(int16_t pinnum){
	 if(pinnum >= 0 && pinnum <= 7 ){
		 int16_t resultInt=0;
		 resultInt=io4->pin[pinnum]->getconfig();
		 list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		 list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io4, cmd_io4_size);
		 tempElement = intToCharArray(tempElement, pinnum);
		 tempElement = intToCharArray(tempElement, resultInt);
		 serial_out0(m_list, ':');
		 delete m_list;
		 return false;
		 }else{
		 return true;
	 }
 }

 bool cmdHandler__io_get_config_adc0(){
	bool firstelement=true;
	for(uint8_t i=0;i<8;i++){
		if(firstelement){
			if(cmdHandler__io_get_config_adc0(i)){
				return true;
			}
			firstelement=false;
		}else{
			serial_out0(space);
			if(cmdHandler__io_get_config_adc0(i)){
				return true;
			}
		}
	}
	return false;
 }
 bool cmdHandler__io_get_config_adc0(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 ){
		int16_t resultInt=myADC.getconfig(pinnum);
		list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_adc0, cmd_adc0_size);
		tempElement = intToCharArray(tempElement, pinnum);
		tempElement = intToCharArray(tempElement, resultInt);
		serial_out0(m_list, ':');
		delete m_list;
		return false;
	}else{
		return true;
	}
 }
 bool cmdHandler__io_get_config_adc1(){
 	bool firstelement=true;
 	for(uint8_t i=0;i<8;i++){
	 	if(firstelement){
		 	if(cmdHandler__io_get_config_adc1(i)){
			 	return true;
		 	}
		 	firstelement=false;
		 	}else{
		 	serial_out0(space);
		 	if(cmdHandler__io_get_config_adc1(i)){
			 	return true;
		 	}
	 	}
 	}
 	return false;
 }
 bool cmdHandler__io_get_config_adc1(int16_t pinnum){
	if(pinnum >= 0 && pinnum <= 7 ){
		int16_t resultInt=myADC.getconfig(pinnum + 8);
		list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_config, cmd_config_size);
		list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_adc1, cmd_adc1_size);
		tempElement = intToCharArray(tempElement, pinnum);
		tempElement = intToCharArray(tempElement, resultInt);
		serial_out0(m_list, ':');
		delete m_list;
		return false;
		}else{
		return true;
	}
 }
 bool cmdHandler__io_get_value(){
	cmdHandler__io_get_value_adc0();
	cmdHandler__io_get_value_adc1();
	cmdHandler__io_get_value_io0();
	cmdHandler__io_get_value_io1();
	cmdHandler__io_get_value_io2();
	cmdHandler__io_get_value_io3();
	cmdHandler__io_get_value_io4();
 }





bool cmdHandler__io_get_value_io0(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_io0(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_io0(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io0, cmd_io0_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		if(io0->pin[pin]->get()){
			intToCharArray(tempElement, 1);
		}else{
			intToCharArray(tempElement, 0);
		}
	}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__io_get_value_io1(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_io1(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_io1(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io1, cmd_io1_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		if(io1->pin[pin]->get()){
			intToCharArray(tempElement, 1);
			}else{
			intToCharArray(tempElement, 0);
		}
	}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__io_get_value_io2(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_io2(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_io2(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io2, cmd_io2_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		if(io2->pin[pin]->get()){
			intToCharArray(tempElement, 1);
			}else{
			intToCharArray(tempElement, 0);
		}
	}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__io_get_value_io3(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_io3(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_io3(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io3, cmd_io3_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		if(io3->pin[pin]->get()){
			intToCharArray(tempElement, 1);
			}else{
			intToCharArray(tempElement, 0);
		}
		}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__io_get_value_io4(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_io4(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_io4(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_io4, cmd_io4_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		if(io4->pin[pin]->get()){
			intToCharArray(tempElement, 1);
			}else{
			intToCharArray(tempElement, 0);
		}
		}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__io_get_value_adc0(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_adc0(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_adc0(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_adc0, cmd_adc0_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		intToCharArray(tempElement, myADC.getoutput(pin));
	}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__io_get_value_adc1(){
	bool firstElement=true;
	for(int8_t i=0;i<8;i++){
		if(firstElement){
			firstElement=false;
			}else{
			serial_out0(space);
		}
		if(cmdHandler__io_get_value_adc1(i)){
			return true;
		}
	}
	return false;
}
bool cmdHandler__io_get_value_adc1(int16_t pin){
	list_array_uint8_t_element* m_list = build_listElementFromProgmem(nullptr, cmd_value, cmd_value_size);
	list_array_uint8_t_element* tempElement = build_listElementFromProgmem(m_list, cmd_adc1, cmd_adc1_size);
	tempElement = intToCharArray(tempElement, pin);
	if(pin >= 0 && pin <= 7){
		intToCharArray(tempElement, myADC.getoutput(pin+8));
	}else{
		return true;
	}
	serial_out0(m_list, ':');
	delete m_list;
	return false;
}
bool cmdHandler__freeMem(){
	list_array_uint8_t_element* tempElement = intToCharArray(freeRam());
	serial_out0(tempElement);
	delete tempElement;
	return false;
}
