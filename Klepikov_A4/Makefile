FLAGS = -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

OPT = -O3

CC = g++

all: a01.out a02.out a03.out a05.out a06.out

a01.out:	list.o student.o list.o list_node.o tasks.o a01.o
	${CC} student.o list.o list_node.o a01.o tasks.o  -o a01.out
a01.o: a01.cpp
	${CC} -c ${FLAGS} ${OPT} a01.cpp




tasks.o: tasks.cpp
	${CC} -c ${FLAGS} ${OPT} tasks.cpp

list.o: list.cpp

	${CC} -c ${FLAGS} ${OPT} list.cpp

list_node.o: list_node.cpp
	${CC} -c ${FLAGS} ${OPT} list_node.cpp

student.o: student.cpp
	${CC} -c ${FLAGS} ${OPT} student.cpp

clean:
	rm -f *.out *o