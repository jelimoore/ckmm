#include "KeyStatus.h"

namespace kmm {
    KeyStatus::KeyStatus() :
    m_algid(0),
    m_kid(0),
    m_status(0)
    {
        //
    }

    uint8_t KeyStatus::toBytes(uint8_t *contents) {
        contents[0] = m_algid;
        contents[1] = m_kid >> 8;
        contents[2] = m_kid;
        contents[3] = m_status;
        return 4;
    }

    uint8_t KeyStatus::parse(uint8_t *contents) {
        m_algid = contents[0];

        m_kid = 0;
        m_kid |= contents[1] << 8;
        m_kid |= contents[2];

        m_status = contents[3];
        return 0;
    }
}