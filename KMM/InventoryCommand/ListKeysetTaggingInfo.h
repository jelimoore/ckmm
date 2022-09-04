#if !defined(__ListKeysetTaggingInfo_H__)
#define __ListKeysetTaggingInfo_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "InventoryType.h"
#include "../KmmBody.h"

namespace kmm
{
    class InventoryCommandListKeysetTaggingInfo : KmmBody {
    public:
        InventoryCommandListKeysetTaggingInfo();
        uint8_t toBytes(uint8_t *contents);
    private:
        MessageID m_messageId;
        InventoryType m_inventoryType;
        ResponseKind m_responseKind;
    };
}

#endif