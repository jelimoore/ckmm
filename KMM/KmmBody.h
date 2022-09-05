#if !defined(__KmmBody_H__)
#define __KmmBody_H__

#include <stdint.h>
#include "MessageID.h"
#include "ResponseKind.h"
#include "InventoryCommand/InventoryType.h"

namespace kmm
{
    class KmmBody {
    public:
        KmmBody();
        MessageID m_messageId;
        InventoryType m_inventoryType;
        ResponseKind m_responseKind;
        virtual uint8_t toBytes(uint8_t *contents);
    };
}

#endif