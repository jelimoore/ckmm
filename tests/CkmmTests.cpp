#include "stdio.h"
#include "munit/munit.h"
#include "InventoryCommandTests.h"

static const MunitSuite CkmmTestSuite[] = {
  {(char*) "/InventoryCommand", InventoryCommand_TestSuite, NULL, 1, MUNIT_SUITE_OPTION_NONE},
  { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    printf("CKMM Test Suite\n");
    printf("Built on %s at %s\n", __DATE__, __TIME__);
    printf("Git version: %s (%s)", __GIT_VER__, __GIT_VER_HASH__);
    return munit_suite_main(CkmmTestSuite, (void*) "µnit", argc, argv);
}