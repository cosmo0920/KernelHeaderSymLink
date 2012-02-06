CXX = g++
LIB = -lboost_filesystem -lboost_system
source = kernelLink.cpp
TARGET = KernelLink

KernelLink:
	$(CXX) -o $(TARGET) $(source) $(LIB)

clean:
	rm $(TARGET)
