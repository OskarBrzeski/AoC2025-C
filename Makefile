WARNS = -Wall -Wextra -Werror -Wpedantic

run: main
	./main

main: main.c day1.o day2.o day3.o day4.o day5.o utility.o
	cc -o main main.c day1.o day2.o day3.o day4.o day5.o utility.o ${WARNS}

day1.o: days/day1.c days/day1.h utility.o
	cc -c days/day1.c ${WARNS}

day2.o: days/day2.c days/day2.h utility.o
	cc -c days/day2.c ${WARNS}

day3.o: days/day3.c days/day3.h utility.o
	cc -c days/day3.c ${WARNS}

day4.o: days/day4.c days/day4.h utility.o
	cc -c days/day4.c ${WARNS}

day5.o: days/day5.c days/day5.h utility.o
	cc -c days/day5.c ${WARNS}

utility.o: utility.c utility.h
	cc -c utility.c ${WARNS}
