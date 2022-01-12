#ifndef TREE_H
#define TREE_H

#include "tree_node.h"
#include <stdlib.h>

template <class T>
class tree
{
private:
	tree_node<T> *root = nullptr;

public:
	tree() = default;
	tree(const tree &x) = delete;
	tree(tree &&x)
	{
		root = x.root;
		x.root = nullptr;
	}
	~tree()
	{
		delete_subtree(root);
		root = nullptr;
	}

	tree &operator=(const tree &x) = delete;
	tree &operator=(tree &&x)
	{
		root = x.root;
		x.root = nullptr;
		return *this;
	}

	void print(int r)
	{
		if (root)
			print_node(root, 0, r);
	}

	int read(FILE *fp)
	{
		tree_node<T> x;
		while (x.read(fp) == SUCCESS)
		{
			tree_node<T> *curr = new tree_node<T>((tree_node<T> &&) x);
			if (!curr)
				return CANNOT_ALLOCATE;
			if (!root)
				root = curr;
			else
				add_node_subtree(root, curr);
		}
		if (!feof(fp))
			return CANNOT_READ;
		return SUCCESS;
	}

private:
	static void delete_subtree(tree_node<T> *curr)
	{
		if (!curr)
			return;
		if (curr->left)
		{
			delete_subtree(curr->left);
			curr->left = nullptr;
		}
		if (curr->right)
		{
			delete_subtree(curr->right);
			curr->right = nullptr;
		}
		delete curr;
		curr = nullptr;
	}

	static void add_node_subtree(tree_node<T> *curr, tree_node<T> *x)
	{
		if ((*x < *curr) > 0)
		{
			if (curr->left == nullptr)
				curr->left = x;
			else
				add_node_subtree(curr->left, x);
		}
		else
		{
			if (curr->right == nullptr)
				curr->right = x;
			else
				add_node_subtree(curr->right, x);
		}
	}

	static void print_node(tree_node<T> *curr, int lvl, int r)
	{
		if (r < lvl)
			return;
		int tab = lvl * 2;
		curr->print(tab);
		if (curr->left)
			print_node(curr->left, lvl + 1, r);
		if (curr->right)
			print_node(curr->right, lvl + 1, r);
	}

public:
	int task1()
	{
		int count = 0;
		if (root)
			task11(root, count);
		return count;
	}
	void task11(tree_node<T> *curr, int &count)
	{
		if (!curr)
			return;

		task11(curr->left, count);
		task11(curr->right, count);

		if (!curr->left && !curr->right)
			count += curr->get_length();
	}

	int task2()
	{
		int len = 0;
		if (root)
			len = task22(root);
		return len;
	}
	int task22(tree_node<T> *curr)
	{
		int l_branch = 0, r_branch = 0, mx_branch = 0;
		if (!curr)
			return 0;

		l_branch = task22(curr->left);
		r_branch = task22(curr->right);

		if (r_branch >= l_branch)
			mx_branch = r_branch;
		else
			mx_branch = l_branch;

		return curr->get_length() + mx_branch;
	}

	int task3()
	{
		int lvl = 2, res = 1, count = 0;
		if (!root)
			return 0;

		count = root->get_length();
		while (res)
		{
			res = 0;
			task33(root, lvl, 1, res);
			if (res > count)
				count = res;
			lvl++;
		}

		return count;
	}
	void task33(tree_node<T> *curr, int lvl, int curr_lvl, int &res)
	{
		if (!curr || curr_lvl > lvl)
			return;
		if (lvl == curr_lvl)
		{
			res += curr->get_length();
			return;
		}
		task33(curr->left, lvl, curr_lvl + 1, res);
		task33(curr->right, lvl, curr_lvl + 1, res);
	}

	int task4()
	{
		if (!root)
			return 0;
		int mx = 0;

		task44(root, mx);
		return mx;
	}

	void task44(tree_node<T> *curr, int &res)
	{
		int l_branch = 0, r_branch = 0, mx_diff = 0;
		if (!curr)
			return;

		l_branch = task444(curr->left);
		r_branch = task444(curr->right);

		mx_diff = abs(l_branch - r_branch);
		if (res < mx_diff)
			res = mx_diff;
		task44(curr->right, res);
		task44(curr->left, res);
	}

	int task444(tree_node<T> *curr)
	{
		if (!curr)
			return 0;
		return task444(curr->left) + task444(curr->right) + curr->get_length();
	}

	int task5()
	{
		return task55(root);
	}

	int task55(tree_node<T> *curr)
	{
		if (curr->left && curr->right)
			return task55(curr->left) + task55(curr->right);
		else if (curr->left)
			return task55(curr->left) + curr->get_length();
		else if (curr->right)
			return task55(curr->right) + curr->get_length();
		return 0;
	}
};
#endif // TREE_H