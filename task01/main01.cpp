#include "stdlib.h"
#include "stdio.h"
#include "strings.h"
#include "time.h"

#include "student.h"
#include "func.h"

int main(int argc, char *argv[])
{
	int n = 0, p = 0, s = 0;
	char *filename = nullptr;
	Student x;
	if (argc < 6)
	{
		printf("Usage: %s [x.name] [x.value] n r s [filename]\n", argv[0]);
		return ERROR_ARGS;
	}

	if()

  // x.name, x.value;

}


/*nt main(int argc, char *argv[])
{
	int n = 0, p = 0, s = 0;
	char *filename = nullptr;

	double x = 0;
	if (argc < 5)
	{
		printf("Usage: %s x n r s <file>\n", argv[0]);
		return -1;
	}
	printf("nice\n");
	if (!((scanf(argv[2], "%lf", &x) == 1) && (scanf(argv[3], "%d", &n) == 1) && (scanf(argv[4], "d", &p) == 1) && (s > 0) && (s < 5) && (scanf(argv[5], "%s", filename)== 1)))
	{
		printf("Usage: %s x n r s <file> \n", argv[0]);
		return -1;
	}
	//printf("%s: Task = %d Diff = %d Elapsed = %.2f\n", argv[0], task, diff, t);
	return 0;
}
*/