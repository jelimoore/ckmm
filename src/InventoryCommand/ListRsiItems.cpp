#include "ListRsiItems.h"

namespace kmm {
    InventoryCommandListRsiItems::InventoryCommandListRsiItems() :
    m_inventoryType(ListRsiItems)
    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListRsiItems::toBytes(uint8_t *contents) {
        return 0;
    }
}