#include "tree.h"
#include "tree_node.h"
#include "math.h"
int tree::task001()
{
	if (root == nullptr)
		return 0;
	return task01(root);
}

int tree::task01(tree_node *curr) // количество концевых элементов дерева
{
	if (curr->left && curr->right)
		return task01(curr->left) + task01(curr->right);
	else
	{
		if (curr->left)
			return task01(curr->left);
		else
		{
			if (curr->right)
				return task01(curr->right);
			else
				return 1;
		}
	}
}

int tree::task002()
{
	if (root == nullptr)
		return 0;
	return task02(root);
}

int tree::task02(tree_node *curr) // длина наибольшей ветви этого дерева.
{
	if (curr->left && curr->right)
		return task02(curr->left) > task02(curr->right) ? task02(curr->left) + 1 : task02(curr->right) + 1;
	else
	{
		if (curr->left)
			return task02(curr->left) + 1;
		else if (curr->right)
			return task02(curr->right) + 1;
		else
			return 1;
	}
}
/*
int tree::task003()
{
}

int tree::task03(int level, tree_node *curr) // максимальгое колилчество в одном уровне tree
{
}
int tree::task004()
{
	if (root == nullptr)
		return 0;
	int res = 0;
	task04(root, &res);
	return res;
}
int tree::task04(tree_node *curr, int *res) // макс разность между глубинами
{
}*/
int tree::task005()
{
	if (root == nullptr)
		return 0;
	return task05(root);
}

int tree::task05(tree_node *curr) // один потомок
{

	if (curr->left && curr->right)
		return task05(curr->left) + task05(curr->right);
	if (curr->left)
		return task05(curr->left) + 1;
	if (curr->right)
		return task05(curr->right) + 1;
	return 0;
}