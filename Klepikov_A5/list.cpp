#include "list.h"
#include "list_node.h"

int list::list_read(char *filename)
{
	FILE *fp = nullptr;
	list_node *curr = nullptr, *tail = nullptr;
	list_node buf;
	int ret = 0;

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

	head = new list_node;
	if (!head)
	{
		fclose(fp);
		return CANNOT_ALLOCATE;
	}

	*head = (list_node &&) buf;
	curr = head;

	while ((buf.read(fp)) == SUCCESS)
	{
		tail = new list_node;

		if (!tail)
		{
			list_delete(); //
			fclose(fp);
			return CANNOT_ALLOCATE;
		}
		*tail = (list_node &&) buf;
		curr->set_next(tail);
		curr = tail;
	}

	if (!feof(fp))
	{
		fclose(fp);
		return CANNOT_READ;
	}

	fclose(fp);
	return SUCCESS;
}

void list::list_delete()
{
	list_node *curr = nullptr, *next = nullptr;

	for (curr = head; curr; curr = next)
	{
		next = curr->next;
		delete curr;
	}
}

void list::list_print(int r)
{
	list_node *curr = nullptr;
	int i = 0;

	for (curr = head; curr && i < r; ++i, curr = curr->next)
	{
		curr->print();
	}
}

int list::get_len()
{
	int count = 0;
	list_node *curr;

	for (curr = head; curr; curr = curr->next)
		count++;
	return count;
}

int list::get_less_than_previous()
{
	int count = 0;
	list_node *curr = head;
	for (; curr->next; curr = curr->next)
		if (*curr > *curr->next)
			count++;

	return count;
}