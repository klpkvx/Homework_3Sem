#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "func.h"

void Print_Array(Student *array, int n, int p)
{
	if (p > n)
		p = n;
	for (int i = 0; i < p; i++)
	{
		array[i].print();
	}
}

int Read_Array(Student *array, char *filename, int n)
{
	FILE *input;
	int error = 0;
	input = fopen(filename, "r");
	if (input == nullptr)
	{
		return CANNOT_OPEN_FILE;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			error = array[i].read(input);
			if (error != SUCCESS)
			{
				fclose(input);
				return error;
			}
		}
	}
	fclose(input);
	return SUCCESS;
}

int Read_Array_Formula(Student *array, int n, int number_formula)
{
	int error = 0;
	for (int i = 0; i < n; i++)
	{
		error = array[i].init("Student", f(i, n, number_formula));
		if (error != SUCCESS)
		{
			delete[] array;
			array = nullptr;
			return error;
		}
	}
	return SUCCESS;
}