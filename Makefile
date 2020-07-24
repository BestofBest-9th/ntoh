all: test1

test1: test1.o
	g++ -o test1 test1.o

test1.o: file.h test1.cpp
	g++ -c -o test1.o test1.cpp

clean:
	rm -f test1.o



