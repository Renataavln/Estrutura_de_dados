CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = pratica2

OBJS = main.o merge_sort.o quick_sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp merge_sort.h quick_sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

merge_sort.o: merge_sort.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) -c merge_sort.cpp

quick_sort.o: quick_sort.cpp quick_sort.h
	$(CXX) $(CXXFLAGS) -c quick_sort.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
