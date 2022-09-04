#if !defined(__ListMnp_H__)
#define __ListMnp_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "InventoryType.h"
#include "../KmmBody.h"

namespace kmm
{
    class InventoryCommandListMnp : KmmBody {
    public:
        InventoryCommandListMnp();
        MessageID m_messageId;
        InventoryType m_inventoryType;
        ResponseKind m_responseKind;
        uint8_t toBytes(uint8_t *contents);
    };
}

#endif