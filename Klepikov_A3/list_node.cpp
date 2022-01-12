#include "student.h"
#include "list_node.h"

list_node::list_node(const list_node &r) : Student(r) // конструктор копирования от студента
{
	next = nullptr;
}

list_node::list_node(list_node &&r) : Student(r) // конструктор перемещения
{
	next = r.next;
	r.next = nullptr;
}

list_node::~list_node() // деструктор
{
	next = nullptr;
}

list_node &list_node::operator=(const list_node &r) // конструктор присваивания
{
	*(Student *)(this) = r; // повторить
	next = nullptr;
	return *this;
}

list_node &list_node::operator=(list_node &&r) // конструктор перемещения
{
	*(Student *)(this) = (Student &&) r;
	next = r.next;
	r.next = nullptr; // не работает
	return *this;
}

list_node *list_node::get_next() const
{
	return next;
}
void list_node::set_next(list_node *r)
{
	next = r;
}

void list_node::delete_list(list_node *head)
{
	list_node *curr, *next;
	for (curr = head; curr; curr = next)
	{
		next = curr->get_next();
		delete curr;
	}
}