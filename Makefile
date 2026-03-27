CXX      := g++
CXXFLAGS := -std=c++17 -Wall -O2
BIN      := /tmp/lc_solution

# Usage: make p=5
#        make p=5 args="some input"
ifdef p
SRC := $(firstword $(wildcard $(p)_*.cpp))
endif

.PHONY: run clean

run: $(SRC)
ifndef SRC
	$(error No file found for problem $(p). Usage: make p=<number>)
endif
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SRC) && $(BIN) $(args)

clean:
	rm -f $(BIN)
