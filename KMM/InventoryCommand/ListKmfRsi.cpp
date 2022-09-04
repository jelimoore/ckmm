#include "ListKmfRsi.h"

namespace kmm {
    InventoryCommandListKmfRsi::InventoryCommandListKmfRsi() :
    m_messageId(InventoryCommand_ID),
    m_inventoryType(ListKmfRsi),
    m_responseKind(Immediate)
    {
    }

    uint8_t InventoryCommandListKmfRsi::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }
}