CC          = gcc
CXX         = g++
STRIP       = strip
CFLAGS      = -g -O3 -Wall -std=c++0x -pthread -I.
LIBS        = -lpthread -lutil
LDFLAGS     = -g
KMMFLAGS    = -DMADEBYMAKEFILE

GITFLAGS=
GIT_VER =
GIT_VER_HASH = 
ifneq ("$(wildcard .git)",)
	GIT_VER = \"$(shell git describe --abbrev=8 --dirty --always --tags)\"
	GIT_VER_HASH = \"$(shell git describe --abbrev=8 --always --tags)\"
	GITFLAGS= -D__GIT_VER__=$(GIT_VER) -D__GIT_VER_HASH__=$(GIT_VER_HASH)
endif

KMM_BIN = ckmm
KMM_OBJECTS = \
	KMM/main.o \
	KMM/KmmBody.o \
	$(wildcard KMM/InventoryCommand/*.cpp)

KMM_TEST_BIN = ckmm_test
KMM_TEST_OBJECTS = \
	$(KMM_OBJECTS) \
	$(wildcard tests/*.cpp) \
	tests/munit/munit.c

all: ckmm
test: ckmm-test

ckmm: $(KMM_OBJECTS) 
		$(CXX) $(KMM_OBJECTS) $(CFLAGS) $(KMMFLAGS) $(GITFLAGS) $(LIBS) -o $(KMM_BIN)

ckmm-test: $(KMM_TEST_OBJECTS) 
		$(CXX) $(KMM_TEST_OBJECTS) $(CFLAGS) $(KMMFLAGS) $(GITFLAGS) $(LIBS) -o $(KMM_TEST_BIN)

%.o: %.cpp
		$(CXX) $(CFLAGS) $(KMMFLAGS) $(GITFLAGS) -c -o $@ $<
