#include "tree_node.h"
#include "tree.h"
#include "student.h"

int tree::task1(int k)
{
	int count = 0;
	if (k <= 0)
		return 0;

	task11(root, k, &count);

	return count;
}

int tree::task11(tree_node *curr, int k, int *count) // поддеревья не более к вершин
{
	int count0 = 0;

	if (curr->left && curr->right)
	{
		count0 = task11(curr->left, k, count) + task11(curr->right, k, count);
		if (count0 + 1 <= k)
			*count += 1;
	}
	else
	{
		if (curr->right)
		{
			count0 = task11(curr->right, k, count);
			if (count0 + 1 <= k)
				*count += 1;
		}
		else
		{
			if (curr->left)
			{
				count0 = task11(curr->left, k, count);
				if (count0 + 1 <= k)
					*count += 1;
			}
			else
				*count += 1;
		}
	}

	return count0 + 1;
}
