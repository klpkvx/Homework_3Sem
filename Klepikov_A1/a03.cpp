#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"

#include "student.h"
#include "func.h"
#include "sort.h"

int main(int argc, char *argv[])
{
	Student *array = nullptr;
	Student x;

	int x_value = 0;
	char *x_name = nullptr;

	int n = 0, p = 0, s = 0;
	char *filename = nullptr;

	int err = 0;
	int diff = 0;
	double t = 0;
	int task = 3;

	switch (argc)
	{
	case 6:
		x_name = argv[1];
		if (!((sscanf(argv[2], "%d", &x_value) == 1) && (sscanf(argv[3], "%d", &n) == 1) && (sscanf(argv[4], "%d", &p) == 1) && (sscanf(argv[5], "%d", &s) == 1) && (s > 0) && (s < 6)))
		{
			printf("Input %s x_name x_value n p s\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	case 7:
		x_name = argv[1];
		if (!((sscanf(argv[2], "%d", &x_value) == 1) && (sscanf(argv[3], "%d", &n) == 1) && (sscanf(argv[4], "%d", &p) == 1) && (sscanf(argv[5], "%d", &s) == 1) && (s == 0)))
		{
			printf("Input %s x_name x_value n p 0 filename\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
		printf("Input %s x_name x_value n p s filename\n", argv[0]);
		return ERROR_ARGS;
		break;
	}
	filename = argv[6];
	x.set_name(x_name);
	x.set_value(x_value);

	array = new Student[n];
	if (!array)
	{
		printf("Error allocate memory!\n");
		return CANNOT_ALLOCATE;
	}

	if (s)
	{
		err = Read_Array_Formula(array, n, s);
	}
	else
	{
		err = Read_Array(array, filename, n);
	}

	if (err)
	{
		printf("Error!\n");
		delete[] array;
		x.set_name(nullptr);
		return -1;
	}

	// Print_Array(array, n, p);

	t = clock();
	diff = task03(array, n, x);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], task, diff, t);

	delete[] array;
	x.set_name(nullptr);

	return SUCCESS;
}