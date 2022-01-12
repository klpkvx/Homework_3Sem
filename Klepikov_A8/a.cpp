#include <stdio.h>
#include <time.h>

#include "student.h"
#include "tree.h"
#include "tree_node.h"

int main(int argc, char *argv[])
{
	tree object;

	int res = 0;
	int k = 0;
	int task = 1;
	int err = 0;
	int r = 0;
	double t = 0;

	switch (argc)
	{
	case (4):
		if (!((sscanf(argv[1], "%d", &r) == 1) && r >= 0 && (sscanf(argv[3], "%d", &k) == 1)))
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

	err = object.tree_read(argv[2]);

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

	object.tree_print(r);

	t = clock();
	res = object.task1(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], task, k, res, t);
	task++;

	t = clock();
	res = object.task2(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], task, k, res, t);

	task++;

	t = clock();
	res = object.task3(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], task, k, res, t);

	task++;

	t = clock();
	res = object.task1(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], task, k, res, t);

	task = 5;

	t = clock();
	res = object.task5(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], task, k, res, t);

	task = 6;

	t = clock();
	res = object.task6(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], task, k, res, t);

	return 0;
}
