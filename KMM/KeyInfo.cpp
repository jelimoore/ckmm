#include "KeyInfo.h"

namespace kmm {
    KeyInfo::KeyInfo() :
    m_keysetId(0),
    m_sln(0),
    m_kid(0),
    m_algid(CLEAR)
    {
    }

    uint8_t KeyInfo::toBytes(uint8_t *contents) {
        contents[0] = m_keysetId;

        contents[1] = (m_sln >> 8);
        contents[2] = m_sln;

        contents[3] = m_algid;

        contents[4] = (m_kid >> 8);
        contents[5] = m_kid;
        return 6;
    }

    uint8_t KeyInfo::parse(uint8_t *contents) {
        // TODO: check len>6

        m_keysetId = contents[0];

        m_sln |= contents[1] << 8;
        m_sln |= contents[2];

        m_algid = (AlgorithmID) contents[3];

        m_kid |= contents[4] << 8;
        m_kid |= contents[5];
        return 0;
    }
}