FLAGS = -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

OPT = -O3

CC = g++

LIST = a.o student.o list2.o list2_node.o
LIST_D=$(subst .o,.d,${LIST})

%.o: %.cpp
	${CC} -c ${FLAGS} ${OPT} -MMD $<

%.out: %.out
	${CC} ${FLAGS} $^ -o $@

-include ${LIST_D}
a.out: ${LIST}

clean:
	rm -f *.out ${LIST} ${LIST_D}