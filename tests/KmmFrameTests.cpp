#include <catch2/catch_test_macros.hpp>
#include "../KMM/KmmFrame.h"
#include "../KMM/ZeroizeCommand.h"

TEST_CASE("KmmFrame", "[KmmFrame]") {
    SECTION("Generation - No Preamble") {
        kmm::ZeroizeCommand command;
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0x01, 0x61, 0x72, 0x81, 0x61, 0x72};
        uint16_t length = 6;
        uint8_t testBytes[length];

        uint16_t receivedLen = frame.toBytes(testBytes);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            printf("Index %d", i);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }

    SECTION("Generation - With Preamble") {
        kmm::ZeroizeCommand command;
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        uint16_t length = 24;
        uint8_t testBytes[length];

        uint16_t receivedLen = frame.toBytesWithPreamble(testBytes, 0x00);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            printf("Index %d", i);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }

    SECTION("Parsing") {
        //TODO
        REQUIRE(1 == 1);
    }
}