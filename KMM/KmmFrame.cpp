#include "KmmFrame.h"

namespace kmm {
    KmmFrame::KmmFrame(kmm::KmmBody* body) :
    m_body(body)
    {
    }

    uint16_t KmmFrame::toBytes(uint8_t *contents) {
        uint8_t temp[256];
        uint8_t bodyLen = m_body->toBytes(temp);
        uint8_t messageLen = 7 + bodyLen;

        contents[0] = m_body->m_messageId;

        contents[1] = (messageLen >> 8) & 0xFF; // len hi
        contents[2] = messageLen & 0xFF; // len lo
        
        contents[3] = 0x00; // responseKind
        //TODO: clean this section up
        if ((m_body->m_responseKind & 0x02) >> 1) {
            contents[3] |= 0b10000000;
        }

        if (m_body->m_responseKind & 0x01) {
            contents[3] |= 0b01000000;
        }

        /* destination rsi */
        contents[4] = 0xFF;
        contents[5] = 0xFF;
        contents[6] = 0xFF;

        /* source rsi */
        contents[7] = 0xFF;
        contents[8] = 0xFF;
        contents[9] = 0xFF;

        for (int i=0; i<bodyLen; i++) {
            contents[10+i] = temp[i];
        }

        return 10 + bodyLen;
    }

    uint16_t KmmFrame::toBytesWithPreamble(uint8_t *contents, uint8_t mfid) {
        contents[0] = 0;    // version
        
        contents[1] = mfid; // MFID

        contents[2] = CLEAR; // algid; hardcoded to clear for now

        contents[3] = 0x00;  // key ID
        contents[4] = 0x00;  // key ID

        contents[5] = 0x00;  // MI
        contents[6] = 0x00;  // MI
        contents[7] = 0x00;  // MI
        contents[8] = 0x00;  // MI
        contents[9] = 0x00;  // MI
        contents[10] = 0x00;  // MI
        contents[11] = 0x00;  // MI
        contents[12] = 0x00;  // MI
        contents[13] = 0x00;  // MI

        uint8_t temp[256];
        uint8_t len = this->toBytes(temp);

        for (int i=0; i<len; i++) {
            contents[14+i] = temp[i];

        }

        return 14+len;
    }
}