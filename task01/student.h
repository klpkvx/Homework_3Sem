#ifndef STUDENT_H
#define STUDENT_H

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
	Student &operator=(const Student &x); // добавил const, а то не работал
	Student &operator=(Student &&x); // оператор присваивания через временный объект
	~Student(); // деструктор

	int get_value() const
	{
		return value;
	}

	const char *get_name() const
	{
		return name;
	}
	// операции, определяемые через методы класса
	int operator<(const Student &x) const; // 2nd const - Гарантия “вызови меня, я не буду менять объект класса”
	int operator>(const Student &x) const;
	int operator==(const Student &x) const;


	void swap(Student &x);
	int read(FILE *fp);

	void print() const;

private:
	int init(const char *n, int v);
	void erase();
};

enum ERRORS
{
	SUCCESS,
	CANNOT_OPEN,
	CANNOT_READ,
	CANNOT_ALLOCATE,
	ERROR_ARGS
};
#endif