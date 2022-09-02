#include "ListActiveKeys.h"

namespace kmm {
    InventoryCommandListActiveKeys::InventoryCommandListActiveKeys() :
    m_messageId(InventoryCommand),
    m_inventoryType(ListActiveKeys),
    m_responseKind(Immediate),
    m_inventoryMarker(0),
    m_maxKeysRequested(0)
    {
    }

    uint8_t* InventoryCommandListActiveKeys::toByes() {
        uint8_t contents[6];
        contents[0] = m_inventoryType;

        contents[1] = (m_inventoryMarker >> 16) & 0xFF;
        contents[2] = (m_inventoryMarker >> 8) & 0xFF;
        contents[3] = (m_inventoryMarker) & 0xFF;

        contents[4] = (m_maxKeysRequested >> 8) & 0xFF;
        contents[5] = (m_maxKeysRequested) & 0xFF;

        return contents;
    }
}