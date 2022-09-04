#include "ZeroizeResponse.h"

namespace kmm {
    ZeroizeResponse::ZeroizeResponse() :
    m_messageId(ZeroizeResponse_ID),
    m_responseKind(Immediate)
    {
    }

    uint8_t ZeroizeResponse::toBytes(uint8_t *contents) {
        return 0;
    }

}