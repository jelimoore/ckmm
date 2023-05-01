#include "KmmFrame.h"

namespace kmm {
    KmmFrame::KmmFrame(KmmBody* bodyIn)
    {
        kmmBody = bodyIn;
    }

    KmmFrame::KmmFrame(bool preamble, uint8_t *contents) {
        if (preamble) {
            //
        } else {
            kmmBody = parse(contents);
        }
    }

    uint16_t KmmFrame::toBytes(uint8_t *contents) {
        uint8_t bodyBytes[512];
        uint8_t bodyLen = kmmBody->toBytes(bodyBytes);
        uint8_t frameLen = 10 + bodyLen;
        uint8_t messageLen = 7 + bodyLen;

        /* message ID */
        contents[0] = kmmBody->m_messageId;

        /* message length */
        contents[1] = (messageLen >> 8) & 0xFF;
        contents[2] = messageLen & 0xFF;

        /* message format */
        contents[3] = 0x00;
        contents[3] |= (kmmBody->m_responseKind & 0x02) << 6;

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

    KmmBody* KmmFrame::parse(uint8_t *contents) {
        KmmBody* body;
        uint8_t messageId = contents[0];
        uint16_t bodyLen = 0;
        bodyLen |= (contents[1] << 8);
        bodyLen |= contents[2];
        uint8_t messageBody[bodyLen - 7];

        for (int i=0; i<bodyLen - 7; i++) {
            messageBody[i] = contents[i+10];
        }

        if (messageId == InventoryCommand_ID) {
            return 0;
        } else if (messageId == InventoryResponse_ID) {
            uint8_t inventoryType = messageBody[0];
            
            if (inventoryType == ListActiveKeys) {
                body = new InventoryResponseListActiveKeys();
                body->parse(messageBody);
            } else {
                return 0;
            }
        } else if (messageId == ZeroizeResponse_ID) {
            body = new ZeroizeResponse();
            body->parse(messageBody);
        } else {
            return 0;
        }
        return body;
    }

}