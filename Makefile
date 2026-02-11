run: main
	./main

main: main.c day1.o
	cc -o main main.c day1.o

day1.o: days/day1.c days/day1.h
	cc -c days/day1.c
