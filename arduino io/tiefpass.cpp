/*
 * tiefpass.cpp
 *
 * Created: 22.10.2017 18:28:58
 *  Author: Flo
 */ 
 #include "tiefpass.h"
 #include <stdlib.h>
int16_t iirlowpass::sample(int16_t NewSample){
	 //shift the old samples
	 int32_t y=0;
	 for(uint8_t n=Ntap-1; n>0; n--){
		x[n] = x[n-1];
	 }

	  x[0] = NewSample;
	  for(uint8_t n=0; n<Ntap; n++){
			y += (int32_t)FIRCoef[n] * (int32_t)x[n];
	  }
	 
	  
	  return y>>18;

}
iirlowpass::iirlowpass(){

	x=(int16_t*)malloc(2*(Ntap));
	
};
iirlowpass::~iirlowpass(){
	free(x);

}