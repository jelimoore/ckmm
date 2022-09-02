#if !defined(__InventoryCommandTests_H__)
#define __InventoryCommandTests_H__

#include "munit/munit.h";
#include "KMM/InventoryCommand/InventoryType.h";
#include "KMM/InventoryCommand/ListActiveKeys.h";
#include "KMM/InventoryCommand/ListActiveKeysetIds.h";
#include "KMM/InventoryCommand/ListKeysetTaggingInfo.h";
#include "KMM/InventoryCommand/ListKmfRsi.h";

static MunitTest InventoryCommand_TestSuite[];

static MunitResult test_ListActiveKeys(const MunitParameter params[], void* data);
static MunitResult test_ListActiveKeysetIds(const MunitParameter params[], void* data);
static MunitResult test_ListKeysetTaggingInfo(const MunitParameter params[], void* data);
static MunitResult test_ListKmfRsi(const MunitParameter params[], void* data);

#endif