#include "KmmFrame.h"

namespace kmm {
    KmmFrame::KmmFrame(KmmBody* kmmBody)
    {
        m_kmmBody = kmmBody;
    }

    uint16_t KmmFrame::toBytes(uint8_t *contents) {
        uint8_t bodyBytes[512];
        uint8_t bodyLen = m_kmmBody->toBytes(bodyBytes);
        uint8_t frameLen = 10 + bodyLen;
        uint8_t messageLen = 7 + bodyLen;

        /* message ID */
        contents[0] = m_kmmBody->m_messageId;

        /* message length */
        contents[1] = (messageLen >> 8) & 0xFF;
        contents[2] = messageLen & 0xFF;

        /* message format */
        contents[3] = 0x00;
        contents[3] |= (m_kmmBody->m_responseKind & 0x02) << 6;

        /* destination rsi */
        contents[4] = 0xFF;
        contents[5] = 0xFF;
        contents[6] = 0xFF;

        /* source rsi */
        contents[7] = 0xFF;
        contents[8] = 0xFF;
        contents[9] = 0xFF;

        for (int i=0; i<bodyLen; i++) {
            contents[10+i] = bodyBytes[i];
        }

        return frameLen;
    }

    KmmBody* parse(uint8_t *contents) {
        KmmBody* body;
        uint8_t messageId = contents[0];
        uint16_t bodyLen = 0;
        bodyLen |= (contents[1] << 8);
        bodyLen |= contents[2];
        uint8_t messageBody[bodyLen];

        if (messageId == InventoryCommand_ID) {
            return 0;
        } else if (messageId == InventoryResponse_ID) {
            return 0;
        } else if (messageId == ZeroizeCommand_ID) {
            body = new ZeroizeResponse();
            body->parse(messageBody);
        } else {
            return 0;
        }
        return body;
    }

}