#include "tree.h"
#include "student.h"
#include "tree_node.h"

tree::tree(tree &&x)
{
	root = x.root;
	x.root = nullptr;
}

tree::~tree()
{
	delete_subtree(root);
	root = nullptr;
}

tree &tree::operator=(tree &&x)
{
	if (this == &x)
		return *this;
	delete_subtree(root);
	root = x.root;
	x.root = nullptr;
	return *this;
}

void tree::tree_print(int r) const
{
	print_subtree(root, 0, r);
}

void tree::delete_subtree(tree_node *curr)
{
	if (curr == nullptr)
		return;
	tree_node *p, *next;
	for (p = curr->down; p; p = next)
	{
		next = p->level;
		delete_subtree(p);
	}
	delete curr;
}

void tree::print_subtree(tree_node *curr, int level, int r) const
{
	if (curr == nullptr || level > r)
		return;
	int spaces = level * 2;
	for (int i = 0; i < spaces; i++)
		printf(" ");
	curr->print();
	for (tree_node *p = curr->down; p; p = p->level)
		print_subtree(p, level + 1, r);
}

int tree::tree_read(char *filename)
{
	tree_node x;
	int err = 0;
	FILE *fp = fopen(filename, "r");
	if (!fp)
		return CANNOT_OPEN;

	if (x.read(fp) != SUCCESS)
	{
		fclose(fp);
		return CANNOT_READ;
	}
	tree_node *curr = new tree_node((tree_node &&) x);
	if (!curr)
	{
		fclose(fp);
		return CANNOT_ALLOCATE;
	}

	root = curr;
	while ((err = x.read(fp)) == SUCCESS)
	{
		curr = new tree_node((tree_node &&) x);
		if (!curr)
			return CANNOT_ALLOCATE;
		add_node_subtree(root, curr);
	}
	if (!feof(fp))
	{
		fclose(fp);
		return CANNOT_READ;
	}
	if (err == 900)
	{
		fclose(fp);
		return CANNOT_READ;
	}
	fclose(fp);
	return SUCCESS;
}

void tree::add_node_subtree(tree_node *curr, tree_node *x)
{
	if (curr->down == nullptr)
	{ // No any child node
		curr->down = x;
		return;
	}
	if (*x < *curr)
	{
		if (*curr->down < *curr)
			// head of the list of child nodes < *curr
			add_node_subtree(curr->down, x);
		else
		{
			x->level = curr->down;
			curr->down = x;
		}
	}
	else if (*x == *curr)
	{
		if (curr->down->level != nullptr)
		{
			x->level = curr->down->level;
			curr->down->level = x;
		}
		else if (*curr->down < *curr)
		{
			curr->down->level = x;
		}
		else
		{
			x->level = curr->down;
			curr->down = x;
		}
	}
	else // *x > *curr
	{
		tree_node *p;
		for (p = curr->down; p->level; p = p->level)
			;
		if (*p > *curr)
			// tail of the list of child nodes > *curr
			add_node_subtree(p, x);
		else
			p->level = x; // append at end of the list
	}
}