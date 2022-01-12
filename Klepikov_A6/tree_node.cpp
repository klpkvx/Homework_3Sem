#include "tree_node.h"
#include "student.h"

tree_node::tree_node(tree_node &&x) // работает или нет
{
	(Student &&)(*this) = x;
	left = x.left;
	right = x.right;
	x.left = nullptr;
	x.right = nullptr;
}

tree_node &tree_node::operator=(tree_node &&x)
{
	if (this == &x)
		return *this;
	(Student &&)(*this) = (Student &&) x;
	erase_links();
	x.erase_links();
	return *this;
}

tree_node::~tree_node()
{
	erase_links();
}

void tree_node::erase_links()
{
	left = nullptr;
	right = nullptr;
}

tree_node *tree_node::get_left(tree_node *x)
{
	return x->left;
}

tree_node *tree_node::get_right(tree_node *x)
{
	return x->right;
}