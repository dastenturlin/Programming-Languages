main.o: main.cpp rational.cpp matrix.cpp
	g++ -c main.cpp rational.cpp matrix.cpp -std=c++11

rational.o: rational.cpp rational.h
	g++ -c rational.cpp -std=c++11

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp -std=c++11

week2: main.o rational.o matrix.o
	g++ main.o rational.o matrix.o -o week2 -std=c++14
