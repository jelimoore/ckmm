#if !defined(__ModifyKeyCommand_H__)
#define __ModifyKeyCommand_H__

#include <stdint.h>
#include "KmmBody.h"
#include "KeyItem.h"

namespace kmm
{
    class ModifyKeyCommand : public KmmBody {
    public:
        ModifyKeyCommand();
        uint8_t m_ksetId;
        uint8_t m_algid;
        kmm::KeyItem *m_keyItem;
        uint8_t toBytes(uint8_t *contents);
        uint8_t parse(uint8_t *contents, uint16_t length);
    };
}

#endif