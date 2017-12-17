/*
 * cmdParser.cpp
 *
 * Created: 09.10.2017 20:40:21
 *  Author: Flo
 */
#include "cmdParser.h"
#include "cmdHandler.h"
#include <string.h>
#include "uart.h"

void cmdParser::checkparser(){
	if(parser_flag){
		parse();
		InBufferUart0pointer=0;
		parser_flag=false;
	}
	
}
void cmdParser::parse(){

	uint8_t i=0;
	
	uint8_t current_command[25]={};
	uint8_t* p_current_command = current_command;
	list_array_uint8_t_element* cmdlist;
	list_array_uint8_t_element* last_element;
	bool firstelement=true;
	while(i<InBufferUart0pointer-1){
		uint8_t  j=0;
		j=0;
		while(InBufferUart0[i]!=space && i<InBufferUart0pointer-1){
			p_current_command[j]=InBufferUart0[i];
			j++;
			i++;
		}
		if(firstelement){
			last_element = new list_array_uint8_t_element(p_current_command, j);
			cmdlist = last_element;
			firstelement=false;
		}else{
			last_element = new list_array_uint8_t_element(last_element, p_current_command, j);
		}
		

		i++;
	}
	resolve(cmdlist);
	InBufferUart0pointer=0;
	delete cmdlist;
	serial_out0(eot);
}
void cmdParser::resolve(list_array_uint8_t_element* cmdlist){
bool parsed=false;
	list_array_uint8_t_element* cmd =cmdlist;
	if(cmdlist->data_size!=0){
		if(match(cmd, cmd_freeMem, cmd_freeMem_size)){
			if(cmd->post!=nullptr){

			}else{
				if(!cmdHandler__freeMem()){
					parsed=true;
				}
			}
		}
		if(match(cmd, cmd_io, cmd_io_size)){
			if(cmd->post!=nullptr){
				cmd=cmd->post;
				if(match(cmd, cmd_get, cmd_get_size)){
					if(cmd->post!=nullptr){
						cmd=cmd->post;
						if(match(cmd, cmd_config, cmd_config_size)){
							if (cmd->post!=nullptr){
								cmd=cmd->post;
								if(match(cmd,cmd_io0, cmd_io0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_get_config_io0(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_config_io0()){
											parsed=true;
										}
										
									}
								}
								if(match(cmd,cmd_io1, cmd_io1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_get_config_io1(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_config_io1()){
											parsed=true;
										}
										
									}
								}
								if(match(cmd,cmd_io2, cmd_io2_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_get_config_io2(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_config_io2()){
											parsed=true;
										}
									}
								}
								if(match(cmd,cmd_io3, cmd_io3_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_get_config_io3(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_config_io3()){
											parsed=true;
										}
									}
								}
								if(match(cmd,cmd_io4, cmd_io4_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_config_io4(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_config_io4()){
											parsed=true;
										}
									}
								}
								if(match(cmd,cmd_adc0, cmd_adc0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_get_config_adc0(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_config_adc0()){
											parsed=true;
										}
									}
								}
								if(match(cmd,cmd_adc1, cmd_adc1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_get_config_adc1(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_config_adc1()){
											parsed=true;
										}
									}
								}
							}else{
								if(!cmdHandler__io_get_config()){
									parsed=true;
								}
							}
						}
						if(match(cmd, cmd_value, cmd_value_size)){
							if(cmd->post!=nullptr){
								cmd=cmd->post;
								if(match(cmd, cmd_io0, cmd_io0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
										
										}else{
											if(!cmdHandler__io_get_value_io0(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
									}else{
										if(!cmdHandler__io_get_value_io0()){
											parsed=true;
										}
									}
								}
								if(match(cmd, cmd_io1, cmd_io1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_value_io1(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_value_io1()){
											parsed=true;
										}
									}
								}
								if(match(cmd, cmd_io2, cmd_io2_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_value_io2(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_value_io2()){
											parsed=true;
										}
									}
								}
								if(match(cmd, cmd_io3, cmd_io3_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_value_io3(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_value_io3()){
											parsed=true;
										}
									}
								}
								if(match(cmd, cmd_io4, cmd_io4_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_value_io4(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_value_io4()){
											parsed=true;
										}
									}
								}
								if(match(cmd, cmd_adc0, cmd_adc0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_value_adc0(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_value_adc0()){
											parsed=true;
										}
									}
								}
								if(match(cmd, cmd_adc1, cmd_adc1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_get_value_adc1(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										if(!cmdHandler__io_get_value_adc1()){
											parsed=true;
										}
									}
								}

							}else{
								if(!cmdHandler__io_get_value()){
									parsed=true;
								}
							}
						}
					}else{
						if(!cmdHandler__io_get()){
							parsed=true;
						}
					}
				}
				if (match(cmd, cmd_set, cmd_set_size)){
					if(cmd->post!=nullptr){
						cmd=cmd->post;
						if(match(cmd, cmd_value, cmd_value_size)){
							if(cmd->post!=nullptr){
								cmd=cmd->post;
								if(match(cmd, cmd_io0, cmd_io0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(match(cmd, cmd_true, cmd_true_size)){
											if(cmd->post!=nullptr){
												cmd=cmd->post;
												if(cmd->post!=nullptr){

												}{
													if(!cmdHandler__io_set_value_io0_true(CharArrayToInt(cmd))){
														parsed=true;
													}
												}
											}else{

											}
										}else{
											if(match(cmd, cmd_false, cmd_false_size)){
												if(cmd->post!=nullptr){
													cmd=cmd->post;
													if(cmd->post!=nullptr){

														}{
														if(!cmdHandler__io_set_value_io0_false(CharArrayToInt(cmd))){
															parsed=true;
														}
													}
												}else{

												}
											}else{
												if(!cmdHandler__io_set_value_io0(CharArrayToInt(cmd))){
													parsed=true;
												}
											}
										}
									}else{
										//gibts net
									}
								}
								if(match(cmd, cmd_io1, cmd_io1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(match(cmd, cmd_true, cmd_true_size)){
											if(cmd->post!=nullptr){
												cmd=cmd->post;
												if(cmd->post!=nullptr){

													}{
													if(!cmdHandler__io_set_value_io1_true(CharArrayToInt(cmd))){
														parsed=true;
													}
												}
												}else{

											}
										}else{
											if(match(cmd, cmd_false, cmd_false_size)){
												if(cmd->post!=nullptr){
													cmd=cmd->post;
													if(cmd->post!=nullptr){

														}{
														if(!cmdHandler__io_set_value_io1_false(CharArrayToInt(cmd))){
															parsed=true;
														}
													}
												}else{

												}
											}else{
												if(!cmdHandler__io_set_value_io1(CharArrayToInt(cmd))){
													parsed=true;
												}
											}
										}
										
									}else{
										//gibts net
									}
								}
								if(match(cmd, cmd_io2, cmd_io2_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(match(cmd, cmd_true, cmd_true_size)){
											if(cmd->post!=nullptr){
												cmd=cmd->post;
												if(cmd->post!=nullptr){

													}{
													if(!cmdHandler__io_set_value_io2_true(CharArrayToInt(cmd))){
														parsed=true;
													}
												}
											}else{

											}
										}else{
											if(match(cmd, cmd_false, cmd_false_size)){
												if(cmd->post!=nullptr){
													cmd=cmd->post;
													if(cmd->post!=nullptr){

														}{
														if(!cmdHandler__io_set_value_io2_false(CharArrayToInt(cmd))){
															parsed=true;
														}
													}
												}else{

												}
											}else{
												if(!cmdHandler__io_set_value_io2(CharArrayToInt(cmd))){
													parsed=true;
												}
											}
										}
										
									}else{
										//gibts net
									}
								}
								if(match(cmd, cmd_io3, cmd_io3_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(match(cmd, cmd_true, cmd_true_size)){
											if(cmd->post!=nullptr){
												cmd=cmd->post;
												if(cmd->post!=nullptr){

													}{
													if(!cmdHandler__io_set_value_io3_true(CharArrayToInt(cmd))){
														parsed=true;
													}
												}
												}else{

											}
										}else{
											if(match(cmd, cmd_false, cmd_false_size)){
												if(cmd->post!=nullptr){
													cmd=cmd->post;
													if(cmd->post!=nullptr){

														}{
														if(!cmdHandler__io_set_value_io3_false(CharArrayToInt(cmd))){
															parsed=true;
														}
													}
												}else{

												}
											}else{
												if(!cmdHandler__io_set_value_io3(CharArrayToInt(cmd))){
													parsed=true;
												}
											}
										}
									}else{
										//gibts net
									}
								}
								if(match(cmd, cmd_io4, cmd_io4_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(match(cmd, cmd_true, cmd_true_size)){
											if(cmd->post!=nullptr){
												cmd=cmd->post;
												if(cmd->post!=nullptr){

													}{
													if(!cmdHandler__io_set_value_io4_true(CharArrayToInt(cmd))){
														parsed=true;
													}
												}
												}else{

											}
											}else{
											if(match(cmd, cmd_false, cmd_false_size)){
												if(cmd->post!=nullptr){
													cmd=cmd->post;
													if(cmd->post!=nullptr){

														}{
														if(!cmdHandler__io_set_value_io4_false(CharArrayToInt(cmd))){
															parsed=true;
														}
													}
													}else{

												}
												}else{
												if(!cmdHandler__io_set_value_io4(CharArrayToInt(cmd))){
													parsed=true;
												}
											}
										}
										}else{
										//gibts net
									}
								}
							}else{
								
								if(!cmdHandler__io_set_value()){
									parsed=true;
								}
							}
						}
						if(match(cmd, cmd_config, cmd_config_size)){
							if(cmd->post!=nullptr){
								cmd=cmd->post;
								if(match(cmd, cmd_io0, cmd_io0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
										}else{
											if(!cmdHandler__io_set_config_io0(CharArrayToInt(cmd))){
												parsed=true;
											}
										}	
									}else{
										
									}
								}
								if(match(cmd, cmd_io1, cmd_io1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_set_config_io1(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										
									}
								}
								if(match(cmd, cmd_io2, cmd_io2_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_set_config_io2(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										
									}
								}
								if(match(cmd, cmd_io3, cmd_io3_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_set_config_io3(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										
									}
								}
								if(match(cmd, cmd_io4, cmd_io4_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_set_config_io4(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										
									}
								}
								if(match(cmd, cmd_adc0, cmd_adc0_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_set_config_adc0(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										
									}
								}
								if(match(cmd, cmd_adc1, cmd_adc1_size)){
									if(cmd->post!=nullptr){
										cmd=cmd->post;
										if(cmd->post!=nullptr){
											
											}else{
											if(!cmdHandler__io_set_config_adc1(CharArrayToInt(cmd))){
												parsed=true;
											}
										}
										}else{
										
									}
								}
							}else{
								if(!cmdHandler__io_set_config()){
									parsed=true;
								}
							}
						}
					}else{
						if(!cmdHandler__io_set()){
							parsed=true;
						}
					}
				}
			}else{
				if(!cmdHandler__io()){
					parsed=true;
				}
			}

		} 
	}
	

// 	if(parsed){
// 		serial_out0(ack);
// 	}else{
// 		serial_out0(nack);
// 	}

	
}
void cmdParser::set_parser_flag(){
	parser_flag=true;
}
bool cmdParser::get_parser_flag(){
	return parser_flag;
}
bool cmdParser::match(list_array_uint8_t_element* cmd,const uint8_t* B, uint8_t sizeB){
	if(cmd->data_size!=sizeB){
		return false;
	}
	uint8_t* A=cmd->data;
	for(uint8_t i=0;i<sizeB;i++){
		if(A[i]!=pgm_read_byte(B+i)){
			return false;
		}
	}
	return true;
}
int16_t CharArrayToInt(list_array_uint8_t_element* array){
int16_t result=0;
bool negFlag=false;
	for(uint8_t i=1; i <= array->data_size; i++){
		if(array->data[array->data_size-i]=='-'){
			negFlag=true;
		}else{
			if(array->data[array->data_size-i]>='0' && array->data[array->data_size-i]<='9'){
				if(i==1){
					result += (array->data[array->data_size-i] - '0');
				}else if(i==2){
					result += (array->data[array->data_size-i] - '0') * 10;
				}else if(i==3){
					result += (array->data[array->data_size-i] - '0') * 100;
				}else if(i==4){
					result += (array->data[array->data_size-i] - '0') * 1000;
				}else if(i==5){
					result += (array->data[array->data_size-i] - '0') * 10000;
				}else{
					return 0;
				}
			}
		}
	}
	if(negFlag){
		result*=-1;
	}
	
	return result;
}
list_array_uint8_t_element* intToCharArray(int16_t value){
	return intToCharArray(nullptr, value);
}
list_array_uint8_t_element* intToCharArray(list_array_uint8_t_element* pre, int16_t value){
	uint8_t result[6]={0,0,0,0,0,0};
	uint8_t cnt=0;
	if(value<0){
		value*=-1;
		result[cnt]='-';
		cnt++;
	}
	bool greater0=false;
	for(int16_t i=10000; i>0 && cnt<6; i/=10){
		uint8_t temp=value/i;
		if(temp>0){
			greater0=true;
		}
		if(greater0){
			value-=temp*i;
			result[cnt]='0' + temp;
			cnt++;
		}
		
	}
	if(cnt==0){
		result[cnt]='0';
		cnt++;
	}
	return new list_array_uint8_t_element(pre, result, cnt);
}
list_array_uint8_t_element* build_listElementFromProgmem(list_array_uint8_t_element* preElement, const uint8_t* inp, uint8_t inpSize){
	uint8_t temp[inpSize];
	for(uint8_t i=0;i<inpSize;i++){
		temp[i]=pgm_read_byte(inp+i);
	}
	return new list_array_uint8_t_element(preElement,temp,inpSize);
}