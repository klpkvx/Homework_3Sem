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
	if (curr->left)
		delete_subtree(curr->left);
	if (curr->right)
		delete_subtree(curr->right);
	delete curr;
}

void tree::print_subtree(tree_node *curr, int level, int r) const
{
	int spaces = level * 2;

	if (r < level || !curr)
		return;
	for (int i = 0; i < spaces; i++)
		printf(" ");
	curr->print();
	print_subtree(curr->left, level + 1, r);
	print_subtree(curr->right, level + 1, r);
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
	if (*x < *curr)
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