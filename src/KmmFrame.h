#if !defined(__KmmFrame_H__)
#define __KmmFrame_H__

#include <stdint.h>
#include "KmmBody.h"

namespace kmm
{
    class KmmFrame {
    public:
        KmmFrame(KmmBody* kmmBody);
        uint16_t toBytes(uint8_t *contents);
    private:
        KmmBody* m_kmmBody;
    };
}

#endif