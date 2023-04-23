#if !defined(__ckmm_H__)
#define __ckmm_H__

// catch-all header file to import all components of the ckmm library

// enums, defines, etc
#include "AlgorithmID.h"
#include "MessageID.h"
#include "OperationStatus.h"
#include "ResponseKind.h"

// ckmm core
#include "KeyInfo.h"
#include "KmmBody.h"
#include "KmmFrame.h"
#include "ThreeWireProtocol.h"

// commands
#include "ZeroizeCommand.h"

// inventory commands
#include "InventoryCommand/ListActiveKeys.h"
#include "InventoryCommand/ListActiveKeysetIds.h"
#include "InventoryCommand/ListKeysetTaggingInfo.h"
#include "InventoryCommand/ListKmfRsi.h"
#include "InventoryCommand/ListMnp.h"
#include "InventoryCommand/ListRsiItems.h"

// responses
#include "ZeroizeResponse.h"

// inventory responses



#endif