#
a.out: main.o
	g++ main.o

main.o: Node.h Stack.h main.cpp
	g++ -c main.cpp

clean:
	rm a.out *.o
