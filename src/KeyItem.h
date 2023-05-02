#if !defined(__KeyItem_H__)
#define __KeyItem_H__

#include <stdint.h>

namespace kmm
{
    class KeyItem {
    public:
        KeyItem();
        //~KeyItem();
        uint16_t m_sln;
        uint16_t m_kid;
        uint8_t* m_key;
        uint8_t m_keyLen;
        bool m_kek;
        bool m_erase;
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    };
}

#endif