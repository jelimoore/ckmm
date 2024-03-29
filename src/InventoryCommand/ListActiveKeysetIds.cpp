#include "ListActiveKeysetIds.h"

namespace kmm {
    InventoryCommandListActiveKeysetIds::InventoryCommandListActiveKeysetIds() :
    m_inventoryType(ListActiveKsetIds)
    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListActiveKeysetIds::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }

    uint8_t InventoryCommandListActiveKeysetIds::parse(uint8_t *contents, uint16_t length) {
        return 0;
    }
}