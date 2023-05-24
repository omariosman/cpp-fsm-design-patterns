# Makefile to compile C++ files and create an executable

# Compiler and flags
CXX = g++ -g
CXXFLAGS = -std=c++11 -Wall -Iheaders

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Files and targets
SRCS := $(shell find $(SRCDIR) -name "*.cpp")
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TARGET = $(BINDIR)/my_executable

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
