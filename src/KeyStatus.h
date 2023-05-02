#if !defined(__KeyStatus_H__)
#define __KeyStatus_H__

#include <stdint.h>

#include "AlgorithmID.h"

namespace kmm
{
    class KeyStatus{
    public:
        KeyStatus();
        uint16_t m_kid;
        uint8_t m_status;
        uint8_t m_algid;
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents);
    };
}

#endif