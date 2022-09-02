#include "InventoryCommandTests.h"


static MunitTest InventoryCommand_TestSuite[] = {
  {(char*) "/ListActiveKeys", test_ListActiveKeys, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {(char*) "/ListActiveKeysetIDs", test_ListActiveKeysetIds, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {(char*) "/ListKeysetTaggingInfo", test_ListKeysetTaggingInfo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {(char*) "/ListKMFRSI", test_ListKmfRsi, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},

  // array of nulls to tell the test runner the array has ended
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static MunitResult test_ListActiveKeys(const MunitParameter params[], void* data) {
    /* These are just to silence compiler warnings about the parameters
   * being unused. */
  (void) params;
  (void) data;
  return MUNIT_OK;
}

static MunitResult test_ListActiveKeysetIds(const MunitParameter params[], void* data) {
    /* These are just to silence compiler warnings about the parameters
   * being unused. */
  (void) params;
  (void) data;
  return MUNIT_OK;
}

static MunitResult test_ListKeysetTaggingInfo(const MunitParameter params[], void* data) {
    /* These are just to silence compiler warnings about the parameters
   * being unused. */
  (void) params;
  (void) data;
  return MUNIT_OK;
}

static MunitResult test_ListKmfRsi(const MunitParameter params[], void* data) {
  /* These are just to silence compiler warnings about the parameters
   * being unused. */
  (void) params;
  (void) data;

  munit_assert_uint8(0, ==, 0);

  return MUNIT_OK;
}