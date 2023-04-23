#if !defined(__ThreeWireProtocol_H__)
#define __ThreeWireProtocol_H__

#include <stdint.h>
#include "CRC16.h"
#include "ckmm.h"

#define OPCODE_READY_REQ 0xC0
#define OPCODE_READY_GENERAL_MODE 0xD0
#define OPCODE_TRANSFER_DONE 0xC1
#define OPCODE_KMM 0xC2
#define OPCODE_DISCONNECT_ACK 0x90
#define OPCODE_DISCONNECT 0x92

uint16_t kmmCreateKmmFrame(kmm::KmmFrame *inFrame, uint8_t *outFrame);

#endif