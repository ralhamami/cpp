#
a.out: main.o
	g++ main.o

main.o: main.cpp TNode.h BST.h
	g++ -c main.cpp

clean:
	rm a.out *.o
