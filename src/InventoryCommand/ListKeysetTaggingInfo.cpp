#include "ListKeysetTaggingInfo.h"

namespace kmm {
    InventoryCommandListKeysetTaggingInfo::InventoryCommandListKeysetTaggingInfo() :
    m_inventoryType(ListKeysetTaggingInfo)

    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListKeysetTaggingInfo::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }

    uint8_t InventoryCommandListKeysetTaggingInfo::parse(uint8_t *contents, uint16_t length) {
        return 0;
    }
}