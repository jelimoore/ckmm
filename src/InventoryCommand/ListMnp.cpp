#include "ListMnp.h"

namespace kmm {
    InventoryCommandListMnp::InventoryCommandListMnp() :
    m_inventoryType(ListMnp)
    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListMnp::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }

    uint8_t InventoryCommandListMnp::parse(uint8_t *contents, uint16_t length) {
        return 0;
    }
}