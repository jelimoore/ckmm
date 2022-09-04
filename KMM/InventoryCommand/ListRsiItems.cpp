#include "ListRsiItems.h"

namespace kmm {
    InventoryCommandListRsiItems::InventoryCommandListRsiItems() :
    m_messageId(InventoryCommand),
    m_inventoryType(ListRsiItems),
    m_responseKind(Immediate)
    {
    }

    uint8_t InventoryCommandListRsiItems::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 0;
    }
}