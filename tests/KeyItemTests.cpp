#include <catch2/catch_test_macros.hpp>
#include "../src/KeyItem.h"

TEST_CASE("KeyItem", "[KeyItem]") {
    SECTION("Generation") {
        kmm::KeyItem key;
        key.m_sln = 0x1234;
        key.m_kid = 0x5678;
        uint8_t keyData[2] = {0xab, 0xcd};
        key.m_key = keyData;
        key.m_keyLen = 0x02;

        uint8_t referenceBytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0xab, 0xcd};
        uint8_t referenceLen = 7;
        uint8_t testBytes[referenceLen];
        uint8_t outLen = key.toBytes(testBytes);
        REQUIRE(outLen == referenceLen);

        for (int i=0; i<referenceLen; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}