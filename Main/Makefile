# === Makefile ===

CXX := g++
SRC := main.cpp
OUT := main

NORMAL_FLAGS := -std=c++23 -O2 -Wall -Wextra \
                -Wno-unused-variable -Wno-unused-but-set-variable

DEBUG_FLAGS := -std=c++23 -O1 -g3 \
               -Wall -Wextra -Wshadow \
               -Wno-unused-variable -Wno-unused-but-set-variable \
               -fno-omit-frame-pointer \
               -fmax-errors=1 \
               -fdiagnostics-color=always

SAN_FLAGS := $(DEBUG_FLAGS) \
             -fsanitize=address,undefined

.PHONY: all debug san debuglog clean

all:
	@echo Building $(OUT) from $(SRC) using `command -v $(CXX)`
	$(CXX) $(NORMAL_FLAGS) -o $(OUT) $(SRC)

debug:
	@echo Building $(OUT) in debug mode
	$(CXX) $(DEBUG_FLAGS) -o $(OUT) $(SRC)

san:
	@echo Building $(OUT) with sanitizers
	$(CXX) $(SAN_FLAGS) -o $(OUT) $(SRC)

debuglog:
	@echo Building $(OUT) in debug mode, writing diagnostics to build_errors.txt
	$(CXX) $(DEBUG_FLAGS) -fdiagnostics-color=auto -o $(OUT) $(SRC) 2> build_errors.txt

clean:
	rm -f $(OUT) build_errors.txt