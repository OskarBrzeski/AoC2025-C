WARNS = -Wall -Wextra -Werror -Wpedantic
OBJECTS = day1.o utility.o day2.o day3.o day4.o day5.o day6.o day7.o

run: main
	./main

main: main.c ${OBJECTS}
	cc -o main main.c ${OBJECTS} ${WARNS}

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

day6.o: days/day6.c days/day6.h utility.o
	cc -c days/day6.c ${WARNS}

utility.o: utility.c utility.h
	cc -c utility.c ${WARNS}

day7.o: days/day7.c days/day7.h utility.o
	cc -c days/day7.c ${WARNS}
