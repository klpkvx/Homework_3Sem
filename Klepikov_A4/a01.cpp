#include <stdio.h>

#include "student.h"
#include "list.h"
#include <time.h>

//#include "tasks.h"

int main(int argc, char *argv[])
{
	int task = 1;
	int k = 0, r = 0;
	int err = 0, len1 = 0, len2 = 0;
	char *filename = nullptr;
	double t = 0;
	list List;

	switch (argc)
	{
	case (4):
		if (!((sscanf(argv[1], "%d", &r) == 1) && r >= 0 && sscanf(argv[3], "%d", &k) == 1))
		{
			printf("Usage: %s r filename k\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
		printf("Usage: %s r filename k\n", argv[0]);
		return ERROR_ARGS;
		break;
	}

	filename = argv[2];

	err = List.list_read(filename);
	if (err)
	{
		switch (err)
		{
		case CANNOT_ALLOCATE:
			printf("Cannot allocate memory!\n");
			return err;
			break;
		case CANNOT_READ:
			printf("Cannot read file!\n");
			return err;
			break;
		case CANNOT_OPEN:
			printf("Cannot open file!\n");
			return err;
			break;
		default:
			printf("Unknown error!\n");
			return err;
		}
	}
	
	printf("Input list:\n");
	List.list_print(r);
	len1 = List.get_len();

	if (k >= 0)
		k = len1 - k % len1;
	else
		k = (-k) % len1;

	t = clock();
	List.task01(k);
	t = (clock() - t) / CLOCKS_PER_SEC;

	printf("New list:\n");
	List.list_print(r);
	len2 = List.get_len();

	printf("%s : Task = %d Len Old = %d Len New = %d Elapsed = %.2f\n", argv[0], task, len1, len2, t);
	return 0;
}
