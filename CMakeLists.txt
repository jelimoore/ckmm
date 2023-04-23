cmake_minimum_required(VERSION 3.10)

Include(FetchContent)

# set the project name
project(ckmm)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

# set the project name
project(ckmm)

FetchContent_Declare(cmake_git_version_tracking                   
  GIT_REPOSITORY https://github.com/andrew-hardin/cmake-git-version-tracking.git
  GIT_TAG 904dbda1336ba4b9a1415a68d5f203f576b696bb
)
FetchContent_MakeAvailable(cmake_git_version_tracking)

list(APPEND ckmm_sources
  src/CRC16.cpp
  src/KeyInfo.cpp
  src/KmmBody.cpp
  src/KmmFrame.cpp
  src/ThreeWireProtocol.cpp
  src/ZeroizeCommand.cpp
  src/ZeroizeResponse.cpp

  src/InventoryCommand/ListActiveKeys.cpp
  src/InventoryCommand/ListActiveKeysetIds.cpp
  src/InventoryCommand/ListKeysetTaggingInfo.cpp
  src/InventoryCommand/ListKmfRsi.cpp
  src/InventoryCommand/ListMnp.cpp
  src/InventoryCommand/ListRsiItems.cpp

)

list(APPEND ckmm_test_sources
  tests/CommandTests.cpp
  tests/InventoryCommandTests.cpp
  tests/KeyInfoTests.cpp
  tests/KmmFrameTests.cpp
)

# add the executable
#add_executable(ckmm KMM/main.cpp ${ckmm_sources})

add_executable(ckmm_tests tests/CkmmTests.cpp ${ckmm_test_sources} ${ckmm_sources})
target_link_libraries(ckmm_tests PRIVATE cmake_git_version_tracking Catch2::Catch2WithMain)