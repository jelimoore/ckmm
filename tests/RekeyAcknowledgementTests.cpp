#include <catch2/catch_test_macros.hpp>
#include "../src/RekeyAcknowledgement.h"
#include "../src/KeyStatus.h"

TEST_CASE("RekeyAcknowledgement", "[RekeyAcknowledgement]") {
    SECTION("Parsing") {
        kmm::RekeyAcknowledgement* resp = new kmm::RekeyAcknowledgement();

        uint8_t inBytes[] = {0x13, 0x01, 0x84, 0x00, 0x34, 0x00};
        uint8_t inLen = 6;

        resp->parse(inBytes, inLen);
        REQUIRE(resp->m_midAck == 0x13);
        REQUIRE(resp->m_numItems == 0x01);
        REQUIRE(resp->m_keyStatus.m_algid == 0x84);
        REQUIRE(resp->m_keyStatus.m_kid == 0x34);
        REQUIRE(resp->m_keyStatus.m_status == 0x00);
        delete(resp);
    }
}