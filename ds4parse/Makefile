main: main.o DS4.o
	g++ -Wall -L/usr/lib/libhidapi-hidraw.so.0.0.0 -lhidapi-hidraw  main.o DS4.o -o main 
main.o:
	g++ -c main.cpp
DS4.o:
	g++ -c DS4.cpp
clean:
	rm *.o main
run:
	./main 0
