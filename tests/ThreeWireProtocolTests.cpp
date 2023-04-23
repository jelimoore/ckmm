#include <catch2/catch_test_macros.hpp>
#include "../src/KmmFrame.h"
#include "../src/ZeroizeCommand.h"
#include "../src/ThreeWireProtocol.h"

TEST_CASE("ThreeWireProtocol", "[TWP]") {
    SECTION("Generation - No Body") {
        kmm::ZeroizeCommand* command = new kmm::ZeroizeCommand();
        kmm::KmmFrame frame(command);

        uint8_t referenceBytes[] = {0xC2U, 0x00U, 0x10U, 0x00U, 0xFFU, 0xFFU, 0xFFU, 0x21U, 0x00U, 0x07U, 0x80U, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0x74U, 0xD7U};
        uint16_t length = 19;
        uint8_t testBytes[length];

        uint16_t receivedLen = kmmCreateKmmFrame(&frame, testBytes);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            //printf("Index %d: ref %d test %d\n", i, referenceBytes[i], testBytes[i]);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
        delete(command);
    }

    SECTION("Generation - With Body") {
        kmm::ZeroizeCommand* command = new kmm::ZeroizeCommand();
        kmm::KmmFrame frame(command);
        
        

        uint8_t referenceBytes[] = {0xC2U, 0x00U, 0x10U, 0x00U, 0xFFU, 0xFFU, 0xFFU, 0x21U, 0x00U, 0x07U, 0x80U, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0x74U, 0xD7U};
        uint16_t length = 19;
        uint8_t testBytes[length];

        uint16_t receivedLen = kmmCreateKmmFrame(&frame, testBytes);
        REQUIRE(length == receivedLen);

        for (int i=0; i<length; i++) {
            printf("Index %d: ref %d test %d\n", i, referenceBytes[i], testBytes[i]);
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
        delete(command);
    }

    SECTION("Parsing") {
        //TODO
        REQUIRE(1 == 1);
    }
}