#include "list_node.h"
#include "input_output.h"

void print_list(list_node *head, int r)
{
	int i = 0;
	list_node *curr;
	for (curr = head; curr && i < r; ++i, curr = curr->get_next())
		curr->print();
}

int read_list(char *filename, list_node **head)
{
	list_node *curr, *tail;
	list_node buf;
	FILE *fp;
	int ret;

	fp = fopen(filename, "r");
	if (!fp)
	{
		return CANNOT_OPEN;
	}

	if ((ret = buf.read(fp)) != SUCCESS)
	{
		fclose(fp);
		return ret;
	}
	*head = new list_node;
	if (!*head)
	{
		fclose(fp);
		return ERROR_MEM;
	}
	**head = (list_node &&) buf;
	curr = *head;
	while ((buf.read(fp)) == SUCCESS)
	{
		tail = new list_node;
		if (!tail)
		{
			delete_list(*head);
			fclose(fp);
			return ERROR_MEM;
		}

		*tail = (list_node &&) buf;
		curr->set_next(tail);
		curr = tail;
	}

	if (!feof(fp))
	{
		delete_list(*head);
		fclose(fp);
		return ERROR_READ;
	}

	fclose(fp);
	return SUCCESS;
}

void delete_list(list_node *head)
{
	list_node *curr, *next;
	for (curr = head; curr; curr = next)
	{
		next = curr->get_next();
		delete curr;
	}
}