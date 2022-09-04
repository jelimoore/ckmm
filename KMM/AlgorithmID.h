#if !defined(__AlgorithmID_H__)
#define __AlgorithmID_H__

enum AlgorithmID {
    ACCORDION = 0x00,
    BATON_ODD = 0x01,
    FIREFLY = 0x02,
    MAYFLY = 0x03,
    SAVILLE = 0x04,
    PADSTONE = 0x05,
    BATON_EVEN = 0x41,
    CLEAR = 0x80,
    DESOFB = 0x81,
    TDES = 0x83,
    AES256 = 0x84,
    AES128 = 0x85,
    DESXL = 0x9F,
    DVIXL = 0xA0,
    DVPXL = 0xA1,
    ADP = 0xAA
};

#endif