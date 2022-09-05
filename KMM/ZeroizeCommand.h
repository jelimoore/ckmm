#if !defined(__ZeroizeCommand_H__)
#define __ZeroizeCommand_H__

#include <stdint.h>
#include "MessageID.h"
#include "ResponseKind.h"
#include "KmmBody.h"

namespace kmm
{
    class ZeroizeCommand : public KmmBody {
    public:
        ZeroizeCommand();
        uint8_t toBytes(uint8_t *contents);
        MessageID m_messageId;
        ResponseKind m_responseKind;
    private:
    };
}

#endif