#include "ListMnp.h"

namespace kmm {
    InventoryCommandListMnp::InventoryCommandListMnp() :
    m_messageId(InventoryCommand_ID),
    m_inventoryType(ListMnp),
    m_responseKind(Immediate)
    {
    }

    uint8_t InventoryCommandListMnp::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }
}