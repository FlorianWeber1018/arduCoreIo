/*
 * COMprotocol.h
 *
 * Created: 09.10.2017 21:16:22
 *  Author: Flo
 */ 


#ifndef PROTKOLDEF_H_
#define PROTKOLDEF_H_
	#include <avr/pgmspace.h>

	#ifndef nullptr
	#define nullptr NULL
	#endif

	#define eot 13			//End of Transmission
// 	#define ack 10			//wenn befehl komplett geparst wurde		(antwort arduino->pi)
// 	#define nack 21			//wenn befehl nicht komplett geparst wurde
	#define space 32		//leerzeichen
// 	const uint8_t ioDescript[] = {'m', 'o', 'd'}					//// wird eigentlich nicht benötigt da das modul bereits über die usb id identifiziert ist
// 	#define ioDescript_size 3
// 	const uint8_t ioId[] = {'0'}
// 	#define ioId_size 1
	const uint8_t cmd_freeMem[] PROGMEM = {'f','r','e','e','M','e','m'};
	#define cmd_freeMem_size 7
	const uint8_t cmd_set[] PROGMEM = {'s','e','t'};
	#define cmd_set_size 3
	const uint8_t cmd_get[] PROGMEM = {'g','e','t'};
	#define cmd_get_size 3
	const uint8_t cmd_io[] PROGMEM = {'i','o'};
	#define cmd_io_size 2
	const uint8_t cmd_state[] PROGMEM = {'s','t','a','t','e'};
	#define cmd_state_size 5
	const uint8_t cmd_all[] PROGMEM = {'a','l','l'};
	#define cmd_all_size 3
	const uint8_t cmd_pt2000[] PROGMEM = {'p','t','2','0','0','0'};
	#define cmd_pt2000_size 6
	const uint8_t cmd_direct[] PROGMEM = {'d','i','r','e','c','t'};
	#define cmd_direct_size 6
	const uint8_t cmd_tp0[] PROGMEM = {'t','p','0'};
	#define cmd_tp0_size 3
	const uint8_t cmd_notp[] PROGMEM = {'n','o','t','p'};
	#define cmd_notp_size 4
	const uint8_t cmd_config[] PROGMEM = {'c','o','n','f','i','g'};
	#define cmd_config_size 6
	const uint8_t cmd_value[] PROGMEM = {'v','a','l','u','e'};
	#define cmd_value_size 5
	const uint8_t cmd_io0[] PROGMEM = {'i','o','0'};
	#define cmd_io0_size 3
	const uint8_t cmd_io1[] PROGMEM = {'i','o','1'};
	#define cmd_io1_size 3
	const uint8_t cmd_io2[] PROGMEM = {'i','o','2'};
	#define cmd_io2_size 3
	const uint8_t cmd_io3[] PROGMEM = {'i','o','3'};
	#define cmd_io3_size 3
	const uint8_t cmd_io4[] PROGMEM = {'i','o','4'};
	#define cmd_io4_size 3
	const uint8_t cmd_adc0[] PROGMEM = {'a','d','c','0'};
	#define cmd_adc0_size 4
	const uint8_t cmd_adc1[] PROGMEM = {'a','d','c','1'};
	#define cmd_adc1_size 4
	const uint8_t cmd_true[] PROGMEM = {'t','r','u','e'};
	#define cmd_true_size 4
	const uint8_t cmd_false[] PROGMEM = {'f','a','l','s','e'};
	#define cmd_false_size 5


#endif /* PROTKOLDEF_H_ */