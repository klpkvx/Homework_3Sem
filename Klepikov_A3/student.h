#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

class Student
{
private:
	char *name = nullptr;
	int value = 0;

public:
	Student() = default;
	Student(const Student &x);
	Student(Student &&x);
	Student &operator=(const Student &x);
	Student &operator=(Student &&x);
	~Student();

	inline int get_value() const
	{
		return value;
	}

	inline char *get_name() const
	{
		return name;
	}

	inline void set_value(int val)
	{
		value = val;
	}

	inline void set_name(char *name)
	{
		this->name = name;
	}

	inline void print() const
	{
		printf("%s %d \n", name, value);
	}

	int operator<(const Student &x) const;
	int operator>(const Student &x) const;

	int operator==(const Student &x) const;

	void swap(Student &x);
	int read(FILE *fp);
	int finit(Student *array, int n, int formula);

	int init(const char *n, int v);

private:
	void erase();
};

enum ERRORS
{
	SUCCESS,
	CANNOT_OPEN,
	CANNOT_READ,
	CANNOT_ALLOCATE,
	ERROR_ARGS,
	ERROR_NAME,
	ERROR_MEM,
	ERROR_READ,
	CANNOT_OPEN_FILE
};
#endif
