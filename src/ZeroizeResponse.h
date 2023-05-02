#if !defined(__ZeroizeResponse_H__)
#define __ZeroizeResponse_H__

#include <stdint.h>
#include "MessageID.h"
#include "ResponseKind.h"
#include "KmmBody.h"

namespace kmm
{
    class ZeroizeResponse : public KmmBody {
    public:
        ZeroizeResponse();
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    };
}

#endif