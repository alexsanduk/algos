OBJS = test.o max_subarray.o
CC = g++
CFLAGS = -c -Wall -I/Users/alexander/usr/gtest/include/
LFLAGS = -Wall -L/Users/alexander/usr/gtest/lib/ -lpthread -lgtest -lgtest_main

test.out : ${OBJS}
	${CC} ${LFLAGS} ${OBJS} -o test.out

test.o : test.cpp max_subarray.h
	${CC} ${CFLAGS} test.cpp

max_subarray.o : max_subarray.cpp max_subarray.h
	${CC} ${CFLAGS} max_subarray.cpp

clean:
	rm -vf *.o prog.out test.out
