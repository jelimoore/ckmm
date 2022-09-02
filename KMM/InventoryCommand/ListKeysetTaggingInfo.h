#if !defined(__ListKeysetTaggingInfo_H__)
#define __ListKeysetTaggingInfo_H__

#include <stdint.h>
#include "KMM/MessageID.h"
#include "KMM/ResponseKind.h"
#include "InventoryType.h"
#include "KMM/KmmBody.h"

namespace kmm
{
    class InventoryCommandListKeysetTaggingInfo : KmmBody {
    public:
        InventoryCommandListKeysetTaggingInfo();
        MessageID m_messageId;
        InventoryType m_inventoryType;
        ResponseKind m_responseKind;
        uint8_t toBytes(uint8_t *contents);
    };
}

#endif