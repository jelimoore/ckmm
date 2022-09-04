#include "ListActiveKeys.h"

namespace kmm {
    InventoryCommandListActiveKeys::InventoryCommandListActiveKeys() :
    m_messageId(InventoryResponse),
    m_inventoryType(ListActiveKeys),
    m_responseKind(None),
    m_numKeys(0),
//TODO: add key info list
    {
    }

    uint8_t InventoryCommandListActiveKeys::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;

        contents[1] = (m_inventoryMarker >> 16) & 0xFF;
        contents[2] = (m_inventoryMarker >> 8) & 0xFF;
        contents[3] = (m_inventoryMarker) & 0xFF;

        contents[4] = (m_maxKeysRequested >> 8) & 0xFF;
        contents[5] = (m_maxKeysRequested) & 0xFF;

        return 0;
    }
}