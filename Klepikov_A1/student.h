#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
class Student
{
private:
	char *name = nullptr;
	int value = 0;

public:
	// конструкторы
	Student() = default;
	Student(const Student &x);						// конструктор копирования
	Student(Student &&x);									// конструктор перемещения
	Student &operator=(const Student &x); // оператор присваивания
	Student &operator=(Student &&x);			// оператор присваивания с перемещением через временный объект
	~Student();														// деструктор

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

	// операции, определяемые через методы класса
	int operator<(const Student &x) const; // 2nd const - Гарантия “вызови меня, я не буду менять объект класса” говорит, что можно вызывать для константных объектов. иначе скажет что компилятор думает про создателя
	int operator>(const Student &x) const; //

	//int operator>=(const Student &x) const;
	//int operator<=(const Student &x) const;

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
	CANNOT_OPEN_FILE
};
#endif
