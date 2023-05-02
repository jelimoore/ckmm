#include "ListActiveKeys.h"
#include <Arduino.h>

namespace kmm {
    InventoryResponseListActiveKeys::InventoryResponseListActiveKeys() :
    m_inventoryType(ListActiveKeys),
    m_inventoryMarker(0),
    m_numItems(0)
    {
        m_messageId = InventoryResponse_ID;
        m_responseKind = Immediate;
    }

    uint8_t InventoryResponseListActiveKeys::toBytes(uint8_t *contents) {
        // not implemented

        return 0;
    }

    uint8_t InventoryResponseListActiveKeys::parse(uint8_t *contents, uint16_t length) {
        if (contents[0] != m_inventoryType) {
            return 0;
        }

        m_inventoryMarker |= contents[1] << 16;
        m_inventoryMarker |= contents[2] << 8;
        m_inventoryMarker |= contents[3];

        m_numItems |= contents[4] << 8;
        m_numItems |= contents[5];

        if (m_numItems == 0) {
            return 0;
        } else if (((m_numItems * 6) % (length - 6)) == 0) {
            for (int i=0; i<m_numItems; i++) {
                uint8_t temp[6];

                for (int j=0; j<6; j++) {
                    temp[j] = contents[6 + (i * 6) + j];
                }

                KeyInfo* info = new KeyInfo();
                info->parse(temp);
                m_keys[i] = info;
            }
            return m_numItems;
        } else {
            return 0;
        }


    }
}