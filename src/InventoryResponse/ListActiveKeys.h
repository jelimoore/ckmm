#if !defined(__InventoryResponseListActiveKeys_H__)
#define __InventoryResponseListActiveKeys_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "../InventoryType.h"
#include "../KmmBody.h"
#include "../KeyInfo.h"

namespace kmm
{
    class InventoryResponseListActiveKeys : public KmmBody {
    public:
        InventoryResponseListActiveKeys();
        uint32_t m_inventoryMarker;
        uint16_t m_maxKeysRequested;
        uint16_t m_numItems;
        KeyInfo* m_keys[256];
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    private:
        InventoryType m_inventoryType;
    };
}

#endif