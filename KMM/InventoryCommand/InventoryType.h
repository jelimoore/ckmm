#if !defined(__InventoryType_H__)
#define __InventoryType_H__

enum InventoryType {
    Null = 0x00,
    SendCurrentDateTime = 0x01,
    ListActiveKsetIds = 0x02,
    ListInactiveKsetIds = 0x03,
    ListActiveKeyIds = 0x04,
    ListInactiveKeyIds = 0x05,
    ListAllKeysetTaggingInfo = 0x06,
    ListAllUniqueKeyInfo = 0x07,
    ListKeyAssignmentItemsForCSSs = 0x08,
    ListKeyAssignmentItemsForTGs = 0x09,
    ListLongKeyAssignmentItemsForLLIDs = 0x0A,
    ListRsiItems = 0x0B,
    ListKeysetTaggingInfo = 0xF9,
    ListActiveKeys = 0xFD,
    ListMnp = 0xFE,
    ListKmfRsi = 0xFF
};

#endif