#include "ListKeysetTaggingInfo.h"

namespace kmm {
    InventoryCommandListKeysetTaggingInfo::InventoryCommandListKeysetTaggingInfo() :
    m_messageId(InventoryCommand),
    m_inventoryType(ListKeysetTaggingInfo),
    m_responseKind(Immediate)
    {
    }

    uint8_t InventoryCommandListKeysetTaggingInfo::toBytes(uint8_t *contents) {
        contents[0] = m_inventoryType;
        return 1;
    }
}