# bank teller simulation

a.out: Customer.o Random.o TellerQueue.o main.o
	g++ Customer.o Random.o TellerQueue.o main.o

Random.o: Random.h Random.cpp
	g++ -c Random.cpp

Customer.o: Customer.h Customer.cpp
	g++ -c Customer.cpp

TellerQueue.o: Customer.h TellerQueue.h TellerQueue.cpp
	g++ -c TellerQueue.cpp

main.o: Random.h Customer.h TellerQueue.h main.cpp
	g++ -c main.cpp

clean:
	rm a.out *.o

