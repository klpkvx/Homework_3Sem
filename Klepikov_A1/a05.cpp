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

	int n = 0, p = 0, s = 0;
	char *filename = nullptr;

	int err = 0;
	int diff = 0;
	double t = 0;
	int task = 5;

	switch (argc) // ./a.out x_name x_value n p s filename
	{
	case 4:
		if (!((sscanf(argv[1], "%d", &n) == 1) && (sscanf(argv[2], "%d", &p) == 1) && (sscanf(argv[3], "%d", &s) == 1) && (s > 0) && (s < 6)))
		{
			printf("Input %s n p s\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	case 5:
		if (!((sscanf(argv[1], "%d", &n) == 1) && (sscanf(argv[2], "%d", &p) == 1) && (sscanf(argv[3], "%d", &s) == 1) && (s == 0)))
		{
			printf("Input %s n p 0 filename\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
		printf("Input %s n p s filename\n", argv[0]);
		return ERROR_ARGS;
		break;
	}

	array = new Student[n];

	if (array == nullptr)
	{
		printf("Error allocate memory!\n");
		return CANNOT_ALLOCATE;
	}

	filename = argv[4];

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
		return -1;
	}

	Print_Array(array, n, p);

	printf("\n");

	t = clock();
	task05(array, n);
	t = (clock() - t) / CLOCKS_PER_SEC;

	Print_Array(array, n, p);

	diff = d_count(array, n);

	printf("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], task, diff, t);
	delete[] array;

	return 0;
}