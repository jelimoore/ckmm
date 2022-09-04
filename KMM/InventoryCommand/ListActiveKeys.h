#if !defined(__ListActiveKeys_H__)
#define __ListActiveKeys_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "InventoryType.h"
#include "../KmmBody.h"

namespace kmm
{
    class InventoryCommandListActiveKeys : KmmBody {
    public:
        InventoryCommandListActiveKeys();
        MessageID m_messageId;
        InventoryType m_inventoryType;
        ResponseKind m_responseKind;
        uint32_t m_inventoryMarker;
        uint16_t m_maxKeysRequested;
        uint8_t toBytes(uint8_t *contents);
    };
}

#endif