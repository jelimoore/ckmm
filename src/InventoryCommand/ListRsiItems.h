#if !defined(__ListRsiItems_H__)
#define __ListRsiItems_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "../InventoryType.h"
#include "../KmmBody.h"

namespace kmm
{
    class InventoryCommandListRsiItems : public KmmBody {
    public:
        InventoryCommandListRsiItems();
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    private:
        InventoryType m_inventoryType;
    };
}

#endif