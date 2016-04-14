#
a.out: main.o Student.o
	g++ main.o Student.o

Student.o: Student.h Student.cpp
	g++ -c Student.cpp

main.o: main.cpp Student.h List.h Node.h
	g++ -c main.cpp

clean:
	rm a.out *.o
