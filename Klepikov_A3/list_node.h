#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "student.h"

class list_node : public Student
{
private:
	list_node *next = nullptr; // узел списка

public:
	list_node() = default;
	list_node(const list_node &r); // конструктор копирования от студента
	list_node(list_node &&r);			 // конструктор перемещения
	~list_node();									 // деструктор

	list_node &operator=(const list_node &r); // конструктор присваивания
	list_node &operator=(list_node &&r);			// конструктор перемещения
	list_node *get_next() const;							// указатель на следующий элемент

	void set_next(list_node *r);
	void delete_list(list_node *head);
	void print_list(list_node *head, int r);
	int read_list(char *filename, list_node **head);
};
#endif