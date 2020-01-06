piglatin: piglatin.o main.o
	g++ -Wall -g piglatin.o main.o -o piglatin

piglatin.o: piglatin.cpp piglatin.h
	g++ -Wall -c piglatin.cpp

main.o: main.cpp piglatin.h
	g++ -Wall -c main.cpp

clean:
	rm -rf piglatin *.o