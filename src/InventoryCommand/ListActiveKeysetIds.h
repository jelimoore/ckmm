#if !defined(__ListActiveKeysetIds_H__)
#define __ListActiveKeysetIds_H__

#include <stdint.h>
#include "../MessageID.h"
#include "../ResponseKind.h"
#include "../InventoryType.h"
#include "../KmmBody.h"

namespace kmm
{
    class InventoryCommandListActiveKeysetIds : public KmmBody {
    public:
        InventoryCommandListActiveKeysetIds();
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents);
    private:
        InventoryType m_inventoryType;
    };
}

#endif