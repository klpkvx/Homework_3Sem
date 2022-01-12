#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "student.h"

class list_node : public Student
{
private:
	list_node *next = nullptr;

public:
	friend class list;

	list_node() = default;
	list_node(const list_node &r);
	list_node(list_node &&r);
	~list_node();

	list_node &operator=(const list_node &r);
	list_node &operator=(list_node &&r);

	void set_next(list_node *r);
};
#endif