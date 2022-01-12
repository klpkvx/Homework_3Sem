#include "avl_tree.h"

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int r = 0, k = 0;
	double t = 0.;
	int res = 0;
	int err = SUCCESS;
	FILE *fp = nullptr;
	if (!((argc == 4) && (sscanf(argv[1], "%d", &r) == 1) && r >= 0 && (sscanf(argv[2], "%d", &k) == 1)))
	{
		printf("Usage: %s r k filename\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[3], "r");
	if (!fp)
	{
		printf("Cannot open file!\n");
		return CANNOT_OPEN;
	}

	avl_tree<Student> *a = new avl_tree<Student>;
	if (!a)
	{
		printf("Cannot allocate!\n");
		return CANNOT_ALLOCATE;
	}

	err = a->read(fp);
	if (err != SUCCESS)
	{
		switch (err)
		{
		case CANNOT_ALLOCATE:
			printf("Cannot allocate\n");
			fclose(fp);
			delete a;
			return CANNOT_ALLOCATE;
			break;
		case CANNOT_READ:
			printf("Cannot read\n");
			fclose(fp);
			delete a;
			return CANNOT_READ;
			break;
		default:
			printf("Unknown error\n");
			fclose(fp);
			delete a;
			break;
		}
	}

	fclose(fp);
	a->print(r);

	t = clock();
	res = a->task1(k);
	t = (clock() - t) / CLOCKS_PER_SEC;

	printf("%s : Task = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 1, k, res, t);

	/*	t = clock();
		res = a->task2(k);
		t = (clock() - t) / CLOCKS_PER_SEC;
		printf("%s : Task = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 2, k, res, t);

		t = clock();
		res = a->task3(k);
		t = (clock() - t) / CLOCKS_PER_SEC;
		printf("%s : Task = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 3, k, res, t);*/

		t = clock();
		res = a->task4(k);
		t = (clock() - t) / CLOCKS_PER_SEC;
		printf("%s : Task = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 4, k, res, t);

		t = clock();
		res = a->task5(k);
		t = (clock() - t) / CLOCKS_PER_SEC;
		printf("%s : Task = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 5, k, res, t);

	delete a;
	return 0;
}