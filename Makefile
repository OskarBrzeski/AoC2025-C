WARNS = -Wall -Wextra -Werror -Wpedantic

run: main
	./main

main: main.c day1.o day2.o day3.o
	cc -o main main.c day1.o day2.o day3.o ${WARNS}

day1.o: days/day1.c days/day1.h
	cc -c days/day1.c ${WARNS}

day2.o: days/day2.c days/day2.h
	cc -c days/day2.c ${WARNS}

day3.o: days/day3.c days/day3.h
	cc -c days/day3.c ${WARNS}
