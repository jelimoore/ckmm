#if !defined(__InventoryCommandListActiveKeys_H__)
#define __InventoryCommandListActiveKeys_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "../InventoryType.h"
#include "../KmmBody.h"

namespace kmm
{
    class InventoryCommandListActiveKeys : public KmmBody {
    public:
        InventoryCommandListActiveKeys();
        uint32_t m_inventoryMarker;
        uint32_t m_numItems;
        uint32_t m_maxKeysRequested;
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    private:
        InventoryType m_inventoryType;
    };
}

#endif
