#include <stdio.h>
#include "time.h"

#include "student.h"
#include "list_node.h"
#include "input_output.h"
#include "tasks.h"
int main(int argc, char *argv[])
{
	int r = 0, err = 0;

	char *filename = nullptr;
	list_node *head = nullptr;

	double t = 0;
	int res = 0;
	int task = 4;

	switch (argc)
	{
	case (3):
		if (!(sscanf(argv[1], "%d", &r) == 1))
		{
			printf("Usage: %s r <filename>\n", argv[0]);
			return ERROR_ARGS;
		}
		break;
	default:
		printf("Usage: %s r <filename>\n", argv[0]);
		return ERROR_ARGS;
		break;
	}

	filename = argv[2];
	err = read_list(filename, &head);
	switch (err)
	{
	case (CANNOT_OPEN):
		printf("Cannot open!\n");
		return err;
		break;
	case (ERROR_MEM):
		printf("Error mem!\n");
		return err;
		break;
	case (ERROR_READ):
		printf("ERROR Read!\n");
		return err;
		break;
	case (CANNOT_READ):
		printf("Cannot read!\n");
		return err;
		break;
	default:
		break;
	}
	printf("List: \n");
	print_list(head, r);
	t = clock();
	res = task04(head);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
	delete_list(head);
	return SUCCESS;
}
