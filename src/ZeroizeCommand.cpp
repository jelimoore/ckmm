#include "ZeroizeCommand.h"

namespace kmm {
    ZeroizeCommand::ZeroizeCommand() :
    KmmBody()
    {
        m_messageId = ZeroizeCommand_ID;
        m_responseKind = Immediate;
    }

    uint8_t ZeroizeCommand::toBytes(uint8_t *contents) {
        //contents[0] = 0;
        return 0;
    }

    uint8_t ZeroizeCommand::parse(uint8_t *contents, uint16_t length) {
        return 0;
    }

}