#include "student.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef FUNC_H
#define FUNC_H

int f(int i, int n, int s);

void Print_Array(Student *array, int n, int p);
int Read_Array(Student *array, char *filename, int n);
int Read_Array_Formula(Student *array, int n, int number_formula);
#endif