#include <stdio.h>
#include <time.h>

#include "student.h"
#include "tree.h"
#include "tree_node.h"

int main(int argc, char *argv[])
{
	tree object;

	int r = 0, err = 0;
	double t = 0;
	int task = 1, res = 0;

	switch (argc)
	{
	case (3):
		if (!((sscanf(argv[1], "%d", &r) == 1) && r >= 0))
		{
			printf("Usage: %s r filename \n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
		printf("Usage: %s r filename \n", argv[0]);
		return ERROR_ARGS;
		break;
	}

	err = object.read(argv[2]);
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

	object.print(r);

	t = clock();
	res = object.task001();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n\n", argv[0], task, res, t);

	task++;

	t = clock();
	res = object.task002();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n\n", argv[0], 2, res, t);

	task++;
/*
	t = clock();
	res = object.task003();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n\n", argv[0], task, res, t);

	task++;

	t = clock();
	res = object.task004();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n\n", argv[0], task, res, t);

	task++;
*/
	t = clock();
	res = object.task005();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n\n", argv[0], 5, res, t);
	return 0;
}
