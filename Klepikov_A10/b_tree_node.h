
#include "b_tree.h"
#ifndef B_TREE_NODE_H
#define B_TREE_NODE_H

template <class T>
class b_tree;
template <class T>

class b_tree_node
{
private:
	T *values = nullptr;
	int size = 0;
	b_tree_node **children = nullptr;

public:
	friend class b_tree<T>;
	b_tree_node() = default;
	b_tree_node(const b_tree_node &x) = delete;
	b_tree_node(b_tree_node &&x)
	{
		values = x.values;
		children = x.children;
		size = x.size;
		x.erase_links();
	}

	b_tree_node &operator=(const b_tree_node &x) = delete;
	b_tree_node &operator=(b_tree_node &&x)
	{
		if (this == &x)
			return *this;
		delete_node();
		values = x.values;
		children = x.children;
		size = x.size;
		x.erase_links();
		return *this;
	}

	~b_tree_node()
	{
		delete_node();
	}

	void print(int r = 0)
	{
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < r; i++)
				printf("  ");

			printf("values[%2d]: ", j + 1);
			values[j].print(0);
		}
	}

	int bin_search(const T &x) const
	{
		int right = size - 1, left = 0, mid = 0;
		if (x < values[left])
			return 0;

		if (values[right] < x)
			return size;
		while (right > left)
		{
			mid = (right + left) / 2;
			if (values[mid] < x)
				left = mid + 1;
			else
				right = mid;
		}

		return right;
	}

private:
	void erase_links()
	{
		values = nullptr;
		size = 0;
		children = nullptr;
	}

	void delete_node()
	{
		if (values)
			delete[] values;
		if (children)
			delete[] children;
		erase_links();
	}

	int init(int m)
	{
		values = new T[2 * m];
		if (!values)
			return CANNOT_ALLOCATE;
		children = new b_tree_node *[2 * m + 1];
		if (!children)
		{
			delete[] values;
			return CANNOT_ALLOCATE;
		}
		for (int i = 0; i < 2 * m + 1; i++)
			children[i] = nullptr;
		size = 0;
		return SUCCESS;
	}

	void add_value(T &x, b_tree_node<T> *down, int index)
	{
		for (int i = size; i > index; i--)
		{
			values[i] = static_cast<T &&>(values[i - 1]);
			children[i + 1] = children[i];
		}
		values[index] = static_cast<T &&>(x);
		children[index + 1] = down;
		size++;
	}
};

#endif //B_TREE_NODE_H