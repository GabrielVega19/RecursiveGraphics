all: TFractal

TFractal: TFractal.o Triangle.o
	g++ TFractal.o Triangle.o -o TFractal -lsfml-system -lsfml-graphics -lsfml-window

TFractal.o: TFractal.cpp
	g++ TFractal.cpp -c -g -ansi -Wall -Werror -pedantic -std=c++17

Triangle.o: Triangle.cpp Triangle.h
	g++ Triangle.cpp -c -g -ansi -Wall -Werror -pedantic -std=c++17

clean:
	rm *.o TFractal