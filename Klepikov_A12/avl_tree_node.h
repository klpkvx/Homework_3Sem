
#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

template <class T>
class avl_tree;
template <class T>
class avl_tree_node : public T
{
private:
	avl_tree_node *left = nullptr;
	avl_tree_node *right = nullptr;
	int balance = 0;

public:
	friend class avl_tree<T>;
	avl_tree_node() = default;
	avl_tree_node(const avl_tree_node &x) = delete;
	avl_tree_node &operator=(const avl_tree_node &x) = delete;

	avl_tree_node(avl_tree_node &&x) : T((static_cast<T &&>(x)))
	{
		erase_links();
		x.erase_links();
	}

	avl_tree_node &operator=(avl_tree_node &&x)
	{
		if (this == &x)
			return *this;
		static_cast<T &&>(*this) = static_cast<T &&>(x);
		erase_links();
		x.erase_links();
		return *this;
	}

	~avl_tree_node()
	{
		erase_links();
	}


	void erase_links()
	{
		left = nullptr;
		right = nullptr;
		balance = 0;
	}
};

#endif // AVL_TREE_NODE_H