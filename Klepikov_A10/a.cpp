#include "b_tree.h"

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int res = 0;
	double t = 0.0;
	int m = 0, r = 0, k = 0, err = 0;
	FILE *fp = nullptr;
	if (!((argc == 5) && (sscanf(argv[1], "%d", &m) == 1) && (sscanf(argv[2], "%d", &r) == 1) && (sscanf(argv[3], "%d", &k) == 1)))
	{
		printf("Usage: %s m r k filename\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[4], "r");
	if (!fp)
	{
		printf("Cannot open file!\n");
		return CANNOT_OPEN;
	}

	b_tree<Student> *a = new b_tree<Student>(m);
	if (!a)
	{
		printf("Cannot allocate!\n");
		return CANNOT_ALLOCATE;
	}

	err = a->read(fp);
	if (err != SUCCESS)
	{
		fclose(fp);
		delete a;
		printf("ERROR: WRONG FILE/MEM\n");
		return -1;
	}

	fclose(fp);
	a->print(r);

	t = clock();
	res = a->task1(k);
	t = (clock() - t) / CLOCKS_PER_SEC;

	printf("%s : Task = %d M = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 1, m, k, res, t);

	t = clock();
	res = a->task2(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d M = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 2, m, k, res, t);

	t = clock();
	res = a->task5(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d M = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 3, m, k, res, t);

	t = clock();
	res = a->task2(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d M = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 4, m, k, res, t);

	t = clock();
	res = a->task5(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d M = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 5, m, k, res, t);

	t = clock();
	res = a->task6(k);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d M = %d K = %d Result = %d Elapsed = %.2f\n", argv[0], 6, m, k, res, t);

	delete a;
	return 0;
}