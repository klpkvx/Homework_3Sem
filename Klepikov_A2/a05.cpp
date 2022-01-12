#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"
#include "tasks.h"
#include "func.h"
#include "time.h"

int main(int argc, char *argv[])
{
	int n = 0, p = 0, s = -1;
	char *filename;

	int task = 5;
	int err = 0;
	int res = 0;
	double t = 0;
	Student *array;
	switch (argc)
	{
	case 5:
		if (!((sscanf(argv[1], "%d", &n) == 1) && (sscanf(argv[2], "%d", &p) == 1) && (sscanf(argv[3], "%d", &s) == 1) && (s == 0)))
		{
			printf("Usage: %s n p 0 <filename>\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	case 4:
		if (!((sscanf(argv[1], "%d", &n) == 1) && (sscanf(argv[2], "%d", &p) == 1) && (sscanf(argv[3], "%d", &s) == 1) && (s > 0) && (s < 5)))
		{
			if (!s)
				printf("Usage: %s n p 0 <filename>\n", argv[0]);
			else
				printf("Useage: %s n p s\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
	{
		printf("Usage: %s n p s <filename>\n", argv[0]);
		return ERROR_ARGS;
	}
	break;
	}

	filename = argv[4];

	array = new Student[n];
	if (array == nullptr)
	{
		printf("ERROR ALLOCATE!\n");
		return CANNOT_ALLOCATE;
	}

	if (s)
		err = Read_Array_Formula(array, n, s);
	else
		err = Read_Array(array, filename, n);

	if (err)
	{
		printf("Error read data!\n");
		delete[] array;
		return err;
	}

	Print_Array(array, n, p);

	printf("\n");
	t = clock();
	res = task05(array, n);
	t = (clock() - t) / CLOCKS_PER_SEC;

	Print_Array(array, res, p);

	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
	delete[] array;
}