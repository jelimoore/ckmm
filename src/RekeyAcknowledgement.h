#if !defined(__RekeyAcknowledgement_H__)
#define __RekeyAcknowledgement_H__

#include <stdint.h>
#include "MessageID.h"
#include "ResponseKind.h"
#include "KmmBody.h"
#include "KeyStatus.h"

namespace kmm
{
    class RekeyAcknowledgement : public KmmBody {
    public:
        RekeyAcknowledgement();
        uint8_t m_midAck;
        uint8_t m_numItems;
        KeyStatus m_keyStatus;
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    };
}

#endif