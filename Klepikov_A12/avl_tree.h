#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avl_tree_node.h"
#include "student.h"

template <class T>
class avl_tree
{
private:
	avl_tree_node<T> *root = nullptr;

public:
	avl_tree() = default;
	avl_tree(const avl_tree &x) = delete;
	avl_tree &operator=(const avl_tree &x) = delete;
	avl_tree(avl_tree<T> &&x) = delete;
	avl_tree &operator=(avl_tree &&x) = delete;
	~avl_tree()
	{
		if (!root)
			return;
		delete_subtree(root);
		root = nullptr;
	}
	int read(FILE *in)
	{
		avl_tree_node<T> x;
		int res = 0;
		while ((res = x.read(in)) == SUCCESS)
		{
			avl_tree_node<T> *curr = new avl_tree_node<T>((avl_tree_node<T> &&) x);
			if (!curr)
				return CANNOT_ALLOCATE;
			add_elem(curr);
		}
		if (!feof(in))
			return CANNOT_READ;
		return SUCCESS;
	}

	void add_elem(avl_tree_node<T> *x)
	{
		if (root == nullptr)
		{
			root = x;
			root->balance++;
			return;
		}
		else
			root = add_node(root, x);
	}

	avl_tree_node<T> *add_node(avl_tree_node<T> *curr, avl_tree_node<T> *x)
	{
		if (curr)
			curr->balance++;
		else
		{
			x->balance++;
			return x;
		}
		if (*x < *curr)
			curr->left = add_node(curr->left, x);
		else
			curr->right = add_node(curr->right, x);
		return balance(curr);
	}

	int getbalance(avl_tree_node<T> *curr) const
	{
		if (!curr)
			return 0;
		return curr->balance;
	}

	int diffbalance(avl_tree_node<T> *curr) const
	{
		return (getbalance(curr->right) - getbalance(curr->left));
	}

	void fixbalance(avl_tree_node<T> *curr)
	{
		int l = getbalance(curr->left);
		int r = getbalance(curr->right);
		curr->balance = (l > r ? l : r) + 1;
	}

	avl_tree_node<T> *balance(avl_tree_node<T> *curr)
	{
		fixbalance(curr);
		if (diffbalance(curr) == 2)
		{
			if (diffbalance(curr->right) < 0)
				curr->right = rotate_right(curr->right);
			return rotate_left(curr);
		}
		if (diffbalance(curr) == -2)
		{
			if (diffbalance(curr->left) > 0)
				curr->left = rotate_left(curr->left);
			return rotate_right(curr);
		}
		return curr;
	}

	avl_tree_node<T> *rotate_right(avl_tree_node<T> *curr)
	{
		avl_tree_node<T> *tmp = curr->left;
		curr->left = tmp->right;
		tmp->right = curr;
		fixbalance(curr);
		fixbalance(tmp);
		return tmp;
	}

	avl_tree_node<T> *rotate_left(avl_tree_node<T> *curr)
	{
		avl_tree_node<T> *tmp = curr->right;
		curr->right = tmp->left;
		tmp->left = curr;
		fixbalance(curr);
		fixbalance(tmp);
		return tmp;
	}

	void print(int r = 0) const
	{
		print_subtree(root, 0, r);
	}

	void print_subtree(avl_tree_node<T> *curr, int level, int r) const
	{
		if (!curr || level > r)
			return;

		for (int i = 0; i < level; i++)
			printf("  ");
		printf("[%2d] ", diffbalance(curr));

		curr->print(0);

		print_subtree(curr->left, level + 1, r);
		print_subtree(curr->right, level + 1, r);
	}
	void delete_subtree(avl_tree_node<T> *curr)
	{
		if (!curr)
			return;
		delete_subtree(curr->left);
		delete_subtree(curr->right);
		delete curr;
	}

	//________________________________________TASKS___________________TASKS___________________TASKS___________________TASKS___________________TASKS____________________________________________________________________________________________________________________________________________________
	int task1(int k)
	{
		if (k == 0)
			return 0;
		int res = 0;
		task11(root, &res, k);
		return res;
	}
	int task11(avl_tree_node<T> *curr, int *res, int k)
	{
		int count = 0;
		if (curr->right && curr->left)
		{
			count = task11(curr->left, res, k) + task11(curr->right, res, k) + 1;
			if (count <= k)
				*res += count;
			return count;
		}
		else
		{
			if (curr->right)
			{
				count = task11(curr->right, res, k) + 1;
				if (count <= k)
					*res += count;
				return count;
			}
			else
			{
				if (curr->left)
				{
					count = task11(curr->left, res, k) + 1;
					if (count <= k)
						*res += count;
					return count;
				}
				else
				{
					if (1 <= k)
						*res += 1;
					return 1;
				}
			}
		}
	}

	int task4(int k)
	{
		return task44(root, k);
	}
	int task44(avl_tree_node<T> *curr, int k)
	{
		if (k == 0)
			return 1;

		if (curr->left && curr->right)
			return task44(curr->left, k - 1) + task44(curr->right, k - 1);
		else
		{
			if (curr->left)
				return task44(curr->left, k - 1);
			else
			{
				if (curr->right)
					return task44(curr->right, k - 1);
				else
					return 0;
			}
		}
	}
	int task5(int k)
	{
		if (k == 0)
			return 0;
		int res = 0;
		task55(root, &res, k - 1);
		return res;
	}
	int task55(avl_tree_node<T> *curr, int *res, int k)
	{
		int count = 0;
		if (k > 0)
		{
			if (curr->left && curr->right)
			{
				count = task55(curr->left, res, k - 1) + task55(curr->right, res, k - 1);
				*res += count;
				return count;
			}
			else
			{
				if (curr->left)
				{
					count = task55(curr->left, res, k - 1);
					*res += count;
					return count;
				}
				else
				{
					if (curr->right)
					{
						count = task55(curr->right, res, k - 1);
						*res += count;
						return count;
					}
					else
						return 0;
				}
			}
		}
		else
		{
			if (!curr->left && !curr->right)
			{
				*res = *res + 1;
				return 1;
			}
			else
				return 0;
		}
	}
};
#endif // AVL_TREE_H
