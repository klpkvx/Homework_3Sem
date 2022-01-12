
#ifndef RB_TREE_NODE_H
#define RB_TREE_NODE_H
enum colors
{
	invalid,
	red,
	black,
};
template <class T>
class rb_tree;
template <class T>
class rb_tree_node : public T
{
private:
	rb_tree_node *left = nullptr;
	rb_tree_node *right = nullptr;
	rb_tree_node *parent = nullptr;
	colors color = invalid;

public:
	friend class rb_tree<T>;
	rb_tree_node() = default;
	rb_tree_node(const rb_tree_node &x) = delete;
	rb_tree_node &operator=(const rb_tree_node &x) = delete;

	rb_tree_node(rb_tree_node &&x) : T((T &&) x)
	{
		erase_links();
		x.erase_links();
	}

	rb_tree_node &operator=(rb_tree_node &&x)
	{
		if (this == &x)
			return *this;
		static_cast<T &&>(*this) = static_cast<T &&>(x);
		erase_links();
		x.erase_links();
		return *this;
	}

	~rb_tree_node()
	{
		erase_links();
	}

	void erase_links()
	{
		left = nullptr;
		right = nullptr;
		color = invalid;
	}
};

#endif // RB_TREE_NODE_H