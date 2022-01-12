#include "tree.h"
#include "tree_node.h"

tree::~tree()
{
	delete_subtree(root);
	root = nullptr;
}

void tree::delete_subtree(tree_node *curr)
{
	if (curr == nullptr)
		return;
	delete_subtree(curr->left);
	delete_subtree(curr->right);
	delete curr;
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

int tree::read(const char *filename) // ????
{
	tree_node x;
	tree_node *curr = nullptr;

	FILE *fp = nullptr;

	fp = fopen(filename, "r");

	if (!fp)
		return CANNOT_OPEN;

	while (x.read(fp) == SUCCESS)
	{
		curr = new tree_node((tree_node &&) x);

		if (!curr)
		{
			fclose(fp);
			return CANNOT_ALLOCATE;
		}

		if (root == nullptr)
			root = curr;
		else
			add_node_subtree(root, curr);
	}

	if (!feof(fp))
	{
		fclose(fp);
		return CANNOT_READ;
	}

	fclose(fp);
	return 0;
}

void tree::print_subtree(tree_node *curr, int level, int r) const
{
	int spaces = level * 2;

	if (curr == nullptr || level > r)
		return;

	for (int i = 0; i < spaces; i++)

	{	printf(" ");}
	curr->print();
	if (curr->left)
		print_subtree(curr->left, level + 1, r);
	if (curr->right)
		print_subtree(curr->right, level + 1, r);
}

void tree::print(int r) const
{
	if (root != nullptr)
		print_subtree(root, 0, r);
}

tree::tree(tree &&x)
{
	root = x.root;
	x.root = nullptr;
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