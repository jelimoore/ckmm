#include "RekeyAcknowledgement.h"

namespace kmm {
    RekeyAcknowledgement::RekeyAcknowledgement()
    {
        m_messageId = RekeyAcknowledgement_ID;
        m_responseKind = None;
    }

    uint8_t RekeyAcknowledgement::toBytes(uint8_t *contents) {
        contents[0] = m_midAck;
        contents[1] = m_numItems;

        uint8_t statusBytes[4];
        uint8_t statusLen = m_keyStatus.toBytes(statusBytes);

        for (int i=0; i<statusLen; i++) {
            contents[i+2] = statusBytes[i];
        }
    }

    uint8_t RekeyAcknowledgement::parse(uint8_t *contents, uint16_t length) {
        m_midAck = contents[0];
        m_numItems = contents[1];

        if (m_numItems == 0) {
            return 0;
        } else if (((m_numItems * 4) % (length - 2)) == 0) {
            for (int i=0; i<m_numItems; i++) {
                uint8_t status[4];
                for (int j=0; j<4; j++) {
                    status[j] = contents[2 + (i*4) + j];
                }
                KeyStatus status2;
                status2.parse(status);
                //TODO: make this accept multiple
                m_keyStatus = status2;
            }
            return 0;
        } else {
            return 1;
        }
    }

}