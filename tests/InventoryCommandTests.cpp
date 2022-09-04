#include <catch2/catch_test_macros.hpp>
#include "../KMM/InventoryCommand/InventoryType.h"
#include "../KMM/InventoryCommand/ListActiveKeys.h"
#include "../KMM/InventoryCommand/ListActiveKeysetIds.h"
#include "../KMM/InventoryCommand/ListKeysetTaggingInfo.h"
#include "../KMM/InventoryCommand/ListKmfRsi.h"
#include "../KMM/InventoryCommand/ListMnp.h"
#include "../KMM/InventoryCommand/ListRsiItems.h"

TEST_CASE("ListActiveKeys", "[InventoryCommand]") {
    SECTION("Generation") {
        kmm::InventoryCommandListActiveKeys command;
        command.m_inventoryMarker = 0;
        command.m_maxKeysRequested = 78;

        uint8_t referenceBytes[] = {0xFD, 0x00, 0x00, 0x00, 0x00, 0x4E};
        uint8_t CommandLength = 6;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}

TEST_CASE("ListActiveKeysetIds", "[InventoryCommand]") {
    SECTION("Generation") {
        kmm::InventoryCommandListActiveKeysetIds command;

        uint8_t referenceBytes[] = {0x02};
        uint8_t CommandLength = 1;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}

TEST_CASE("ListKeysetTaggingInfo", "[InventoryCommand]") {
    SECTION("Generation") {
        kmm::InventoryCommandListKeysetTaggingInfo command;

        uint8_t referenceBytes[] = {0xF9};
        uint8_t CommandLength = 1;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}

TEST_CASE("ListKmfRsi", "[InventoryCommand]") {
    SECTION("Generation") {
        kmm::InventoryCommandListKmfRsi command;

        uint8_t referenceBytes[] = {0xFF};
        uint8_t CommandLength = 1;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
    
}

TEST_CASE("ListMnp", "[InventoryCommand]") {
    SECTION("Generation") {
        kmm::InventoryCommandListMnp command;

        uint8_t referenceBytes[] = {0xFE};
        uint8_t CommandLength = 1;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}

TEST_CASE("ListRsiItems", "[InventoryCommand]") {
    SECTION("Generation") {
        kmm::InventoryCommandListRsiItems command;

        uint8_t referenceBytes[] = {0x0B};
        uint8_t CommandLength = 1;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}