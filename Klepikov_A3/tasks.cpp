#include "tasks.h"
#include "student.h"

int task01(list_node *head)
{
	int count = 0;
	list_node *curr;
	list_node *mx;
	mx = head;
	for (curr = head; curr; curr = curr->get_next())
	{
		if (*mx < *curr)
		{
			mx = curr;
			count = 1;
		}
		else
		{
			if (*curr == *mx)
				count++;
		}
	}
	return count;
}

int task02(list_node *head) // кол-во элементов больших предыдущего
{
	int count = 0;

	list_node *prev = head, *curr;

	for (curr = head->get_next(); curr; curr = curr->get_next())
	{
		if ((*curr > *prev) > 0)
			count++;

		prev = curr;
	}

	return count;
}

int task03(list_node *head) //количество локальных максимумов этого списка.
{
	int count = 0;
	list_node *curr, *prev, *next;
	curr = head;
	prev = curr;
	curr = curr->get_next();
	if (!curr)
		return 0;
	next = curr->get_next();
	if (!next)
		return 0;
	while (next)
	{
		if ((*curr > *prev || *curr == *prev) && (*curr > *next || *curr == *next)) // (*curr < prev || *curr < *next)
			count++;
		prev = curr;
		curr = next;
		next = curr->get_next();
	}
	return count;
}

//1 если список возрастает
//2 если список убывает
//3 если постоянен
//4  недостаточно данных
// 0 не монотонен
int task04(list_node *head)
{
	int status = 0;
	list_node *prev, *curr;

	prev = head;
	curr = prev->get_next();

	if (!curr)
		return 4;

	if (*prev < *curr)
		status = 1;
	else
	{
		if (*prev > *curr)
			status = 2;
		else
			status = 3;
	}

	prev = curr;
	curr = curr->get_next();

	while (curr)
	{
		if (*curr > *prev)
		{
			if (status == 1 || status == 3)
				status = 1;
			else
				return 0;
		}
		else
		{
			if (*curr < *prev)
			{
				if (status == 2 || status == 3)
					status = 2;
				else
					return 0;
			}
		}
		prev = curr;
		curr = curr->get_next();
	}

	return status;
}

int task05(list_node *head)
{
	list_node *prev, *curr;
	int count = 0, mx_count = 0;

	prev = head;
	curr = prev->get_next();

	while (curr)
	{
		if (*curr > *prev)
			count++;
		else
		{
			if (mx_count < count)
				mx_count = count;
			count = 0;
		}
		prev = curr;
		curr = curr->get_next();
	}

	if (mx_count < count)
		mx_count = count;

	return (mx_count ? mx_count + 1 : 0);
}

int task06(list_node *head) //кол-во участков постоянства
{
	list_node *curr, *prev;
	int count = 0, flag = 0;

	prev = head;
	curr = prev->get_next();

	if (!curr)
		return 0;

	while (curr)
	{
		if (*curr == *prev)
			flag = 1;
		else
		{
			if (flag)
				count++;
			flag = 0;
		}
		prev = curr;
		curr = curr->get_next();
	}

	return (flag ? count + 1 : count);
}

int task07(list_node *head) //максимальное расстояние между соседними участками постоянства.
{
	list_node *prev, *curr;
	int flag = 0, len = 0, mx = 0, first = 0;

	prev = head;
	curr = head->get_next();

	while (curr)
	{
		if (*curr == *prev)
		{
			first++;
			flag = 1;

			if (len > mx)
				mx = len;
			len = 0;
		}
		else
		{
			if (flag)
			{
				flag = 0;
				len = 0;
			}
			if (!flag && first)
				len++;
		}

		prev = curr;
		curr = curr->get_next();
	}

	return (mx ? mx - 1 : mx);
}
