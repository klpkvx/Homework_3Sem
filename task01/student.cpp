#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "student.h"

int Student::init(const char *n, int v) // инициализация объекта
{
	value = v;
	if (n != nullptr)
	{
		size_t len = strlen(n);
		name = new char[len + 1];
		if (name == nullptr)
		{
			return CANNOT_ALLOCATE;
		}
		for (size_t i = 0; i <= len; i++)
		{
			name[i] = n[i];
		}
	}
	else
	{
		name = nullptr;
	}
	return SUCCESS;
}

void Student::erase()
{
	value = 0;
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

Student::Student(const Student &x)
{
	init(x.name, x.value);
}

Student::Student(Student &&x)
{
	name = x.name;
	x.name = nullptr;
	value = x.value;
	x.value = 0;
}

Student &Student::operator=(const Student &x)
{
	if (this == &x)
	{
		return *this;
	}

	erase();
	init(x.name, x.value);
	return *this;
}

Student &Student::operator=(Student &&x)
{
	if (this == &x)
	{
		return x;
	}
	erase();
	name = x.name;
	x.name = nullptr;
	value = x.value;
	x.value = 0;
	return *this;
}

int Student::operator<(const Student &x) const
{
	return value < x.value; // надо дописать
}

int Student::operator>(const Student &x) const
{
	return value > x.value; // надо дописать
}

int Student::operator==(const Student &x) const;
{

	if (( x.name!= nullptr) && strcmp(name,x.name)==0 && (x.value==value))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


Student::~Student()
{
	erase();
}