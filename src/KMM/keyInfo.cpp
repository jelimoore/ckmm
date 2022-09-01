
//#include "Defines.h"
using namespace keyinfo;

void KeyInfo::serialize(uint8_t& buf) {
    byte[] contents = new byte[6];

    /* keyset id */
    contents[0] = (byte)KeySetId;

    /* sln */
    contents[1] = (byte)(SLN >> 8);
    contents[2] = (byte)SLN;

    /* algorithm id */
    contents[3] = (byte)AlgorithmId;

    /* key id */
    contents[4] = (byte)(KeyId >> 8);
    contents[5] = (byte)KeyId;

    return contents;
}