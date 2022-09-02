#include "munit/munit.h"
#include "InventoryCommandTests.h"

static const MunitSuite CkmmTestSuite[] = {
  {(char*) "/InventoryCommand", InventoryCommand_TestSuite, NULL, 1, MUNIT_SUITE_OPTION_NONE},
  { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(CkmmTestSuite, (void*) "µnit", argc, argv);
}