#include <catch2/catch_test_macros.hpp>
#include "../src/InventoryResponse/ListActiveKeys.h"
#include "../src/KeyInfo.h"

TEST_CASE("ListActiveKeys", "[InventoryResponse]") {
    SECTION("Parsing") {
        kmm::InventoryResponseListActiveKeys* resp = new kmm::InventoryResponseListActiveKeys();

        // SLN 1 KID 1 ALGID 0x84 KSET 1
        uint8_t referenceBytes[] = {0xFD, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x84, 0x00, 0x01};
        resp->parse(referenceBytes);
        
        REQUIRE(resp->m_numItems == 1);
        REQUIRE(resp->m_keys[0]->m_algid == 0x84);
        REQUIRE(resp->m_keys[0]->m_keysetId == 0x01);
        REQUIRE(resp->m_keys[0]->m_kid == 0x01);
        REQUIRE(resp->m_keys[0]->m_sln == 0x01);
    }
}