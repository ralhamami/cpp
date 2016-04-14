a.out: main.o Money.o
	g++ main.o Money.o

Money.o: Money.h Money.cpp
	g++ -c Money.cpp

main.o: main.cpp Money.h
	g++ -c main.cpp

clean:
	/bin/rm -f *.o a.out *~
