#include "ListActiveKeysetIds.h"

namespace kmm {
    InventoryCommandListActiveKeysetIds::InventoryCommandListActiveKeysetIds() :
    m_messageId(InventoryCommand_ID),
    m_inventoryType(ListActiveKsetIds),
    m_responseKind(Immediate)
    {
    }

    uint8_t InventoryCommandListActiveKeysetIds::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }
}