lab5 : Hugeint.o main.o
	g++ -o lab5 Hugeint.o main.o

HugeInt.o : Hugeint.cpp Hugeint.h
	g++ -c Hugeint.cpp

main.o : main.cpp Hugeint.h
	g++ -c main.cpp

clean : 
	rm lab5 *.o
