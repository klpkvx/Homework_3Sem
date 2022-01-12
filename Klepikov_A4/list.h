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

	void list_rm_element(list_node *r);
	void list_rm_interval(list_node *curr, list_node *tmp);
	void del(list_node *x);

			//	void list_rm(list_node *x);

			// tasks;
			void task01(int k); // внутри этой функции можно не пистаь get_next() а писать
	void task02(int k);
	void task03(int k);
	void task05(int k);
	void task06(int k);
	void task07(int k);

	//	void task07(int k);
};

#endif //LIST_H
