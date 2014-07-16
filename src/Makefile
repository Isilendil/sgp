main : main.o Week.o Schedule.o utility.o Population.o
	g++ -o main main.o Week.o Schedule.o utility.o Population.o

main.o : main.cpp Week.h Schedule.h utility.h common.h
	g++ -c main.cpp

Week.o : Week.cpp Week.h utility.h common.h 
	g++ -c Week.cpp

Schedule.o : Schedule.cpp Schedule.h Week.h utility.h common.h 
	g++ -c Schedule.cpp

Population.o : Population.cpp Population.h Week.h Schedule.h utility.h common.h
	g++ -c Population.cpp

utility.o : utility.cpp utility.h common.h
	g++ -c utility.cpp

clean : 
	rm main main.o Week.o Schedule.o utility.o Population.o

