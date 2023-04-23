#if !defined(__KmmBody_H__)
#define __KmmBody_H__

#include <stdint.h>
#include "MessageID.h"
#include "ResponseKind.h"

namespace kmm
{
    class KmmBody {
    public:
        KmmBody();
        kmmMessageID m_messageId;
        kmmResponseKind m_responseKind;
        virtual uint8_t toBytes(uint8_t *contents) = 0;
        virtual uint8_t parse(uint8_t *contents) = 0;
    };
}

#endif