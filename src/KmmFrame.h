#if !defined(__KmmFrame_H__)
#define __KmmFrame_H__

#include <stdint.h>
#include "KmmBody.h"
#include "MessageID.h"
#include "ZeroizeResponse.h"
#include "InventoryType.h"

#include "RekeyAcknowledgement.h"
#include "ZeroizeCommand.h"
#include "InventoryResponse/ListActiveKeys.h"

namespace kmm
{
    class KmmFrame {
    public:
        KmmFrame(KmmBody* bodyIn);
        KmmFrame(bool preamble, uint8_t *contents);
        uint16_t toBytes(uint8_t *contents);
        KmmBody* parse(uint8_t *contents);
        KmmBody* kmmBody;
    private:
    };
}

#endif