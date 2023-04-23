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

}