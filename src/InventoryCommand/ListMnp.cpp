#include "ListMnp.h"

namespace kmm {
    InventoryCommandListMnp::InventoryCommandListMnp() :
    m_inventoryType(ListMnp)
    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListMnp::toBytes(uint8_t *contents) {
        return 0;
    }
}