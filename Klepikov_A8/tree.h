#ifndef node_H
#define node_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum
{
	FIILE,
	MEM,
	OK
};

class node
{
private:
	char *name = nullptr;
	node *left = nullptr;
	node *right = nullptr;
	node *center = nullptr;

public:
	node() = default;
	node(const node &x) = delete;
	node(node &&x)
	{
		name = x.name;
		x.name = nullptr;
	}
	~node()
	{
		erase_links();
		delete[] name;
		name = nullptr;
	}
	int read(FILE *in)
	{
		char buf[1234];
		if (!fgets(buf, 1234, in))
		{
			return FIILE;
		}
		size_t len = strlen(buf);
		name = new char[len + 1];
		if (!name)
			return MEM;
		for (size_t i = 0; i <= len; i++)
		{
			name[i] = buf[i];
		}
		return OK;
	}

	node &operator=(const node &x) = delete;
	node &operator=(node &&x)
	{
		if (this == &x)
			return *this;
		name = x.name;
		x.name = nullptr;
		return *this;
	}
	int operator>(const node &x)
	{
		int r = strcmp(this->name, x.name);
		if (r > 0)
			return 1;
		return 0;
	}
	int operator<(const node &x)
	{
		int r = strcmp(this->name, x.name);
		if (r < 0)
			return 1;
		return 0;
	}
	friend class tree;

private:
	void erase_links()
	{
		left = nullptr;
		right = nullptr;
		center = nullptr;
	}
};

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
	int read(FILE *in)
	{
		node vsp;
		while (vsp.read(in) == OK)
		{
			node *now = new node((node &&) vsp);
			if (!now)
				return MEM;
			add_node(now);
		}
		return OK;
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
	void print()
	{
		if (root)
			rec_pr(root, 0, 9);
	}
	int task()
	{
		if (root)
			return rec_task(root);
		return 0;
	}
	~tree()
	{
		delete_subtree(root);
		root = nullptr;
	}

private:
	void delete_subtree(node *curr)
	{
		if (!curr)
			return;
		delete_subtree(curr->left);
		delete_subtree(curr->right);
		delete_subtree(curr->center);
		delete curr;
	}
	void rec_pr(node *curr, int lvl, int vse)
	{
		if (!curr)
			return;
		if (lvl >= vse)
			return;
		for (int i = 0; i < lvl; i++)
		{
			printf("  ");
		}
		printf("%s\n", curr->name);
		rec_pr(curr->left, lvl + 1, vse);
		rec_pr(curr->center, lvl + 1, vse);
		rec_pr(curr->right, lvl + 1, vse);
	}
	int rec_task(node *curr)
	{
		if (!curr)
			return 0;
		int count = rec_task(curr->left);
		count += rec_task(curr->center);
		count += rec_task(curr->right);
		return (count > 0 ? count : 1);
	}

	void add_node_subtree(node *curr, node *x)
	{
		if ((*curr < *x))
		{
			if (curr->right)
			{
				add_node_subtree(curr->right, x);
				return;
			}
			curr->right = x;
			x->erase_links();
			return;
		}

		if ((*curr > *x))
		{
			if (curr->left)
			{
				add_node_subtree(curr->left, x);
				return;
			}
			curr->left = x;
			x->erase_links();
			return;
		}

		if (curr->center)
		{
			add_node_subtree(curr->center, x);
			return;
		}
		curr->center = x;
		x->erase_links();
	}
};

#endif
