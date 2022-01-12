#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "student.h"

class tree_node : public Student
{
private:
	tree_node *right = nullptr;
	tree_node *left = nullptr;
	friend class tree;

public:
	tree_node() = default;
	tree_node(const tree_node &r) = delete;
	tree_node(tree_node &&r);
	~tree_node();

	tree_node &operator=(const tree_node &r) = delete;
	tree_node &operator=(tree_node &&r);
	void erase_links();

	tree_node *get_left(tree_node *r);
	tree_node *get_right(tree_node *r);
};

#endif // TREE_NODE_H