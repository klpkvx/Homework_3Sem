#include "list2.h"
#include <stdlib.h>

list2::list2(list2 &&x)
{
	head = x.head;
	x.head = nullptr;
}

list2 &list2::operator=(list2 &&x)
{
	head = x.head;
	x.head = nullptr;
	return *this;
}

list2::~list2()
{
	delete_list();
	head = nullptr;
}

int list2::operator<(const list2 &x)
{
	if (x.head == nullptr)
	{
		if (this->head == nullptr)
			return 0;
		return -1;
	}
	else
	{
		if (this->head == nullptr)
			return 1;
		return (this->head->operator<(*(x.head)));
	}
}

int list2::read(FILE *fp)
{
	int ret = 0, i = 0;
	list2_node buf;
	list2_node *curr, *tail;
	ret = buf.read(fp);
	if (ret != SUCCESS)
		return ret;
	head = new list2_node;
	if (head == nullptr)
		return CANNOT_ALLOCATE;
	*head = (list2_node &&) buf;
	curr = head;
	i = 1;
	while (i < list2::m && buf.read(fp) == SUCCESS)
	{
		tail = new list2_node;
		if (!tail)
		{
			delete_list();
			return CANNOT_ALLOCATE;
		}
		*tail = (list2_node &&) buf;
		curr->next = tail;
		tail->prev = curr;
		curr = tail;
		i++;
	}
	if (!feof(fp) && i < list2::m)
	{
		delete_list();
		return CANNOT_READ;
	}
	return SUCCESS;
}

void list2::print(int tab)
{
	int i;
	list2_node *curr;
	for (curr = head, i = 0; curr && i < list2::r; curr = curr->next, i++)
		curr->print(tab);
	printf("\n");
}

void list2::delete_list()
{
	list2_node *curr, *next;
	for (curr = head; curr; curr = next)
	{
		next = curr->next;
		delete curr;
	}
}

int list2::get_length()
{
	int res = 0;
	list2_node *curr;
	for (curr = head; curr; curr = curr->next)
		res++;
	return res;
}
