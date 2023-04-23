#if !defined(__CRC16_H__)
#define __CRC16_H__

#include <stdint.h>

uint16_t calculateFrameCrc16(uint8_t *val, uint8_t inLen);

#endif