#include "InventoryCommandTests.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("ListActiveKeys", "[InventoryCommand]") {
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

TEST_CASE("ListActiveKeysetIds", "[InventoryCommand]") {
    kmm::InventoryCommandListActiveKeysetIds command;

    uint8_t referenceBytes[] = {0x02};
    uint8_t CommandLength = 1;
    uint8_t testBytes[CommandLength];
    command.toBytes(testBytes);

    for (int i=0; i<CommandLength; i++) {
        REQUIRE(referenceBytes[i] == testBytes[i]);
    }
}

TEST_CASE("ListKeysetTaggingInfo", "[InventoryCommand]") {
    kmm::InventoryCommandListKeysetTaggingInfo command;

    uint8_t referenceBytes[] = {0xF9};
    uint8_t CommandLength = 1;
    uint8_t testBytes[CommandLength];
    command.toBytes(testBytes);

    for (int i=0; i<CommandLength; i++) {
        REQUIRE(referenceBytes[i] == testBytes[i]);
    }
}

TEST_CASE("ListKmfRsi", "[InventoryCommand]") {
    kmm::InventoryCommandListKmfRsi command;

    uint8_t referenceBytes[] = {0xFF};
    uint8_t CommandLength = 1;
    uint8_t testBytes[CommandLength];
    command.toBytes(testBytes);

    for (int i=0; i<CommandLength; i++) {
        REQUIRE(referenceBytes[i] == testBytes[i]);
    }
}

TEST_CASE("ListMnp", "[InventoryCommand]") {
    kmm::InventoryCommandListMnp command;

    uint8_t referenceBytes[] = {0xFE};
    uint8_t CommandLength = 1;
    uint8_t testBytes[CommandLength];
    command.toBytes(testBytes);

    for (int i=0; i<CommandLength; i++) {
        REQUIRE(referenceBytes[i] == testBytes[i]);
    }
}

TEST_CASE("ListRsiItems", "[InventoryCommand]") {
    kmm::InventoryCommandListRsiItems command;

    uint8_t referenceBytes[] = {0x0B};
    uint8_t CommandLength = 1;
    uint8_t testBytes[CommandLength];
    command.toBytes(testBytes);

    for (int i=0; i<CommandLength; i++) {
        REQUIRE(referenceBytes[i] == testBytes[i]);
    }
}