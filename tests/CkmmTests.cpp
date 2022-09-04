#include "../git.h"
#include <cstdlib>
#include <iostream>
#include <catch2/catch_test_macros.hpp>

TEST_CASE( "CkmmTestInit", "[CkmmInit]" ) {
    printf("CKMM Test Suite\n");
    printf("Built on %s at %s\n", __DATE__, __TIME__);
    REQUIRE(git::IsPopulated() == true);
    if(git::IsPopulated()) {
        if(git::AnyUncommittedChanges()) {
            std::cerr << "WARN: there were uncommitted changes at build-time." << std::endl;
        }
        std::cout << "Commit " << git::CommitSHA1() << " (" << git::Branch() << ")\n"
                  << " - Author: " << git::AuthorName() << " <" << git::AuthorEmail() << ">\n"
                  << " - Date: " << git::CommitDate() << "\n"
                  << " - Msg: " << git::CommitSubject() << std::endl;
    }
    CHECK(git::AnyUncommittedChanges() == false);
}