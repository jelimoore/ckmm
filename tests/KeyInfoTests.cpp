#include <catch2/catch_test_macros.hpp>
#include "../KMM/KeyInfo.h"
#include "../KMM/AlgorithmID.h"

TEST_CASE("KeyInfo", "[KeyInfo]") {
    SECTION("Generation") {
        kmm::KeyInfo key;
        key.m_keysetId = 0x01;
        key.m_sln = 0x6172;
        key.m_kid = 0x6172;
        key.m_algid = DESOFB;

        uint8_t referenceBytes[] = {0x01, 0x61, 0x72, 0x81, 0x61, 0x72};
        uint8_t length = 6;
        uint8_t testBytes[length];
        key.toBytes(testBytes);

        for (int i=0; i<length; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }

    SECTION("Parsing") {
        kmm::KeyInfo key;
        // (hex) keyset 5, sln 4262, algid 84/AES256, kid 5617
        uint8_t referenceBytes[] = {0x05, 0x42, 0x62, 0x84, 0x56, 0x17};
        key.parse(referenceBytes);

        REQUIRE(key.m_keysetId == 0x05);
        REQUIRE(key.m_sln == 0x4262);
        REQUIRE(key.m_algid == AES256);
        REQUIRE(key.m_kid == 0x5617);
    }
}