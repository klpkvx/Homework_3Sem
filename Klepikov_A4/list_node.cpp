
#include "list_node.h"

void list_node::set_next(list_node *r)
{
	next = r;
}

list_node::~list_node()
{
	next = nullptr;
}

list_node::list_node(list_node &&r) : Student(r)
{
	next = r.next;
	r.next = nullptr;
}

list_node::list_node(const list_node &r) : Student(r)
{
	next = nullptr;
}

list_node &list_node::operator=(const list_node &r)
{
	*(Student *)(this) = r;
	next = nullptr;
	return *this;
}

list_node &list_node::operator=(list_node &&r)
{
	*(Student *)(this) = (Student &&) r;
	next = r.next;
	r.next = nullptr;
	return *this;
}