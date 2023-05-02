#include "KeyItem.h"

namespace kmm {
    KeyItem::KeyItem()
    {
        m_kek = false;
        m_erase = false;
    }
/*
    KeyItem::~KeyItem() {
        if (m_key != nullptr) {
            delete m_key;
        }
    }
*/
    uint8_t KeyItem::toBytes(uint8_t *contents) {
        uint8_t keyFormat = 0;
        if (m_kek) keyFormat |= 1 << 7;
        if (m_erase) keyFormat |= 1 << 5;
        contents[0] = keyFormat;

        contents[1] = m_sln >> 8;
        contents[2] = m_sln;
        
        contents[3] = m_kid >> 8;
        contents[4] = m_kid;

        for (int i=0; i<m_keyLen; i++) {
            contents[5+i] = m_key[i];
        }

        return 5 + m_keyLen;
    }

    uint8_t KeyItem::parse(uint8_t *contents, uint16_t length) {
        m_kek = (contents[0] & 0x80) == 1;
        m_erase = (contents[0] & 0x20) == 1;

        m_sln = contents[1] << 8;
        m_sln = contents[2];

        m_kid = contents[3] << 8;
        m_kid = contents[4];

        uint8_t keyLen = length - 5;
        m_key = new uint8_t[keyLen];

        for (int i=0; i<keyLen; i++) {
            m_key[i] = contents[5 + i];
        }

        return 0;
    }

}
