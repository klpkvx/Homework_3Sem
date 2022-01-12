#include <stdio.h>

#include "student.h"
#include "list.h"
#include "list_node.h"
#include <time.h>

int main(int argc, char *argv[])
{
	int task = 3;
	int r = 0, diff = 0, err = 0;
	double t = 0;

	list obj;

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

	err = obj.list_read(argv[2]);
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
	obj.list_print(r);

	t = clock();
	obj.task03();
	t = (clock() - t) / CLOCKS_PER_SEC;

	printf("Sorted list:\n");
	obj.list_print(r);
	diff = obj.get_less_than_previous();

	printf("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], task, diff, t);
	return 0;
}
