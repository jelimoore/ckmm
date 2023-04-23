#include "ListKeysetTaggingInfo.h"

namespace kmm {
    InventoryCommandListKeysetTaggingInfo::InventoryCommandListKeysetTaggingInfo() :
    m_inventoryType(ListKeysetTaggingInfo)

    {
        m_messageId = InventoryCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryCommandListKeysetTaggingInfo::toBytes(uint8_t *contents) {
        return 0;
    }
}