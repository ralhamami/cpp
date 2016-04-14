# Heap

a.out: main.o Car.o
	g++ main.o Car.o

Car.o: Car.h Car.cpp
	g++ -c Car.cpp

main.o: main.cpp Car.h Heap.h
	g++ -c main.cpp

clean:
	rm *.o a.out
