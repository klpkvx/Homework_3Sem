#ifndef B_TREE_H
#define B_TREE_H

#include "student.h"
#include "b_tree_node.h"

template <class T>

class b_tree
{
private:
	int m = 0;
	b_tree_node<T> *root = nullptr;

public:
	b_tree(int i)
	{
		m = i;
		root = nullptr;
	}

	b_tree(const b_tree &x) = delete;
	b_tree &operator=(const b_tree &x) = delete;
	b_tree(b_tree<T> &&x)
	{
		m = x.m;
		root = x.root;
		x.erase_links();
	}
	b_tree &operator=(b_tree &&x)
	{
		if (*this == x)
			return *this;
		delete_subtree(root);
		m = x.m;
		root = x.root;
		x.erase_links();
		return *this;
	}
	~b_tree()
	{
		if (!root)
			return;
		delete_subtree(root);
		erase_links();
	}

	void erase_links()
	{
		m = 0;
		root = nullptr;
	}

	int read(FILE *fp)
	{
		T x;
		delete_subtree(root);
		while (x.read(fp) == SUCCESS)
		{
			if (add_value(x) == CANNOT_ALLOCATE)
			{
				delete_subtree(root);
				return CANNOT_ALLOCATE;
			}
		}
		if (!feof(fp))
		{
			delete_subtree(root);
			return CANNOT_READ;
		}
		return SUCCESS;
	}

	void print(int r = 0)
	{
		print_subtree(root, 0, r);
	}

	static void delete_subtree(b_tree_node<T> *curr)
	{
		if (!curr)
			return;
		for (int i = 0; i < curr->size + 1; i++)
		{
			delete_subtree(curr->children[i]);
		}
		delete curr;
	}

	static void print_subtree(b_tree_node<T> *curr, int level, int r)
	{
		if (curr == nullptr || level > r)
		{
			return;
		}
		curr->print(level);
		for (int i = 0; i <= curr->size; i++)
		{
			if (curr->children[i] != nullptr && level < r)
			{
				for (int j = 0; j < level; j++)
				{
					printf("  ");
				}
				printf("children[%d]:\n", i);
				print_subtree(curr->children[i], level + 1, r);
			}
		}
	}

	int add_value(T &x)
	{
		if (!root)
		{
			root = new b_tree_node<T>();
			if (!root)
				return CANNOT_ALLOCATE;
			if (root->init(m) == CANNOT_ALLOCATE)
			{
				delete root;
				return CANNOT_ALLOCATE;
			}
			root->values[0] = static_cast<T &&>(x);
			root->size = 1;
			return SUCCESS;
		}
		b_tree_node<T> *curr = root;
		b_tree_node<T> *down = nullptr;
		T tmp = static_cast<T &&>(x);
		int r = add_value_subtree(curr, &tmp, &down, m);
		if (r == CANNOT_ALLOCATE)
			return CANNOT_ALLOCATE;
		if (r == SUCCESS)
			return SUCCESS;

		b_tree_node<T> *p = new b_tree_node<T>();
		if (!p)
			return CANNOT_ALLOCATE;
		if ((p->init(m)) == CANNOT_ALLOCATE)
		{
			delete p;
			return CANNOT_ALLOCATE;
		}
		p->values[0] = static_cast<T &&>(tmp);
		p->size = 1;
		p->children[0] = curr;
		p->children[1] = down;
		root = p;
		return SUCCESS;
	}

	int add_value_subtree(b_tree_node<T> *curr, T *x, b_tree_node<T> **down, int m)
	{
		int index = curr->bin_search(*x);
		b_tree_node<T> *b = curr->children[index];
		if (!b)
		{
			if (curr->size == 2 * m)
			{
				b_tree_node<T> *p = new b_tree_node<T>();
				if (!p)
					return CANNOT_ALLOCATE;
				if ((p->init(m)) == CANNOT_ALLOCATE)
				{
					delete p;
					return CANNOT_ALLOCATE;
				}

				if (index == m)
				{
					for (int i = m; i < 2 * m; i++)
					{
						p->values[i - m] = static_cast<T &&>(curr->values[i]);
					}
				}

				else
				if (index > m)
				{
					int i = 0;
					for (i = m + 1; i < index; i++)
					{
						p->values[i - m - 1] = static_cast<T &&>(curr->values[i]);
					}
					p->values[i - m - 1] = static_cast<T &&>(*x);
					for (i = index; i < 2 * m; i++)
					{
						p->values[i - m] = static_cast<T &&>(curr->values[i]);
					}
					*x = static_cast<T &&>(curr->values[m]);
				}
				else
				{
					int i = 0;
					for (i = m; i < 2 * m; i++)
					{
						p->values[i - m] = static_cast<T &&>(curr->values[i]);
					}
					T tmp = static_cast<T &&>(curr->values[m - 1]);
					for (i = m - 2; i > index - 1; i--)
					{
						curr->values[i + 1] = static_cast<T &&>(curr->values[i]);
					}
					curr->values[index] = static_cast<T &&>(*x);
					*x = static_cast<T &&>(tmp);
				}
				curr->size = m;
				p->size = m;
				*down = p;
				return FULL; // разделили узел и послали элемент своему родителю
			}
			else
			{
				curr->add_value(*x, *down, index);
				return SUCCESS;
			}
		}
		else
		{

			int r = add_value_subtree(b, x, down, m);
			if (r == CANNOT_ALLOCATE)
				return r;
			else if (r == SUCCESS)
				return r;

			if (curr->size == 2 * m)
			{
				b_tree_node<T> *p = new b_tree_node<T>();

				if (!p)
					return CANNOT_ALLOCATE;

				if ((p->init(m)) == CANNOT_ALLOCATE)
				{
					delete p;
					return CANNOT_ALLOCATE;
				}

				if (index == m)
				{
					int i = 0;
					for (int i = m; i < 2 * m; i++)
					{
						p->values[i - m] = static_cast<T &&>(curr->values[i]);
						p->children[i - m] = curr->children[i];
						curr->children[i] = nullptr;
					}
					p->children[i - m] = curr->children[i];
					curr->children[i] = *down;
				}

				if (index > m)
				{
					int i = 0;
					for (i = m + 1; i < index; i++)
					{
						p->values[i - m - 1] = static_cast<T &&>(curr->values[i]);
						p->children[i - m - 1] = curr->children[i];
						curr->children[i] = nullptr;
					}
					p->values[i - m - 1] = static_cast<T &&>(*x);
					p->children[i - m - 1] = *down;
					for (i = index; i < 2 * m; i++)
					{
						p->values[i - m] = static_cast<T &&>(curr->values[i]);
						p->children[i - m] = curr->children[i];
						curr->children[i] = nullptr;
					}
					p->children[i - m] = curr->children[i];
					curr->children[i] = nullptr;
					*x = static_cast<T &&>(curr->values[m]);
				}
				else
				{

					for (int i = m; i < 2 * m; i++)
					{
						p->values[i - m] = static_cast<T &&>(curr->values[i]);
						p->children[i] = curr->children[i];
						curr->children[i] = nullptr;
					}
					T tmp = static_cast<T &&>(curr->values[m - 1]);
					for (int i = m - 2; i > index - 1; i--)
					{
						curr->values[i + 1] = static_cast<T &&>(curr->values[i]);
						p->children[i + 2] = curr->children[i + 1];
					}
					curr->values[index] = static_cast<T &&>(*x);
					p->children[index + 1] = *down;
					*x = static_cast<T &&>(tmp);
				}
				p->size = m;
				curr->size = m;
				*down = p;
				return FULL;
			}
			else
			{
				curr->add_value(*x, *down, index);
				return SUCCESS;
			}
		}
	}

	int task1(int k)
	{
		if (!root) return 0;
		return task_11(root, k);
	}

	int task_11(b_tree_node<T> *curr, int k)
	{
		int count = 0;
		if (!curr->children[0])
		{
			if (!k)
				return curr->size;
			return 0;
		}
		for (int i = 0; i < curr->size + 1; i++)
			count += + task_11(curr->children[i], k);
		if ((curr->size + 1) == k)
			return curr->size + count;
		return count;
	}

	int task2(int k)
	{
		int res = 0;
		if (!k) return 0;
		task_22(root, k, &res);
		return res;
	}
	int task_22(b_tree_node<T> *curr, int k, int *res)
	{
		int count = 0;

		if (!curr->children[0])
		{
			if (k - 1 >= 0)
				*res += curr->size;
			return 1;
		}
		for (int i = 0; i < curr->size + 1; i++)
			count += task_22(curr->children[i], k, res);

		if (k - 1 >= count)
			*res += + task_222(curr);
		return count + 1;
	}

	int task_222(b_tree_node<T> *curr)
	{
		int count = 0;

		if (!curr->children[0])
			return curr->size;
		for (int i = 0; i < curr->size + 1; i++)
			count += task_222(curr->children[i]);
		return count + curr->size;
	}

	int task5(int k)
	{
		return task_55(root, k);
	}

	int task_55(b_tree_node<T> *curr, int k)
	{
		int count = 0;

		if (!k)
			return curr->size;

		if (!curr->children[0])
			return 0;

		for (int i = 0; i < curr->size + 1; i++)
			count += task_55(curr->children[i], k - 1);
		return count;
	}

	int task6(int k)
	{
		int res = 0;
		if (!k) return 0;
		task_66(root, k - 1, &res);
		return res;
	}

	int task_66(b_tree_node<T> *curr, int k, int *res)
	{
		int count = 0;
		if (k < 0) return 0;
		if (!curr->children[0])
		{
			if (!k)
			{
				*res += curr->size;
				return 1;
			}
			return 0;
		}
		for (int i = 0; i < curr->size + 1; i++)
			count += task_66(curr->children[i], k - 1, res);
		*res = *res + count * curr->size;
		return count;
	}
};
#endif // B_TREE_H
