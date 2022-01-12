#ifndef LIST2_NODE
#define LIST2_NODE

#include "student.h"

class list2_node : public Student
{
private:
	list2_node *next = nullptr;
	list2_node *prev = nullptr;

public:
	friend class list2;

	list2_node() = default;
	list2_node(const list2_node &r);
	list2_node(list2_node &&r);
	~list2_node();

	list2_node &operator=(const list2_node &r);
	list2_node &operator=(list2_node &&r);
};

#endif // LIST2_NODE
