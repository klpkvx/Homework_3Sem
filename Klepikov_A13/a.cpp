#include <stdio.h>
#include <time.h>

#include "tree.h"
#include "node.h"

int main(int argc, char *argv[])
{
	tree object;

	int res = 0, task = 1;
	double t = 0;
	int err = 0;
	if (argc != 2)
	{
		printf("Usage %s file\n", argv[0]);
		return -1;
	}
	err = object.tree_read(argv[1]);
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

	object.tree_print();

	t = clock();
	res = object.task1();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("Result: %d\n", res);
	task++;

	return 0;
}
