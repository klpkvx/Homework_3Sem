#ifndef LIST_H
#define LISH_H

#include "list_node.h"
class list : public list_node
{
private:
	list_node *head = nullptr;

public:
	list() = default;
	list(const list &r) = delete;
	list(list &&r)
	{
		head = r.head;
		r.head = nullptr;
	}

	list &operator=(const list &r) = delete;
	list &operator=(list &&r)
	{
		head = r.head;
		r.head = nullptr;
		return *this;
	}

	~list()
	{
		list_delete();
		head = nullptr;
	}

	int get_len();

	int list_read(char *filename);
	void list_print(int r);
	void list_delete();
	int get_less_than_previous();

	// tasks;
	void task01();
	void task02();
	void task03();
	void task04();
	void task05();
};

#endif // LIST_H
