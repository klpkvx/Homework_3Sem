#include "tasks.h"
#include "student.h"

int task01(Student *array, int len)
{
	int flag = 0;
	int i = 1, j = 1;
	for (i = 1; i < len; i++)
	{
		if (flag)
		{
			if (array[i - 1] < array[i] || array[i - 1] == array[i])
			{
				array[j] = (Student &&) array[i];
				j++;
				flag = 0;
			}
			else
			{
				flag = 1;
			}
		}
		else
		{
			if (array[j - 1] < array[i] || array[j - 1] == array[i])
			{
				array[j] = (Student &&) array[i];
				j++;
				flag = 0;
			}
			else
				flag = 1;
		}
	}
	return j;
}

int task02(Student *a, int len)
{
	int j = 2, i = 0;
	int flag1 = 0, flag2 = 0, flag3 = 0;

	if (len <= 2)
		return len;
	if (len == 3)
	{
		if (a[0] > a[2] && a[1] > a[2])
			return 2;
		else
			return 3;
	}

	if (len == 4)
	{
		if (a[0] > a[2] && a[1] > a[2])
			flag1 = 1;
		if (a[1] > a[3] && a[2] > a[3])
			flag2 = 1;
		if (flag2 && !flag1)
			return 3;
		else if (flag1 && !flag2)
		{
			a[2] = (Student &&) a[3];
			return 3;
		}
		else if (flag1 && flag2)
		{
			return 2;
		}
		else
		{
			return 4;
		}
	}
	if (a[0] < a[2] && a[1] < a[2])
		flag1 = 1;
	if (a[1] < a[3] && a[2] < a[3])
		flag2 = 1;

	for (i = 4; i < len; i++)
	{
		if (a[i] > a[i - 2] && a[i] > a[i - 1])
			flag3 = 1;
		if (!flag1)
		{
			a[j] = (Student &&) a[i - 2];
			j++;
		}
		flag1 = flag2;
		flag2 = flag3;
		flag3 = 0;
	}
	if (!flag1)
	{
		a[j] = (Student &&) a[i - 2];
		j++;
	}
	if (!flag2)
	{
		a[j] = (Student &&) a[i - 1];
		j++;
	}
	return j;
}

int task03(Student *a, int len)
{
	int flag1 = 0, flag2 = 0;

	int j = 1;
	int i = 0;

	if (len <= 2)
		return len;

	if (len == 3)
	{
		if (a[0] > a[1] && a[1] < a[2])
		{
			a[1] = (Student &&) a[2];
			return len - 1;
		}
		else
			return len;
	}

	if (a[0] > a[1] && a[1] < a[2])
	{
		flag1 = 1;
	}

	for (i = 3; i < len; i++)
	{
		if (a[i - 2] > a[i - 1] && a[i - 1] < a[i])
		{
			flag2 = 1;
		}
		if (!flag1)
		{
			a[j] = (Student &&) a[i - 2];
			j++;
		}
		flag1 = flag2;
		flag2 = 0;
	}
	if (!flag1)
	{
		a[j] = (Student &&) a[i - 2];
		j++;
	}
	a[j] = (Student &&) a[i - 1];
	j++;
	return j;
}

/*int task04(Student *a, int len)
{
	int i = 0 , j = 0, flag = 0;

	for (int i= 0 ; i< len; i++)
	{

	}
}*/
// Если участок убывания
/* */
int task05(Student *a, int n)
{
	int i = 0, j = 0;
	int flag1 = 0, flag2 = 0;
	if (a[1] < a[0])
		flag1 = 1;
	else
		j++;
	for (i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			flag2 = 1;
		}
		if (!flag1 && !flag2)
		{
			a[j] = (Student &&) a[i];
			j++;
		}
		flag1 = flag2;
		flag2 = 0;
	}
	if (!flag1)
	{
		a[j] = (Student &&) a[n - 1];
		j++;
	}
	return j;
}
int task06(Student *array, int len, Student &x)
{

	int i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		if (array[i] > x || array[i] == x)
		{
			array[j] = (Student &&) array[i];
			j++;
		}
	}
	return j;
}

int task07(Student *array, int len, Student &x)
{
	int i = 0, j = 0, flag = 0;
	for (i = 0; i < len; i++)
	{
		if (array[i] > x || array[i] == x)
		{
			array[j] = (Student &&) array[i];
			j++;
		}
		else
		{
			if (flag == 0)
			{
				array[j] = (Student &&) array[i];
				flag = 1;
				j++;
			}
		}
	}
	return j;
}

int task08(Student *array, int len, Student &x)
{
	int i = 0, j = 0, flag = 0, flag1 = 0;

	if (array[0] < x || array[0] == x)
	{
		array[j] = (Student &&) array[0];
		j++;
		flag = 1;
	}
	else
	{
		if (flag == 0)
		{
			array[j] = (Student &&) array[0];
			j++;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		flag1 = 1;
	}
	for (i = 1; i < len; i++)
	{
		if (array[i] < x || array[i] == x)
		{
			if (flag1 && !flag)
			{
				array[j] = (Student &&) array[i - 1];
				flag1 = 0;
				j++;
			}
			array[j] = (Student &&) array[i];
			j++;
			flag = 1;
		}
		else
		{
			if (flag1 == 0)
			{
				array[j] = (Student &&) array[i];
				j++;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			flag1 = 1;
		}
	}
	if (x < array[i - 1] && flag == 0)
	{
		array[j] = (Student &&) array[i - 1];
		j++;
	}
	return j;
}

int task09(Student *a, int len, Student &x)

{
	int i = 0, j = 0;
	int prev = 0, cur = 0, next = 0;

	if (a[0] < x)
		cur = 1;

	for (i = 0; i < len - 1; i++)
	{
		if (a[i + 1] < x)
			next = 1;
		else
			next = 0;
		if (!prev && !next)
		{
			a[j] = (Student &&) a[i];
			j++;
		}
		prev = cur;
		cur = next;
	}

	if (!prev)
	{
		a[j] = (Student &&) a[len - 1];
		j++;
	}
	return j;
}