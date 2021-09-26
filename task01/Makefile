FLAGS =	-mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

OPT = -O3

CC = g++

all: a01.out

a01.out: main01.o student.o
	${CC} main01.o student.o -o a.out
main01.o: main01.cpp
	${CC} -c ${FLAGS} ${OPT} main01.cpp
student.o: student.cpp
	${CC} -c ${FLAGS} ${OPT} student.cpp
f.o: f.cpp
	${CC} -c ${FLAGS} ${OPT} f.cpp
clean:
	rm -f *.out *.o