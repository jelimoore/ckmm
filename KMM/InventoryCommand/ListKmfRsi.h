#if !defined(__ListKmfRsi_H__)
#define __ListKmfRsi_H__

#include <stdint.h>
#include "KMM/MessageID.h"
#include "KMM/ResponseKind.h"
#include "InventoryType.h"

namespace kmm
{
    class InventoryCommandListKmfRsi {
    public:
        InventoryCommandListKmfRsi();
        MessageID m_messageId;
        InventoryType m_inventoryType;
        ResponseKind m_responseKind;
        uint8_t toBytes(uint8_t *contents);
    };
}

#endif