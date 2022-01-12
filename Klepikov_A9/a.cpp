#include <stdio.h>
#include <time.h>

#include "list2.h"
#include "tree.h"

int list2::m = 0;
int list2::r = 0;

int main(int argc, char *argv[])
{
	int r = 0, res = 0, m = 0;
	double t = 0;
	char *filename;
	FILE *fp = nullptr;

	switch (argc)
	{
	case (4):
		if (!((sscanf(argv[1], "%d", &r) == 1) && r >= 0 && (sscanf(argv[3], "%d", &m) == 1)))
		{
			printf("Usage: %s r filename m\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
		printf("Usage: %s r filename m\n", argv[0]);
		return ERROR_ARGS;
		break;
	}
	filename = argv[2];
	list2::set_m(m);
	list2::set_r(r);

	tree<Student> *object1 = new tree<Student>;
	if (!(fp = fopen(filename, "r")))
	{
		printf("Cannot open %s\n", filename);
		return -1;
	}

	res = object1->read(fp);
	if (res != SUCCESS)
	{
		switch (res)
		{
		case CANNOT_OPEN:
			printf("Cannot open %s\n", filename);
			break;
		case CANNOT_ALLOCATE:
			printf("Cannot allocate %s\n", filename);
			break;
		case CANNOT_READ:
			printf("Cannot read %s\n", filename);
			break;
		default:
			printf("Unknown error %s\n", filename);
		}
		fclose(fp);
		delete object1;
		return -1;
	}

	object1->print(r);

	t = clock();
	res = object1->task1();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 1, res, t);

	t = clock();
	res = object1->task2();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 2, res, t);

	t = clock();
	res = object1->task3();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 3, res, t);

	t = clock();
	res = object1->task4();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 4, res, t);

	t = clock();
	res = object1->task5();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 5, res, t);

	delete object1;
	fclose(fp);

	fp = nullptr;
	printf("\n");

	tree<list2> *object2 = new tree<list2>;
	if (!(fp = fopen(filename, "r")))
	{
		printf("Cannot open %s\n", filename);
		return -1;
	}
	res = object2->read(fp);
	if (res != SUCCESS)
	{
		switch (res)
		{
		case CANNOT_OPEN:
			printf("Cannot open %s\n", filename);
			break;
		case CANNOT_ALLOCATE:
			printf("Cannot allocate %s\n", filename);
			break;
		case CANNOT_READ:
			printf("Cannot read %s\n", filename);
			break;
		default:
			printf("Unknown error %s\n", filename);
		}
		fclose(fp);
		delete object2;
		return -1;
	}
	object2->print(r);

	t = clock();
	res = object2->task1();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 1, res, t);

	t = clock();
	res = object2->task2();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 2, res, t);

	t = clock();
	res = object2->task3();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 3, res, t);

	t = clock();
	res = object2->task4();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 4, res, t);

	t = clock();
	res = object2->task5();
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 5, res, t);

	delete object2;
	fclose(fp);
	return 0;
}
