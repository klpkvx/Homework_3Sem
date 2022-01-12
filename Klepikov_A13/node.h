#ifndef NODE_H
#define NODE_H

#include "stdio.h"
#include "string.h"
enum ERRORS
{
	SUCCESS,
	CANNOT_OPEN,
	CANNOT_READ,
	CANNOT_ALLOCATE,
	ERROR_ARGS,
};

class node
{
private:
	char *name = nullptr;
	node *left = nullptr;
	node *center = nullptr;
	node *right = nullptr;
	friend class tree;

public:
	node() = default;
	node(const node &x) = delete;
	~node()
	{
		erase_links();
		delete[] name;
		name = nullptr;
	}
	node &operator=(const node &x) = delete;

	node(node &&x)
	{
		name = x.name;
		x.name = nullptr;
	}
	node &operator=(node &&x)
	{
		if (this == &x)
			return *this;
		name = x.name;
		x.name = nullptr;
		return *this;
	}
	void erase_links()
	{
		left = nullptr;
		right = nullptr;
		center = nullptr;
	}

	int init(const char *n)
	{
		if (n != nullptr)
		{
			size_t len = strlen(n);
			name = new char[len + 1];
			if (name == nullptr)
				return CANNOT_ALLOCATE;
			for (size_t i = 0; i <= len; i++)
				name[i] = n[i];
		}
		else
			name = nullptr;
		return SUCCESS;
	}

	int read(FILE *fp)
	{

		char buf[1234];
		if (!fgets(buf, 1234, fp))
		{
			return CANNOT_READ;
		}
		size_t len = strlen(buf);
		name = new char[len + 1];
		if (!name)
			return CANNOT_ALLOCATE;
		for (size_t i = 0; i <= len; i++)
		{
			name[i] = buf[i];
		}
		return SUCCESS;
	}

	int operator>(const node &x) const
	{
		if (name && x.name)
		{
			if (strcmp(name, x.name) > 0)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	int operator<(const node &x) const
	{
		if (name && x.name)
		{
			if (strcmp(name, x.name) < 0)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
};

#endif // NODE_H