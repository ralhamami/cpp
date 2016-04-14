a.out: main.o Money.o Memo.o
	g++ main.o Money.o Memo.o

Memo.o: Memo.h Memo.cpp
	g++ -c Memo.cpp

Money.o: Money.h Money.cpp
	g++ -c Money.cpp

main.o: main.cpp Money.h Memo.h
	g++ -c main.cpp

clean:
	/bin/rm -f *.o a.out *~
