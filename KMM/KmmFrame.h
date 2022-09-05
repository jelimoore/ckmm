#if !defined(__KmmFrame_H__)
#define __KmmFrame_H__

#include <stdint.h>
#include "MessageID.h"
#include "AlgorithmID.h"
#include "KmmBody.h"

namespace kmm
{
    class KmmFrame {
    public:
        KmmFrame(kmm::KmmBody body);
        uint16_t toBytes(uint8_t *contents);
        uint16_t toBytesWithPreamble(uint8_t *contents, uint8_t mfid);
    private:
        kmm::KmmBody m_body;
        uint16_t m_frameLen;
    };
}

#endif