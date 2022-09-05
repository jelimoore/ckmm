#include "KmmBody.h"

namespace kmm {
    KmmBody::KmmBody() :
    m_messageId((MessageID) 0),
    m_inventoryType((InventoryType) 0),
    m_responseKind((ResponseKind) 0)
    {
    }

    //virtual uint8_t KmmBody::toBytes(uint8_t *contents);
}