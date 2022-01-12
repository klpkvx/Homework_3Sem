#ifndef TREE_H
#define TREE_H

#include "student.h"
#include "tree_node.h"

class tree
{
private:
	tree_node *root = nullptr;

public:
	tree() = default;
	tree(const tree &x) = delete;
	tree(tree &&x);
	~tree();

	tree &operator=(const tree &x) = delete;
	tree &operator=(tree &&x);

	void tree_print(int r) const;
	int tree_read(char *filename);

private:
	void delete_subtree(tree_node *curr);
	void print_subtree(tree_node *curr, int level, int r) const;
	void add_node_subtree(tree_node *curr, tree_node *x);

public:
	int task1(int k);
	int task11(tree_node *curr, int k, int *res);

	int task2(int k);
	int task22(tree_node *curr, int k, int *res);

	int task3(int k);
	int task33(tree_node *curr, int k, int *res);

	int task4(int k);
	int task44(tree_node *curr, int k, int *res);

	int task5(int k);
	int task55(tree_node *curr, int k);
};
#endif // TREE_H