#include "ListActiveKeysetIds.h"

namespace kmm {
    InventoryCommandListActiveKeysetIds::InventoryCommandListActiveKeysetIds() :
    m_inventoryType(ListActiveKsetIds)
    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListActiveKeysetIds::toBytes(uint8_t *contents) {
        return 0;
    }
}