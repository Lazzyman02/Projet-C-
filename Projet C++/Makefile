CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = 
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q main.exe main.o 2>nul || exit 0