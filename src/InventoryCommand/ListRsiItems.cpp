#include "ListRsiItems.h"

namespace kmm {
    InventoryCommandListRsiItems::InventoryCommandListRsiItems() :
    m_inventoryType(ListRsiItems)
    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListRsiItems::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }

    uint8_t InventoryCommandListRsiItems::parse(uint8_t *contents) {
        return 0;
    }
}