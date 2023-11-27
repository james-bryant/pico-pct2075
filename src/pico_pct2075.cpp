#include <stdio.h>

#include "pico_pct2075.h"

PCT2075::PCT2075(i2c_inst_t *i2c, uint8_t address) {
    this->i2c = i2c;
    this->address = address;
}

PCT2075::~PCT2075() {

}

float PCT2075::getTempurature() {
    uint8_t cmd = PCT2075_TEMP;
    while (i2c_write_blocking(i2c, address, &cmd, 1, true) <= 0) {
        printf("retrying i2c write command 0x%02x to 0x%02x\n", cmd, address);
    }

    while (i2c_write_blocking(i2c, address, &cmd, 1, true) <= 0) {
        printf("retrying i2c write command 0x%02x to 0x%02x\n", cmd, address);
    }

    uint8_t result[2];
    while (i2c_read_blocking(i2c, address, result, 2, false) <= 0) {
        printf("retrying i2c read 0x%02x\n", address);
    }

    uint16_t concatenate = (((result[0] << 8) | result[1]) >> 5);
    float temp;
    if(concatenate & 0x400u){
        concatenate = ((~concatenate) & 0x7FF) +1;
        temp = concatenate * -0.125;
    }else{
        temp = concatenate * 0.125;
    }
    return (float) temp;

}