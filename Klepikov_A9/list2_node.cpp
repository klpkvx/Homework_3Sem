
#include "list2_node.h"
list2_node::list2_node(const list2_node &r) : Student(r)
{
	next = nullptr;
	prev = nullptr;
}
list2_node::list2_node(list2_node &&r) : Student(r)
{
	next = r.next;
	r.next = nullptr;
	prev = r.prev;
	r.prev = nullptr;
}
list2_node::~list2_node()
{
	next = nullptr;
	prev = nullptr;
}
list2_node &list2_node::operator=(const list2_node &r)
{
	*(Student *)(this) = r;
	next = nullptr;
	prev = nullptr;
	return *this;
}
list2_node &list2_node::operator=(list2_node &&r)
{
	*(Student *)(this) = (Student &&) r;
	next = r.next;
	r.next = nullptr;
	prev = r.prev;
	r.prev = nullptr;
	return *this;
}
