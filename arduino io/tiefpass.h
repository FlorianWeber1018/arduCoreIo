/*
 * tiefpass.h
 *
 * Created: 22.10.2017 18:29:10
 *  Author: Flo
 */ 
#ifndef TIEFPASS_H_
#define TIEFPASS_H_


#include <inttypes.h>

#define Ntap 11
#define DCgain 262144

class iirlowpass{
	public:
		int16_t sample(int16_t input);
		iirlowpass();
		~iirlowpass();
	private:
		 const int16_t FIRCoef[Ntap] = {
			 22780,
        23402,
        23896,
        24252,
        24469,
        24541,
        24469,
        24252,
        23896,
        23402,
        22780
		 };
		 int16_t* x;

};




#endif /* TIEFPASS_H_ */