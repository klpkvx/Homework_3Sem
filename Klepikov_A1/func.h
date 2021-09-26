#ifndef FUNC_H
#define FUNC_H

#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int f(int i, int n, int s);

/* Функции Ввода, печати */
void Print_Array(Student *array, int n, int p);
int Read_Array(Student *array, char *filename, int n);
int Read_Array_Formula(Student *array, int n, int number_formula);
#endif