# prog05

a.out: Time.o Date.o Appointment.o Onetime.o Daily.o Monthly.o main.o
	g++ Time.o Date.o Appointment.o Onetime.o Daily.o Monthly.o main.o

Time.o: Time.h Time.cpp
	g++ -c Time.cpp

Date.o: Time.h Date.h Date.cpp
	g++ -c Date.cpp

Appointment.o: Appointment.h Appointment.cpp
	g++ -c Appointment.cpp

Onetime.o: Appointment.h Onetime.h Onetime.cpp
	g++ -c Onetime.cpp

Daily.o: Appointment.h Daily.h Daily.cpp
	g++ -c Daily.cpp

Monthly.o: Appointment.h Monthly.h Monthly.cpp
	g++ -c Monthly.cpp

main.o: Appointment.h Onetime.h Daily.h Monthly.h main.cpp
	g++ -c main.cpp

clean:
	/bin/rm -f *.o a.out
