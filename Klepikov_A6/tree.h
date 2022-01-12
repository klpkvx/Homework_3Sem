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

	int read(const char *filename);
	void print(int r) const;

private:
	void delete_subtree(tree_node *root);
	void add_node_subtree(tree_node *root, tree_node *x);
	void print_subtree(tree_node *curr, int level, int r) const;

public:
	int task01(tree_node *curr);
	int task001();
	int task02(tree_node *curr);
	int task002();
	int task03(int lvl,tree_node *curr);
	int task003();
	int task04(tree_node * curr, int *res);
	int task004();
	int task05(tree_node *curr);
	int task005();

};

#endif // TREE_H