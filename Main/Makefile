# === Makefile ===

# 1) rely on whatever g++ is on your PATH
CXX      := g++
CXXFLAGS := -std=c++23 -O2 -Wextra

# 2) disable built‑in suffix rules
.SUFFIXES:

# 3) default goal: if you run “make” with no args, build main
all: main

# 4) pattern rule: “make foo” → compiles foo.cpp → foo.exe
%: %.cpp
	@echo Building $@ from $< using `where g++`  
	$(CXX) $(CXXFLAGS) -o $@ $<

# 5) clean up
.PHONY: clean
clean:
	del /Q *.exe    # on *nix use: rm -f *.exe
