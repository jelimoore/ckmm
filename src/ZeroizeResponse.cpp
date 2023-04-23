#include "ZeroizeResponse.h"

namespace kmm {
    ZeroizeResponse::ZeroizeResponse()
    {
        m_messageId = ZeroizeResponse_ID;
        m_responseKind = Immediate;
    }

    uint8_t ZeroizeResponse::toBytes(uint8_t *contents) {
        return 0;
    }

    uint8_t ZeroizeResponse::parse(uint8_t *contents) {
        return 0;
    }

}