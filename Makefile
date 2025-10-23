#AI Generation Used To Make This Makefile

# Compiler & flags
CXX := g++
INCLUDES := -I./gmp-local/include
LIBS := -L./gmp-local/lib -lgmpxx -lgmp
CXXFLAGS := -ggdb -std=c++17 $(INCLUDES)
LDLIBS := -lcurses -ltermcap $(LIBS)

# Sources / objects / binary
SRCS := main.cpp DFA.cpp Buffer.cpp
OBJS := $(SRCS:.cpp=.o)
BIN  := project1.x

# Default target
all: $(BIN)

# Link step
$(BIN): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDLIBS)

# Compile step (generic pattern rule)
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Housekeeping
.PHONY: clean
clean:
	$(RM) -f $(BIN) $(OBJS) *~
