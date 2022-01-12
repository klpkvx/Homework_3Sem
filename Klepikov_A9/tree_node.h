#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "student.h"
#include "list2.h"

template <class T>class tree;
template <class T>
class tree_node : public T
{
private:
	tree_node *left = nullptr;
	tree_node *right = nullptr;

public:
	friend class tree<T>;

	tree_node() = default;
	tree_node(const tree_node &r) = delete;
	tree_node(tree_node &&r) : T((T &&) r)
	{
		left = r.left;
		r.left = nullptr;
		right = r.right;
		r.right = nullptr;
	}
	~tree_node()
	{
		left = nullptr;
		right = nullptr;
	}

	tree_node &operator=(const tree_node &r) = delete;
	tree_node &operator=(tree_node &&r)
	{
		if (this == &r)
			return *this;
		*(T *)(this) = (T &&) r;
		left = r.left;
		right = r.right;
		r.left = nullptr;
		r.right = nullptr;
		return *this;
	}
};
#endif // TREE_NODE_H
