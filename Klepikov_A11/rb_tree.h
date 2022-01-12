#ifndef RB_TREE_H
#define RB_TREE_H

#include "student.h"
#include "rb_tree_node.h"

template <class T>
class rb_tree
{
private:
	rb_tree_node<T> *root = nullptr;

public:
	rb_tree() = default;
	rb_tree(const rb_tree &x) = delete;
	rb_tree &operator=(const rb_tree &x) = delete;
	rb_tree(rb_tree<T> &&x) = delete;
	rb_tree &operator=(rb_tree &&x) = delete;
	~rb_tree()
	{
		if (!root)
			return;
		delete_subtree(root);
		root = nullptr;
	}
	int read(FILE *fp)
	{
		rb_tree_node<T> x;
		if (x.read(fp) != SUCCESS)
		{
			fclose(fp);
			return CANNOT_READ;
		}
		rb_tree_node<T> *curr = new rb_tree_node<T>((rb_tree_node<T> &&) x);
		if (!curr)
			return CANNOT_ALLOCATE;
		root = curr;
		root->color = black;
		while (x.read(fp) == SUCCESS)
		{
			curr = new rb_tree_node<T>((rb_tree_node<T> &&) x);
			if (!curr)
				return CANNOT_ALLOCATE;
			curr->color = red;
			add_node_subtree(root, curr);
			fix_tree(curr);
		}
		if (!feof(fp))
			return CANNOT_READ;
		return SUCCESS;
	}
	void add_node_subtree(rb_tree_node<T> *curr, rb_tree_node<T> *x)
	{
		if (*x < *curr)
		{
			if (!curr->left)
			{
				curr->left = x;
				x->parent = curr;
			}
			else
				add_node_subtree(curr->left, x);
		}
		else
		{
			if (!curr->right)
			{
				curr->right = x;
				x->parent = curr;
			}
			else
				add_node_subtree(curr->right, x);
		}
	}
	void print(int r = 0) const
	{
		print_subtree(root, 0, r);
	}

	void print_subtree(rb_tree_node<T> *curr, int level, int r) const
	{
		if (!curr || level > r)
			return;
		int spaces = level * 2;
		if (curr->color == black)
			curr->print(spaces, black);
		if (curr->color == red)
			curr->print(spaces, red);
		print_subtree(curr->left, level + 1, r);
		print_subtree(curr->right, level + 1, r);
	}
	void delete_subtree(rb_tree_node<T> *curr)
	{
		if (!curr)
			return;
		delete_subtree(curr->left);
		delete_subtree(curr->right);
		delete curr;
	}
	void fix_tree(rb_tree_node<T> *curr)
	{
		rb_tree_node<T> *parent = nullptr;
		rb_tree_node<T> *grandparent = nullptr;
		rb_tree_node<T> *uncle = nullptr;
		while ((curr->parent) && (curr->color == red) && (curr->parent->color == red))
		{
			parent = curr->parent;
			grandparent = parent->parent;
			if (parent == grandparent->left)
			{
				uncle = grandparent->right;
				if ((uncle) && (uncle->color == red))
				{
					grandparent->color = red;
					uncle->color = black;
					parent->color = black;
					curr = grandparent;
				}
				else
				{
					if (curr == parent->right)
					{
						curr = parent;
						rotate_left(curr);
					}
					else
					{
						parent->color = black;
						grandparent->color = red;
						rotate_right(grandparent);
						curr = grandparent;
						break;
					}
				}
			}
			else
			{
				uncle = grandparent->left;
				if ((uncle) && (uncle->color == red))
				{
					uncle->color = black;
					parent->color = black;
					grandparent->color = red;
					curr = grandparent;
				}
				else
				{
					if (curr == parent->left)
					{
						rotate_right(parent);
						curr = parent;
					}
					else
					{
						parent->color = black;
						grandparent->color = red;
						rotate_left(grandparent);
						curr = grandparent;
						break;
					}
				}
			}
		}
		if (!curr->parent)
			curr->color = black;
	}

	void rotate_right(rb_tree_node<T> *curr)
	{
		rb_tree_node<T> *curr_left = curr->left;

		curr->left = curr_left->right;
		if (curr->left)
			curr->left->parent = curr;

		curr_left->parent = curr->parent;

		curr_left->right = curr;

		if (!curr->parent)
		{
			root = curr_left;

			curr->parent = curr_left;
			return;
		}

		if (curr == curr->parent->left)
		{
			curr->parent->left = curr_left;
			curr->parent = curr_left;
			return;
		}
		curr->parent->right = curr_left;
		curr->parent = curr_left;
		return;
	}

	void rotate_left(rb_tree_node<T> *curr)
	{
		rb_tree_node<T> *curr_right = curr->right;

		curr->right = curr_right->left;
		if (curr->right)
			curr->right->parent = curr;

		curr_right->parent = curr->parent;

		curr_right->left = curr;

		if (!curr->parent)
		{
			root = curr_right;
			curr->parent = curr_right;
			return;
		}

		if (curr == curr->parent->right)
		{
			curr->parent->right = curr_right;
			curr->parent = curr_right;
			return;
		}
		curr->parent->left = curr_right;
		curr->parent = curr_right;
		return;
	}

	int task1(int k)
	{
		if (k == 0)
			return 0;
		int res = 0;
		task11(root, &res, k);
		return res;
	}
	int task11(rb_tree_node<T> *curr, int *res, int k)
	{
		int count = 0;
		if (curr->right && curr->left)
		{
			count = task11(curr->left, res, k) + task11(curr->right, res, k) + 1;
			if (count <= k)
				*res += count;
			return count;
		}
		else
		{
			if (curr->right)
			{
				count = task11(curr->right, res, k) + 1;
				if (count <= k)
					*res += count;
				return count;
			}
			else
			{
				if (curr->left)
				{
					count = task11(curr->left, res, k) + 1;
					if (count <= k)
						*res += count;
					return count;
				}
				else
				{
					if (1 <= k)
						*res += 1;
					return 1;
				}
			}
		}
	}
	
	int task4(int k)
	{
		return task44(root, k);
	}
	int task44(rb_tree_node<T> *curr, int k)
	{
		if (k == 0)
			return 1;

		if (curr->left && curr->right)
			return task44(curr->left, k - 1) + task44(curr->right, k - 1);
		else
		{
			if (curr->left)
				return task44(curr->left, k - 1);
			else
			{
				if (curr->right)
					return task44(curr->right, k - 1);
				else
					return 0;
			}
		}
	}
	int task5(int k)
	{
		if (k == 0)
			return 0;
		int res = 0;
		task55(root, &res, k - 1);
		return res;
	}
	int task55(rb_tree_node<T> *curr, int *res, int k)
	{
		int count = 0;
		if (k > 0)
		{
			if (curr->left && curr->right)
			{
				count = task55(curr->left, res, k - 1) + task55(curr->right, res, k - 1);
				*res += count;
				return count;
			}
			else
			{
				if (curr->left)
				{
					count = task55(curr->left, res, k - 1);
					*res += count;
					return count;
				}
				else
				{
					if (curr->right)
					{
						count = task55(curr->right, res, k - 1);
						*res += count;
						return count;
					}
					else
						return 0;
				}
			}
		}
		else
		{
			if (!curr->left && !curr->right)
			{
				*res = *res + 1;
				return 1;
			}
			else
				return 0;
		}
	}
};
#endif // RB_TREE_H
