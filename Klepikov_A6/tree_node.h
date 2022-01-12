#ifndef TREE_NODE_H
#define TREE_NODE_H
#include "student.h"

class tree_node : public Student
{
private:
	tree_node *left = nullptr;
	tree_node *right = nullptr;
	friend class tree;

public:
	tree_node() = default;
	tree_node(const tree_node &x) = delete;
	tree_node(tree_node &&x);
	~tree_node();

	tree_node &operator=(const tree_node &x) = delete;
	tree_node &operator=(tree_node &&x);

	tree_node *get_left(tree_node *x);
	tree_node *get_right(tree_node *x);

	void erase_links();
};

#endif // TREE_NODE_H