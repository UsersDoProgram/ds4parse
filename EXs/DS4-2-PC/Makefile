main:
	cp ../../include/DS4.h DS4.h
	g++ -std=c++14 -Wall -L/usr/lib/libhidapi-hidraw.so.0.0.0 -lhidapi-hidraw ../../lib/DS4.o main.cpp -o main 
clean:
	rm main DS4.h
run:
	./main 0
