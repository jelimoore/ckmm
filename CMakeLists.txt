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

list(APPEND ckmm_sources
  KMM/KmmBody.cpp
#  KMM/KmmFrame.cpp

  KMM/InventoryCommand/ListActiveKeys.cpp
  KMM/InventoryCommand/ListActiveKeysetIds.cpp
  KMM/InventoryCommand/ListKeysetTaggingInfo.cpp
  KMM/InventoryCommand/ListKmfRsi.cpp
)

# add the executable
add_executable(ckmm KMM/main.cpp ${ckmm_sources})

add_executable(ckmm_tests tests/CkmmTests.cpp)
target_link_libraries(ckmm_tests PRIVATE Catch2::Catch2WithMain)