#include "ThreeWireProtocol.h"

uint16_t twpCreateKmmFrame(uint8_t *inFrame, uint16_t inLen, uint8_t *outFrame) {
    uint16_t length = inLen + 6;
    uint16_t totalLen = length + 3;
    
    /* KMM opcode */
    outFrame[0] = OPCODE_KMM;

    /* frame len */
    outFrame[1] = (length >> 8) & 0xFF;
    outFrame[2] = length & 0xFF;

    /* control opcode */
    outFrame[3] = 0x00;

    /* dest RSI */
    outFrame[4] = 0xFF;
    outFrame[5] = 0xFF;
    outFrame[6] = 0xFF;

    for (int i=0; i<inLen; i++) {
        outFrame[7+i] = inFrame[i];
    }

    uint16_t crc = calculateFrameCrc16(outFrame, totalLen - 2);

    outFrame[totalLen - 2] = crc & 0xFF;
    outFrame[totalLen - 1] = crc >> 8;
    return totalLen;
}