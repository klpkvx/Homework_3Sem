#ifndef TREE_H
#define TREE_H

#include "node.h"

class tree
{
private:
	node *root = nullptr;

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
		if (!root)
			return;
		delete_subtree(root);
		root = nullptr;
	};

	tree &operator=(const tree &x) = delete;
	tree &operator=(tree &&x)
	{
		if (this == &x)
			return *this;
		delete_subtree(root);
		root = x.root;
		x.root = nullptr;
		return *this;
	}

	void delete_subtree(node *curr)
	{
		if (curr == nullptr)
			return;
		if (curr->left)
			delete_subtree(curr->left);
		if (curr->center)
			delete_subtree(curr->center);

		if (curr->right)
			delete_subtree(curr->right);
		delete curr;
	}

	int read(const char *filename)
	{
		node tmp;
		FILE *fp = fopen(filename, "r");
		if (!fp)
			return CANNOT_READ;
		while (tmp.read(fp) == SUCCESS)
		{
			node *curr = new node((node &&) tmp);
			if (!curr)
				return CANNOT_ALLOCATE;
			add_node(curr);
		}
		fclose(fp);
		return SUCCESS;
	}
	void tree_print() const
	{
		if (root)
			print_subtree(root, 0, 100);
	}
	void print_subtree(node *curr, int level, int r) const
	{

		if (r <= level || !curr)
			return;
		for (int i = 0; i < level; i++)
			printf(" ");
		printf("%s\n", curr->name);
		print_subtree(curr->left, level + 1, r);
		print_subtree(curr->center, level + 1, r);
		print_subtree(curr->right, level + 1, r);
	}

	int tree_read(char *filename)
	{

		node x;
		FILE *fp = fopen(filename, "r");
		if (!fp)
			return CANNOT_OPEN;

		while (x.read(fp) == SUCCESS)
		{
			node *curr = new node((node &&) x);
			if (!curr)
			{
				fclose(fp);
				return CANNOT_ALLOCATE;
			}
			add_node(curr);
		}
		fclose(fp);
		return SUCCESS;
	}

	void add_node(node *x)
	{
		if (!root)
		{
			root = x;
			root->erase_links();
			return;
		}
		add_node_subtree(root, x);
	}

	void add_node_subtree(node *curr, node *x)
	{
		if (*x < *curr)
		{
			if (!curr->left)
				curr->left = x;
			else
				add_node_subtree(curr->left, x);
		}
		else
		{
			if (*x > *curr)
				if (!curr->right)
					curr->right = x;
				else
					add_node_subtree(curr->right, x);
			else
			{
				if (!curr->center)
					curr->center = x;
				else
					add_node_subtree(curr->center, x);
			}
		}
	}

	int task1()
	{
		return task11(root);
	}

	int task11(node *curr)
	{
		int res = 0;
		if (!curr)
			return 0;
		res = task11(curr->left);
		res += task11(curr->center);
		res += task11(curr->right);
		if (res > 0)
			return res;
		else
			return 1;
	}
};
#endif // TREE_H