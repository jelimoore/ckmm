#include "ModifyKeyCommand.h"

namespace kmm {
    ModifyKeyCommand::ModifyKeyCommand()
    {
        m_messageId = ModifyKeyCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t ModifyKeyCommand::toBytes(uint8_t *contents) {
        uint8_t keyLen = m_keyItem->m_keyLen;
        uint8_t keyBytes[keyLen + 5];

        // decryption instructions
        contents[0] = 0x00;

        // extended decryption instructions
        contents[1] = 0x00;

        // algid
        contents[2] = 0x80;

        //key ID
        contents[3] = 0x00;
        contents[4] = 0x00;

        contents[5] = m_ksetId;
        contents[6] = m_algid;
        contents[7] = keyLen;               // key length
        contents[8] = 1;                    // count

        uint8_t keyBytesLen = m_keyItem->toBytes(keyBytes);

        for (int i=0; i<keyBytesLen; i++) {
            contents[9+i] = keyBytes[i];
        }

        return keyBytesLen + 9;
    }

    uint8_t ModifyKeyCommand::parse(uint8_t *contents, uint16_t length) {

    }
}