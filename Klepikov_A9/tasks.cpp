#include "tree_node.h"
#include "tree.h"
#include "student.h"

int tree::task1(int k)
{
	int count = 0;
	if (k < 0)
		return 0;

	task11(root, k, &count);

	return count;
}

int tree::task11(tree_node *curr, int k, int *count) // число потомков на одном уровне равное числу k
{
	if (curr->down)
	{
		if (task11(curr->down, k, count) == k)
			*count += 1;
	}
	else
	{
		if (k == 0)
			*count += 1;
	}
	if (curr->level)
	{
		return task11(curr->level, k, count) + 1;
	}
	else
		return 1;
}

int tree::task2(int k) // количество элементов в поддеревьях, имеющих <=k вершин
{
	int count = 0;
	if (k <= 0)
		return 0;

	task22(root, k, &count);

	return count;
}

int tree::task22(tree_node *curr, int k, int *count) // элементы в поддеревьях не более k вершин
{
	int count0 = 0;
	if (curr->down && curr->level)
	{
		count0 = task22(curr->down, k, count) + 1;
		if (count0 <= k)
			*count += count0;
		return task22(curr->level, k, count) + count0;
	}
	else
	{
		if (curr->level == nullptr && curr->down)
		{
			count0 = task22(curr->down, k, count) + 1;
			if (count0 <= k)
				*count += count0;
			return count0;
		}
		if (curr->level && curr->down == nullptr)
		{
			*count += 1;
			return task22(curr->level, k, count) + 1;
		}
		if (curr->level == nullptr && curr->down == nullptr)
		{
			*count += 1;
			return 1;
		}
	}
	return count0;
}

int tree::task3(int k)
{
	int count = 0;
	task33(root, k, &count);
	return count;
}

int tree::task33(tree_node *curr, int k, int *count) // количество элементов в поддеревьях, имеющих не более k уровней.
{
	int count_down = 0;
	int count_lvl = 0;
	if (curr->down && curr->level)
	{
		count_down = task33(curr->down, k, count) + 1;
		count_lvl = task33(curr->level, k, count);
		if (count_down <= k)
			*count = *count + task333(curr->down) + 1;
		if (count_down > count_lvl)
			return count_down;
		else
			return count_lvl;
	}
	else if (curr->level)
	{
		*count += 1;
		return task33(curr->level, k, count);
	}
	else if (curr->down)
	{
		count_down = task33(curr->down, k, count) + 1;
		if (count_down <= k)
			*count = *count + task333(curr->down) + 1;
		return count_down;
	}
	*count += 1;
	return 1;
}
int tree::task333(tree_node *curr)
{
	if (curr->level && curr->down)
		return task333(curr->down) + task333(curr->level) + 1;
	else if (curr->down)
		return task333(curr->down) + 1;
	else if (curr->level)
		return task333(curr->level) + 1;
	return 1;
}

int tree::task5(int k) // количество элементов на k-м уровне
{
	return task55(root, k);
}

int tree::task55(tree_node *curr, int k)
{
	int count = 0;
	if (k != 0)
	{
		if (curr->down && curr->level)
			return task55(curr->down, k - 1) + task55(curr->level, k);
		else
		{
			if (curr->down)
				return task55(curr->down, k - 1);
			else
			{
				if (curr->level)
					return task55(curr->level, k);
				else
				{
					if (!curr->level && !curr->down)
						return 0;
				}
			}
		}
	}
	else
	{
		while (curr->level)
		{
			count += 1;
			curr = curr->level;
		}
	}
	return count + 1;
}

int tree::task6(int k) // количество элементов во всех ветвях длины не менее k начиная с окрня
{
	int count = 0;
	task66(root, k, 1, &count);
	return count;
}

void tree::task66(tree_node *curr, int k, int lvl, int *count)
{
	if (curr->down)
		task66(curr->down, k, lvl + 1, count);
	else
	{
		if (lvl >= k)
			*count += lvl;
	}
	if (curr->level)
	{
		task66(curr->level, k, lvl, count);
	}
}