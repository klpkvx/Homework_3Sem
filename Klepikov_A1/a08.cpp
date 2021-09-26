#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"

#include "student.h"
#include "func.h"
#include "sort.h"

int main(int argc, char *argv[])
{
	Student *array1 = nullptr;
	Student *array2 = nullptr;

	int n = 0, p = 0, s = 0;
	char *filename = nullptr;

	int err = 0;
	int diff = 0;
	double t = 0;
	int task = 8;

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

	array1 = new Student[n];

	if (array1 == nullptr)
	{
		printf("Error allocate memory!\n");
		return CANNOT_ALLOCATE;
	}

	filename = argv[4];

	if (s)
	{
		err = Read_Array_Formula(array1, n, s);
	}
	else
	{
		err = Read_Array(array1, filename, n);
	}

	if (err)
	{
		printf("Error!\n");
		delete[] array1;
		return -1;
	}
	
		array2 = new Student[n];

	if (array2 == nullptr)
	{
		printf("Error allocate memory!\n");
		return CANNOT_ALLOCATE;
	}

	Print_Array(array1, n, p);

	printf("\n");

	t = clock();
	task08(array1,array2, n);
	t = (clock() - t) / CLOCKS_PER_SEC;

	Print_Array(array1, n, p);

	diff = d_count(array1, n);

	printf("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], task, diff, t);
	delete[] array1;
	delete[] array2;

	return 0;
}