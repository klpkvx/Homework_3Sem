FLAGS = -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

OPT = -O3

CC = g++

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out

a01.out:	list_node.o student.o tasks.o  input_output.o a01.o
	${CC} list_node.o student.o a01.o tasks.o input_output.o -o a01.out
a01.o: a01.cpp
	${CC} -c ${FLAGS} ${OPT} a01.cpp

a02.out:	list_node.o student.o tasks.o  input_output.o a02.o
	${CC} list_node.o student.o a02.o tasks.o input_output.o -o a02.out
a02.o: a02.cpp
	${CC} -c ${FLAGS} ${OPT} a02.cpp

a03.out:	list_node.o student.o tasks.o  input_output.o a03.o
	${CC} list_node.o student.o a03.o tasks.o input_output.o -o a03.out
a03.o: a03.cpp
	${CC} -c ${FLAGS} ${OPT} a03.cpp

a04.out:	list_node.o student.o tasks.o  input_output.o a04.o
	${CC} list_node.o student.o a04.o tasks.o input_output.o -o a04.out
a04.o: a04.cpp
	${CC} -c ${FLAGS} ${OPT} a04.cpp

a05.out:	list_node.o student.o tasks.o  input_output.o a05.o
	${CC} list_node.o student.o a05.o tasks.o input_output.o -o a05.out
a05.o: a05.cpp
	${CC} -c ${FLAGS} ${OPT} a05.cpp

a06.out:	list_node.o student.o tasks.o  input_output.o a06.o
	${CC} list_node.o student.o a06.o tasks.o input_output.o -o a06.out
a06.o: a06.cpp
	${CC} -c ${FLAGS} ${OPT} a06.cpp

a07.out:	list_node.o student.o tasks.o  input_output.o a07.o
	${CC} list_node.o student.o a07.o tasks.o input_output.o -o a07.out
a07.o: a07.cpp
	${CC} -c ${FLAGS} ${OPT} a07.cpp

tasks.o: tasks.cpp
	${CC} -c ${FLAGS} ${OPT} tasks.cpp

list_node.o: list_node.cpp
	${CC} -c ${FLAGS} ${OPT} list_node.cpp

student.o: student.cpp
	${CC} -c ${FLAGS} ${OPT} student.cpp

input_output.o: input_output.cpp
	${CC} -c ${FLAGS} ${OPT} input_output.cpp

clean:
	rm -f *.out *o