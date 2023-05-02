#include <catch2/catch_test_macros.hpp>
#include "../src/KmmFrame.h"
#include "../src/ZeroizeCommand.h"
#include "../src/InventoryCommand/ListActiveKeys.h"
#include "../src/MessageID.h"

TEST_CASE("KmmFrame", "[KmmFrame]") {
    SECTION("Generation - No Preamble 1") {
        kmm::ZeroizeCommand* command = new kmm::ZeroizeCommand();
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0x21, 0x00, 0x07, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        uint16_t length = 10;
        uint8_t testBytes[length];

        uint16_t receivedLen = frame.toBytes(testBytes);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            //printf("Index %d: ref %d test %d\n", i, referenceBytes[i], testBytes[i]);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
        delete(command);
    }

    SECTION("Generation - No Preamble 2") {
        kmm::InventoryCommandListActiveKeys* command = new kmm::InventoryCommandListActiveKeys();
        command->m_inventoryMarker = 0x00;
        command->m_maxKeysRequested = 0x4E;
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0x0D, 0x00, 0x0D, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
        0xFD, 0x00, 0x00, 0x00, 0x00, 0x4E};
        uint16_t length = 16;
        uint8_t testBytes[length];

        uint16_t receivedLen = frame.toBytes(testBytes);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            //printf("Index %d: ref %d test %d\n", i, referenceBytes[i], testBytes[i]);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
        delete(command);
    }
/*
    SECTION("Generation - With Preamble 1") {
        kmm::ZeroizeCommand* command = new kmm::ZeroizeCommand();
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x21, 0x00, 0x07, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        uint16_t length = 24;
        uint8_t testBytes[length];

        uint16_t receivedLen = frame.toBytesWithPreamble(testBytes, 0x00);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            //printf("Index %d: ref %d test %d\n", i, referenceBytes[i], testBytes[i]);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
        delete(command);
    }

    SECTION("Generation - With Preamble 2") {
        kmm::InventoryCommandListActiveKeys* command = new kmm::InventoryCommandListActiveKeys();
        command->m_inventoryMarker = 0x00;
        command->m_maxKeysRequested = 0x4E;
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0D, 0x00, 0x0D, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
        0xFD, 0x00, 0x00, 0x00, 0x00, 0x4E};
        uint16_t length = 30;
        uint8_t testBytes[length];

        uint16_t receivedLen = frame.toBytesWithPreamble(testBytes, 0x00);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            //printf("Index %d: ref %d test %d\n", i, referenceBytes[i], testBytes[i]);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
        delete(command);
    }
    */

    SECTION("Parsing - 1") {
        uint8_t inBytes[] = {0x22, 0x00, 0x07, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        kmm::KmmFrame* frame = new kmm::KmmFrame(false, inBytes);
        kmm::KmmBody* body = frame->kmmBody;
        REQUIRE(body->m_messageId == ZeroizeResponse_ID);
        delete(frame);
        delete(body);
    }

    SECTION("Parsing - 2") {
        uint8_t inBytes[] = {0x0D, 0x00, 0x0D, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x4E};
        kmm::KmmFrame* frame = new kmm::KmmFrame(false, inBytes);
        delete(frame);
    }

    SECTION("Parsing - 3") {
        uint8_t inBytes[] = {0x0E, 0x00, 0x13, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x84, 0x00, 0x01};
        kmm::KmmFrame* frame = new kmm::KmmFrame(false, inBytes);
        kmm::KmmBody* body = frame->kmmBody;
        REQUIRE(body->m_messageId == InventoryResponse_ID);
        
        kmm::InventoryResponseListActiveKeys* keysResp = static_cast<kmm::InventoryResponseListActiveKeys*>(body);
        REQUIRE(keysResp->m_keys[0]->m_algid == 0x84);
        REQUIRE(keysResp->m_keys[0]->m_keysetId == 0x01);
        REQUIRE(keysResp->m_keys[0]->m_sln == 0x01);
        REQUIRE(keysResp->m_keys[0]->m_kid == 0x01);
        delete(frame);
        delete(body);
    }
}