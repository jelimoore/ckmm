#include "ZeroizeCommand.h"

namespace kmm {
    ZeroizeCommand::ZeroizeCommand() :
    m_messageId(ZeroizeCommand_ID),
    m_responseKind(Immediate)
    {
    }

    uint8_t ZeroizeCommand::toBytes(uint8_t *contents) {
        contents[0] = m_messageId;
        return 1;
    }

}