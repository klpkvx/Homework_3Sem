#include "list.h"
#include "list_node.h"

void list::task01()
{
	if (!head || !head->next)
		return;
	list_node *tmp = nullptr, *head_new = nullptr, *curr = head;
	while (head->next)
	{
		curr = head;
		if (*curr->next < *curr)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			tmp->next = curr;
			head = tmp;
		}
		else
		{
			tmp = curr;
			curr = curr->next;
		}
		while (curr->next)
		{
			if (*curr->next < *curr)
			{
				tmp->next = curr->next;
				curr->next = curr->next->next;
				tmp = tmp->next;
				tmp->next = curr;
			}
			else
			{
				tmp = curr;
				curr = curr->next;
			}
		}
		tmp->next = nullptr;
		tmp = head_new;
		head_new = curr;
		head_new->next = tmp;
	}
	head->next = head_new;
}

void list::task02()
{
	if (!head || !head->next)
		return;
	list_node *prev = head, *curr = prev->next;
	list_node *head_new = nullptr, *tail_new = head;
	list_node *min = head, *tmp = nullptr;
	while (head->next)
	{
		prev = head;
		curr = head->next;
		while (curr)
		{
			if (*curr < *min)
			{
				min = curr;
				tmp = prev;
			}
			prev = curr;
			curr = curr->next;
		}
		if (tmp)
		{
			tmp->next = min->next;
			min->next = nullptr;
		}
		else
			head = head->next;
		if (!head_new)
		{
			head_new = min;
			tail_new = min;
		}
		else
		{
			tail_new->next = min;
			tail_new = tail_new->next;
		}
		min = head;
		tmp = nullptr;
	}
	tail_new->next = head;
	head = head_new;
}

void list::task03()
{
	if (!head || !head->next)
		return;
	list_node *tmp = head->next, *head_new = nullptr;
	list_node *curr = nullptr, *prev = head_new;
	head->next = nullptr;
	head_new = head;
	head = tmp;
	while (head)
	{
		tmp = head->next;
		head->next = nullptr;
		curr = head_new;
		while (curr && *head > *curr)
		{
			prev = curr;
			curr = curr->next;
		}
		if (!prev)
		{
			head->next = head_new;
			head_new = head;
		}
		else
		{
			prev->next = head;
			head->next = curr;
		}
		prev = nullptr;
		head = tmp;
	}
	head = head_new;
}

void list::task04()
{
	list_node *curr, *tmp;
	list_node *tail = nullptr, *swap = nullptr;

	list_node *head_a = nullptr, *tail_a = nullptr, *curr_a = nullptr;
	list_node *head_b = nullptr, *tail_b = nullptr, *curr_b = nullptr;
	list_node *head_c = nullptr, *tail_c = nullptr, *curr_c = nullptr;

	int len = 100, len_a = 0, len_b = 0;
	int flag = 0, end = 1;
	int first = 0, first_a = 0, first_b = 0;

	if (!head || !head->next)
		return;

	if (!head->next->next)
	{
		if (*head > *head->next)
		{
			tail = head->next;
			swap = tail;
			head->next = tail->next;
			tail->next = head;
			head = swap;
		}
		else
			return;
	}

	while (end < len && head)
	{
		first = 0, first_a = 0, first_b = 0;
		len_a = 0, len_b = 0;

		for (curr = head; curr; curr = curr->next)
		{
			if (!flag)
				len++;

			if (len_a == end && len_b == end)
			{
				first_a = 0;
				first_b = 0;
				len_a = 0;
				len_b = 0;
				tail_a->next = nullptr;
				tail_b->next = nullptr;
				curr_a = head_a;
				curr_b = head_b;
				curr_c = tail_c;

				while (curr_a && curr_b)
				{
					if (*curr_a < *curr_b)
					{
						if (first)
						{
							curr_c->next = curr_a;
							curr_c = curr_c->next;
						}
						else
						{
							head_c = curr_a;
							curr_c = head_c;
							first++;
						}
						curr_a = curr_a->next;
					}
					else
					{
						if (first)
						{
							curr_c->next = curr_b;
							curr_c = curr_c->next;
						}
						else
						{
							head_c = curr_b;
							curr_c = head_c;
							first++;
						}
						curr_b = curr_b->next;
					}
				}

				while (curr_a)
				{
					curr_c->next = curr_a;
					curr_c = curr_c->next;
					curr_a = curr_a->next;
				}

				while (curr_b)
				{
					curr_c->next = curr_b;
					curr_c = curr_c->next;
					curr_b = curr_b->next;
				}

				tail_c = curr_c;
				tmp = curr;
				head_a = tmp;
				tail_a = head_a;
				head_b = nullptr;
				first_a++;
				len_a++;
			}

			else if (len_a < end && !first_a)
			{
				tmp = curr;
				head_a = tmp;
				tail_a = head_a;
				len_a++;
				first_a++;
			}

			else if (len_a < end)
			{
				tmp = curr;
				tail_a->next = tmp;
				tail_a = tail_a->next;
				len_a++;
			}

			else if (len_b < end && !first_b)
			{
				tmp = curr;
				head_b = tmp;
				tail_b = head_b;
				len_b++;
				first_b++;
			}

			else if (len_b < end)
			{
				tmp = curr;
				tail_b->next = tmp;
				tail_b = tail_b->next;
				len_b++;
			}
		}
		tail_c->next = nullptr;

		if (!flag)
		{
			flag++;
			len = len - 100;
		}

		if (len_a > 0)
		{
			first_a = 0;
			first_b = 0;
			len_a = 0;
			len_b = 0;
			tail_a->next = nullptr;
			curr_a = head_a;
			curr_b = head_b;
			curr_c = tail_c;

			while (curr_a && curr_b)
			{
				if (*curr_a < *curr_b)
				{
					if (first)
					{
						curr_c->next = curr_a;
						curr_c = curr_c->next;
					}
					else
					{
						head_c = curr_a;
						curr_c = head_c;
						first++;
					}
					curr_a = curr_a->next;
				}
				else
				{
					if (first)
					{
						curr_c->next = curr_b;
						curr_c = curr_c->next;
					}
					else
					{
						head_c = curr_b;
						curr_c = head_c;
						first++;
					}
					curr_b = curr_b->next;
				}
			}

			while (curr_a)
			{
				curr_c->next = curr_a;
				curr_c = curr_c->next;
				curr_a = curr_a->next;
			}

			while (curr_b)
			{
				curr_c->next = curr_b;
				curr_c = curr_c->next;
				curr_b = curr_b->next;
			}

			tail_c = curr_c;
		}
		tail_c->next = nullptr;
		head = head_c;
		end *= 2;
	}
}