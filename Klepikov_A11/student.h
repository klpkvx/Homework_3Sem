#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include "rb_tree_node.h"

class Student
{
private:
	char *name = nullptr;
	int value = 0;

public:
	Student() = default;
	Student(const Student &x);
	Student(Student &&x);
	~Student();

	void erase();
	int init(const char *n, int v);

	Student &operator=(const Student &x);
	Student &operator=(Student &&x);

	int operator<(const Student &x) const;
	int operator>(const Student &x) const;
	int operator==(const Student &x) const;

	int get_value() const { return value; }
	char *get_name() const { return name; }

	void set_value(int val) { value = val; }
	void set_name(char *name) { this->name = name; }

	void swap(Student &x);

	int read(FILE *fp);
	void print(int tab, colors color);

	int get_length() const { return (name != nullptr ? 1 : 0); }
};

enum ERRORS
{
	SUCCESS,
	CANNOT_OPEN,
	CANNOT_READ,
	CANNOT_ALLOCATE,
	ERROR_ARGS,
	FULL
};
#endif
