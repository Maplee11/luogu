CXX = g++
CXXFLAGS = -std=c++17 -pedantic -O2
TARGET = a.out
SRC = P3376.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

new:
	@ cp "template.cpp" $(SRC)

run: $(TARGET)
	@if [ -f $(TARGET) ]; then \
		clear; \
		./$(TARGET); \
		rm -f $(TARGET); \
	fi

clean:
	@ rm -f $(TARGET)
