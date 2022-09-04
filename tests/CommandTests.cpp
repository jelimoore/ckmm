#include <catch2/catch_test_macros.hpp>
#include "../KMM/ZeroizeCommand.h"

TEST_CASE("ZeroizeCommand", "[Command]") {
    SECTION("Generation") {
        kmm::ZeroizeCommand command;

        uint8_t referenceBytes[] = {0x21};
        uint8_t CommandLength = 1;
        uint8_t testBytes[CommandLength];
        command.toBytes(testBytes);

        for (int i=0; i<CommandLength; i++) {
            REQUIRE(referenceBytes[i] == testBytes[i]);
        }
    }
}