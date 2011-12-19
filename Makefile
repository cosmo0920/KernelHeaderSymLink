CXX = g++
LIB = -lboost_filesystem
source = kernelLink.cpp
TARGET = KernelLink

KernelLink:
	$(CXX) -o $(TARGET) $(source) $(LIB)

clean:
	rm $(TARGET)