#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "student.h"

Student::Student(const Student &x) // конструктор копирования без него нельзя передать в функцию по значению
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

Student &Student::operator=(const Student &x) // в стандарте написано надо const писать в аргументы, если убрать const будет другой оператор
{
	if (this == &x) // чтобы избежать a = a
	{
		return *this;
	}

	erase();
	init(x.name, x.value);
	return *this;
}

Student &Student::operator=(Student &&x) // оператор присваивания с перемещением когда временный объект время жизни которого кончается на этой строке присваивания
{
	if (this == &x) // этот кусок никогда не произойдет. все равно надо текущий экземпляр удалить и ему присвоить экземпляр временного объекта
	{
		return *this;
	}
	erase();
	name = x.name;
	x.name = nullptr;
	value = x.value;
	x.value = 0;
	return *this;
}

Student::~Student()
{
	erase();
}

int Student::operator>(const Student &x) const
{
	if (name == nullptr && x.name == nullptr)
	{
		if (value > x.value)
			return 1;
		else
			return 0;
	}
	if (name == nullptr || x.name == nullptr)
	{
		if (name == nullptr)
			return 0;
		else
			return 1;
	}
	if (strcmp(name, x.name) > 0)
		return 1;
	else
	{
		if (strcmp(name, x.name) < 0)
			return 0;
		else
		{
			if (value > x.value)
				return 1;
			else
				return 0;
		}
	}
}

int Student::operator<(const Student &x) const
{
	if (name == nullptr && x.name == nullptr)
	{
		if (value < x.value)
			return 1;
		else
			return 0;
	}

	if (name == nullptr || x.name == nullptr)
	{
		if (name == nullptr)
			return 1;
		else
			return 0;
	}
	if (strcmp(name, x.name) < 0)
		return 1;
	else
	{
		if (strcmp(name, x.name) > 0)
			return 0;
		else
		{
			if (value < x.value)
				return 1;
			else
				return 0;
		}
	}
}

int Student::operator==(const Student &x) const
{
	if (name == nullptr && x.name == nullptr)
	{
		if (value == x.value)
			return 1;
		else
			return 0;
	}
	if (name == nullptr || x.name == nullptr)
	{
		if (name == nullptr)
			return 0;
		else
			return 1;
	}
	if ((strcmp(name, x.name) == 0) && (value == x.value))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Student::init(const char *n, int v) // инициализация объекта
{
	value = v;
	if (n != nullptr)
	{
		size_t len = strlen(n); // size_t потому что в разных системах разные размеры типов данных
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

void Student::swap(Student &x)
{
	char *n;
	int v;
	n = name;
	name = x.name;
	x.name = n;
	v = value;
	value = x.value;
	x.value = v;
}

int Student::read(FILE *fp)
{
	const int LEN = 1234;
	char buf[LEN];
	int v;
	if (fscanf(fp, "%s%d", buf, &v) != 2)
	{
		return CANNOT_READ;
	}
	erase();
	if (init(buf, v) != SUCCESS)
	{
		return CANNOT_ALLOCATE;
	}
	return SUCCESS;
}