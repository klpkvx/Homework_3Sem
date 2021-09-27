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
	Student *array3 = nullptr;

	int n1 = 0, n2 = 0, p1 = 0, p2 = 0, s1 = 0, s2 = 0;
	char *filename1 = nullptr;
	char *filename2 = nullptr;

	int err = 0;
	int diff = 0;
	double t = 0;
	int task = 2;

	if (!(argc == 7 || argc == 8 || argc == 9))
	{
		printf("Input %s n1 p1 s1 file1 n2 p2 s2 file\n", argv[0]);
		return ERROR_ARGS;
	}

	if (argc == 7)
	{
		!((sscanf(argv[1], "%d", &n1) == 1) && (sscanf(argv[2], "%d", &p1) == 1) && (sscanf(argv[3], "%d", &s1) == 1) && (sscanf(argv[4], "%d", &n2) == 1) && (sscanf(argv[5], "%d", &p2) == 1) && (sscanf(argv[6], "%d", &s2) == 1) && (s1 > 0) && (s1 < 5) && (s1 > 0) && (s2 < 5));
		{
			printf("Input %s n1 p1 s1 file1 n2 p2 s2 file\n", argv[0]);
			return ERROR_ARGS;
		}
	}
	if (argc == 8)
	{
		if (sscanf(argv[1], "%d", &n1) == 1 && sscanf(argv[2], "%d", &p1) == 1 && sscanf(argv[3], "%d", &s1) == 1 && sscanf(argv[5], "%d", &n2) == 1 && sscanf(argv[6], "%d", &p2) == 1 && sscanf(argv[7], "%d", &s2) == 1 && s1 == 0 && s2 > 0 && s2 <= 4)
		{
			filename1 = argv[4];
		}
		else if (sscanf(argv[1], "%d", &n1) == 1 && sscanf(argv[2], "%d", &p1) == 1 && sscanf(argv[3], "%d", &s1) == 1 && sscanf(argv[4], "%d", &n2) == 1 && sscanf(argv[5], "%d", &p2) == 1 && sscanf(argv[6], "%d", &s2) == 1 && s2 == 0 && s1 > 0 && s1 <= 4)
		{
			filename2 = argv[7];
		}
		else
		{
			printf("Input %s n1 p1 s1 file1 n2 p2 s2 file\n", argv[0]);
			return ERROR_ARGS;
		}
	}
	if (argc == 9)
	{
		if (
				!(sscanf(argv[1], "%d", &n1) == 1 && sscanf(argv[2], "%d", &p1) == 1 && sscanf(argv[3], "%d", &s1) == 1 && sscanf(argv[5], "%d", &n2) == 1 && sscanf(argv[6], "%d", &p2) == 1 && sscanf(argv[7], "%d", &s2) == 1 && s1 == 0 && s2 == 0))
		{
			printf("Input %s n1 p1 s1 file1 n2 p2 s2 file\n", argv[0]);
			return ERROR_ARGS;
		}
		else
		{
			filename1 = argv[4];
			filename2 = argv[8];
		}
	}

	array1 = new Student[n1];

	if (array1 == nullptr)
	{
		printf("Error allocate memory!\n");
		return CANNOT_ALLOCATE;
	}
	array2 = new Student[n2];

	if (array2 == nullptr)
	{
		printf("Error allocate memory!\n");
		delete[] array1;
		return CANNOT_ALLOCATE;
	}

	array3 = new Student[n2 + n1];

	if (array3 == nullptr)
	{
		printf("Error allocate memory!\n");
		delete[] array2;
		delete[] array1;
		return CANNOT_ALLOCATE;
	}

	if (s1)
	{
		err = Read_Array_Formula(array1, n1, s1);
	}
	else
	{
		err = Read_Array(array1, filename1, n1);
	}

	if (err)
	{
		printf("Error!\n");
		delete[] array1;
		delete[] array2;
		delete[] array3;
		return -1;
	}

	if (s2)
	{
		err = Read_Array_Formula(array2, n2, s2);
	}
	else
	{
		err = Read_Array(array2, filename2, n2);
	}

	if (err)
	{
		printf("Error!\n");
		delete[] array1;
		delete[] array2;
		delete[] array3;
		return -1;
	}
	printf("Array1: \n");
	Print_Array(array1, n1, p1);
	printf("\n");

	printf("Array2: \n");
	Print_Array(array2, n2, p2);
	printf("\n");
	t = clock();
	task02(array1, array2, array3, n1, n2);
	t = (clock() - t) / CLOCKS_PER_SEC;

	printf("Array3: \n");
	Print_Array(array3, n1 + n2, p1 + p2);
	printf("\n");
	diff = d_count(array3, n1 + n2);

	printf("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], task, diff, t);
	delete[] array1;
	delete[] array2;
	delete[] array3;

	return 0;
}