
CXX = g++
CXXFLAGS = -Ivendor/SFML/include -Iinclude
LDFLAGS = -Lvendor/SFML/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = build/app.exe
SRC = src/*.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build
