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
			fclose(fp);
			return CANNOT_ALLOCATE;
		}
		*tail = (list_node &&) buf;
		curr->next = tail;
		tail->prev = curr;

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

void list::list_rm_element(list_node *r)
{
	if (r == head && head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	if (!r->next)
	{
		r->prev->next = nullptr;
		r->prev = nullptr;
		delete r;
	}
	else
	{
		if (r == head)
		{
			head = r->next;
			head->prev = nullptr;
			r->next = nullptr;
			delete r;
		}
		else
		{
			r->prev->next = r->next;
			r->next->prev = r->prev;
			r->prev = nullptr;
			r->next = nullptr;
			delete r;
		}
	}
}
void list::del(list_node *x)
{
	if (x == head && head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	if (!x->next)
	{
		x->prev->next = nullptr;
		x->prev = nullptr;
		delete x;
		return;
	}
	if (x == head)
	{
		head = x->next;
		head->prev = nullptr;
		x->next = nullptr;
		delete x;
		return;
	}
	x->prev->next = x->next;
	x->next->prev = x->prev;
	x->prev = nullptr;
	x->next = nullptr;
	delete x;
}
void list::list_rm_interval(list_node *curr, list_node *tmp)
{
	list_node *temp = nullptr; //r
	temp = curr->prev;
	while (curr != tmp)
	{
		temp = curr->prev;
		if (temp == head && head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		if (!temp->next)
		{
			temp->prev->next = nullptr;
			temp->prev = nullptr;
			delete temp;
		}
		else
		{
			if (temp == head)
			{
				head = temp->next;
				head->prev = nullptr;
				temp->next = nullptr;
				delete temp;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp->prev = nullptr;
				temp->next = nullptr;
				delete temp;
			}
		}
		curr = curr->next;
	}
}