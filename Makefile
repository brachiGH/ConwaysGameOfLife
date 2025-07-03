CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Define all source files
SRCS = game.cpp game_of_life.cpp cell.cpp

# Define object files (by replacing .cpp with .o)
OBJS = $(SRCS:.cpp=.o)
TARGET = game

all: $(TARGET)

# link the executable from the object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# compile .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean