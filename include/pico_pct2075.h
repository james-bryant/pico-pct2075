#ifndef __PICO_PCT2075_H__
#define __PICO_PCT2075_H__

#include "hardware/i2c.h"

/*
Temperature register:
Read only
POR state 0x0000
*/
#define PCT2075_TEMP 	0x00u /**< Contains two 8-bit data bytes to store the measured Temp data.*/
/*
Configuration register:
R/W
POR state 0x00
*/
#define PCT2075_CONF 	0x01u /**< Contains a single 8-bit data byte to set the device operating condition.*/
/*
Hysteresis register:
R/W
POR state 0x4B00
*/
#define PCT2075_THYST 	0x02u /**< contains two 8-bit data bytes to store the hysteresis This limit; default is 75ºC.*/
/*
Overtemperature shutdown threshold register:
R/W
POR state 0x5000
*/
#define PCT2075_TOS		0x03u /**< Contains two 8-bit data bytes to store the overtemperature shutdown Tots limit; default is 80ºC*/
/*
R/W
POR state 0x00
*/
#define PCT2075_TIDLE 	0x04u /**< Temperature conversion cycle default to 100 ms.*/

// Configuration Register
#define PCT2075_CONF_OS_F_QUE_BIT 	        4u
#define PCT2075_CONF_OS_F_QUE_BIT_LENGHT    2u
#define PCT2075_CONF_OS_POL_BIT 	        2u
#define PCT2075_CONF_OS_COMP_INT_BIT 	    1u
#define PCT2075_CONF_SHUTDOWN_BIT 	        0u

#define PCT2075_QUEUE_VAL_1		0x00u
#define PCT2075_QUEUE_VAL_2		0x01u
#define PCT2075_QUEUE_VAL_4		0x10u
#define PCT2075_QUEUE_VAL_6		0x11u
#define PCT2075_OS_POL_ACTIVE_LOW	0u
#define PCT2075_OS_POL_ACTIVE_HIGH	1u
#define PCT2075_OS_COMPARATOR_OPERATION	0u
#define PCT2075_OS_INTERRUPT_OPERATION	1u
#define PCT2075_NORMAL_MODE		0u
#define PCT2075_SHUTDOWN_MODE		1u

class PCT2075
{
private:
    i2c_inst_t *i2c;
    uint8_t address;

    

public:

    PCT2075(i2c_inst_t *i2c, uint8_t address);
    ~PCT2075();

    float getTempurature();

};

#endif // __PICO_PCT2075_H__