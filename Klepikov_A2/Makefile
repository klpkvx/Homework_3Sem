FLAGS = -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

OPT = -O3

CC = g++

all: a01.out a02.out a03.out a05.out a06.out a07.out a08.out a09.out

a01.out:	a01.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a01.o f.o inputarr.o student.o tasks.o -o a01.out
a01.o: a01.cpp
	${CC} -c ${FLAGS} ${OPT} a01.cpp

a02.out:	a02.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a02.o f.o inputarr.o student.o tasks.o -o a02.out
a02.o: a02.cpp
	${CC} -c ${FLAGS} ${OPT} a02.cpp

a03.out:	a03.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a03.o f.o inputarr.o student.o tasks.o -o a03.out
a03.o: a03.cpp
	${CC} -c ${FLAGS} ${OPT} a03.cpp

a05.out:	a05.o f.o inputarr.o student.o tasks.o # делается
	${CC} a05.o f.o inputarr.o student.o tasks.o -o a05.out
a05.o: a05.cpp
	${CC} -c ${FLAGS} ${OPT} a05.cpp

a06.out:	a06.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a06.o f.o inputarr.o student.o tasks.o -o a06.out
a06.o: a06.cpp
	${CC} -c ${FLAGS} ${OPT} a06.cpp

a07.out:	a07.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a07.o f.o inputarr.o student.o tasks.o -o a07.out
a07.o: a07.cpp
	${CC} -c ${FLAGS} ${OPT} a07.cpp

a08.out:	a08.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a08.o f.o inputarr.o student.o tasks.o -o a08.out
a08.o: a08.cpp
	${CC} -c ${FLAGS} ${OPT} a08.cpp

a09.out:	a09.o f.o inputarr.o student.o tasks.o # сделана
	${CC} a09.o f.o inputarr.o student.o tasks.o -o a09.out
a09.o: a09.cpp
	${CC} -c ${FLAGS} ${OPT} a09.cpp

student.o: student.cpp
	${CC} -c ${FLAGS} ${OPT} student.cpp
f.o: f.cpp
	${CC} -c ${FLAGS} ${OPT} f.cpp
tasks.o: tasks.cpp
	${CC} -c ${FLAGS} ${OPT} tasks.cpp
inputarr.o: inputarr.cpp
	${CC} -c ${FLAGS} ${OPT} inputarr.cpp

clean:
	rm -f *.out *o