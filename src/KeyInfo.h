#if !defined(__KeyInfo_H__)
#define __KeyInfo_H__

#include <stdint.h>

#include "AlgorithmID.h"

namespace kmm
{
    class KeyInfo{
    public:
        KeyInfo();
        uint8_t m_keysetId;
        uint16_t m_sln;
        uint16_t m_kid;
        kmmAlgorithmID m_algid;
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents);
    };
}

#endif