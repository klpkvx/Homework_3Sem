#include "list.h"
#include "list_node.h"

//циклический сдвиг элементов списка на k позиций вправо.
void list::task01(int k)
{
	int i = 0;
	list_node *new_head = nullptr, *new_tail = nullptr, *tmp = nullptr;
	list_node *curr = head;

	if (!k)
		return;

	while (curr)
	{
		if (i == k)
		{
			new_head = curr;
			new_tail = tmp;
		}

		tmp = curr;
		curr = curr->next;
		i++;
	}

	if (new_head && new_tail)
	{
		head->prev = tmp;
		tmp->next = head;
		new_tail->next = nullptr;
		new_head->prev = nullptr;
		head = new_head;
	}
}

//выбрасывающую из него все элементы, большие какого-либо из k предыдущих элементов.
void list::task02(int k)
{
	int count = 1, len = 0, flag = 0;
	list_node *curr = head, *tmp = nullptr;

	for (curr = head; curr->next; curr = curr->next)
		count++;

	if (k > count || k <= 0)
		return;

	len = count - k;

	while (len)
	{
		flag = 0;
		count = k;
		tmp = curr->prev;
		while (count)
		{
			if (*curr > *tmp)
			{
				flag = 1;
				break;
			}
			tmp = tmp->prev;
			count--;
		}
		curr = curr->prev;
		if (flag)
			list_rm_element(curr->next);
		len--;
	}
}

//выбрасывающую из него все элементы, большие какого-либо из k следующих элементов.
void list::task03(int k)
{
	int count = 1, len = 0, flag = 0;
	list_node *curr = head, *tmp = nullptr;

	for (curr = head; curr->next; curr = curr->next)
		count++;

	if (k > count || k <= 0)
		return;

	len = count - k;
	curr = head;

	while (len)
	{
		tmp = curr->next;
		count = k;
		flag = 0;

		while (count)
		{
			if (*curr > *tmp)
			{
				flag = 1;
				break;
			}
			tmp = tmp->next;
			count--;
		}

		curr = curr->next;
		if (flag)
			list_rm_element(curr->prev);
		len--;
	}
}

//выбрасывающую из него все участки постоянства, имеющие длину не менее k (
//	участок удаляется целиком).
void list::task05(int k)
{
	int count = 0, len = 0;
	list_node *curr = head, *tmp = nullptr;

	len = get_len();

	if (k > len)
		return;

	while (curr->next)
	{
		count = 1;
		tmp = curr;
		if (*tmp == *tmp->next)
		{
			count++;
			tmp = tmp->next;

			while ((tmp->next) && (*tmp == *tmp->next))
			{
				count++;
				tmp = tmp->next;
			}

			if (count >= k)
			{
				curr = curr->next;
				list_rm_interval(curr, tmp);
				list_rm_element(tmp->prev);
				if (tmp->next)
				{
					curr = tmp->next;
					list_rm_element(tmp);
				}
				else
				{
					list_rm_element(tmp);
					break;
				}
			}
			else
			{
				if (tmp->next)
					curr = tmp->next;
				else
					break;
			}
		}
		else
			curr = curr->next;
	}
}

//выбрасывающую из него все участки нестрого убывания, имеющие длину не менее k
void list::task06(int k)
{
	int len = 0, count = 0;
	list_node *curr = head, *tmp = nullptr;

	len = get_len();
	if (k > len)
		return;
	if (k == 0 || k == 1)
		k = 2;

	while (curr->next)
	{
		if (*curr < *curr->next)
			curr = curr->next;
		else
		{
			count = 1;
			tmp = curr;
			if (*tmp->next == *tmp)
			{
				count++;
				tmp = tmp->next;
				while (tmp->next && *tmp->next == *tmp)
				{
					count++;
					tmp = tmp->next;
				}
				if (count == len)
				{
					curr = curr->next;
					while (curr != tmp)
					{
						list_rm_element(curr->prev);
						curr = curr->next;
					}
					list_rm_element(tmp->prev);
					list_rm_element(tmp);
					return;
				}
				if (tmp->next)
				{
					if (*tmp < *tmp->next)
						curr = tmp->next;
					else
					{
						while (tmp->next && (*tmp > *tmp->next || *tmp == *tmp->next))
						{
							count++;
							tmp = tmp->next;
						}
						if (k <= count)
						{
							curr = curr->next;
							while (curr != tmp)
							{
								list_rm_element(curr->prev);
								curr = curr->next;
							}
							list_rm_element(tmp->prev);
							if (tmp->next)
							{
								curr = tmp->next;
								list_rm_element(curr->prev);
							}
							else
							{
								list_rm_element(tmp);
								break;
							}
						}
						else
						{
							if (tmp->next)
								curr = tmp->next;
							else
								break;
						}
					}
				}
				else
					break;
			}
			else
			{
				while (tmp->next && (*tmp > *tmp->next || *tmp == *tmp->next))
				{
					count++;
					tmp = tmp->next;
				}
				if (k <= count)
				{
					curr = curr->next;
					while (curr != tmp)
					{
						list_rm_element(curr->prev);
						curr = curr->next;
					}
					list_rm_element(tmp->prev);
					if (tmp->next)
					{
						curr = curr->next;
						list_rm_element(curr->prev);
					}
					else
					{
						list_rm_element(tmp);
						break;
					}
				}
				else
				{
					if (tmp->next)
						curr = tmp->next;
					else
						break;
				}
			}
		}
	}
}