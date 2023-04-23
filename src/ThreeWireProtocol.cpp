#include "ThreeWireProtocol.h"
#include <catch2/catch_test_macros.hpp>

uint16_t kmmCreateKmmFrame(kmm::KmmFrame *inFrame, uint8_t *outFrame) {
    uint8_t inBytes[512];
    uint16_t inLen = inFrame->toBytes(inBytes);
    uint16_t bodyLength = inLen + 6;
    uint8_t bodyBytes[bodyLength];
    uint16_t totalLen = bodyLength + 3;
    
    /* KMM opcode */
    outFrame[0] = OPCODE_KMM;

    /* frame len */
    outFrame[1] = (bodyLength >> 8) & 0xFF;
    outFrame[2] = bodyLength & 0xFF;

    /* control opcode */
    bodyBytes[0] = 0x00;

    /* dest RSI */
    bodyBytes[1] = 0xFF;
    bodyBytes[2] = 0xFF;
    bodyBytes[3] = 0xFF;

    // copy the frame bytes to the body
    for (int i=0; i<inLen; i++) {
        bodyBytes[4+i] = inBytes[i];
    }

    // copy the body into the main frame
    for (int i=0; i<bodyLength; i++) {
        outFrame[3+i] = bodyBytes[i];
    }

    // crc just the body
    uint16_t crc = kmmCalculateFrameCrc16(bodyBytes, inLen + 4);

    outFrame[totalLen - 2] = crc & 0xFF;
    outFrame[totalLen - 1] = crc >> 8;
    return totalLen;
}