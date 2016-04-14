a.out: Savings.o Checking.o Account.o main.o
	g++ Savings.o Checking.o Account.o main.o

Savings.o: Savings.h Savings.cpp
	g++ -c Savings.cpp

Checking.o: Checking.h Checking.cpp
	g++ -c Checking.cpp

Account.o: Account.h Account.cpp
	g++ -c Account.cpp

main.o: main.cpp Savings.h Checking.h Account.h
	g++ -c main.cpp

clean:
	/bin/rm -f *.o a.out *~