#include "sort.h"
#include "student.h"

int task01(int len, Student *array, Student &x)
{
	int p, l = 0, s = 0;
	p = len - 1;
	l = 0;
	s = 0;
	if (array[p] < x)
	{
		return len;
	}
	if (array[l] > x)
	{
		return l;
	}

	while (p > l)
	{
		s = (p + l) / 2;
		if (array[s] < x)
		{
			l = s + 1;
		}
		else
		{
			p = s;
		}
	}
	return p;
}

void task02(Student *array1, Student *array2, Student *array3, int len1, int len2)
{
	int i = 0, j = 0, k = 0;

	while ((i < len1) && (j < len2))
	{
		if ((array1[i] < (array2[j])) > 0)
		{
			array3[k] = (Student &&) array1[i];
			k++;
			i++;
		}

		else
		{
			array3[k] = (Student &&) array2[j];
			k++;
			j++;
		}
	}

	while (i < len1)
		array3[k++] = (Student &&) array1[i++];

	while (j < len2)
		array3[k++] = (Student &&) array2[j++];
}

int task03(Student *array, int len, Student &x)
{
	int i = 0, j = len - 1;

	while (i <= j)
	{
		while ((i < len) && (array[i] < (x)) > 0)
			i++;
		while ((j >= 0) && (array[j] > (x)) > 0)
			j--;

		if (i <= j)
		{
			array[i].swap(array[j]);

			i++;
			j--;
		}
	}
	return j + 1;
}

void task04(Student *array, int len)
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if ((array[j] > (array[j + 1])) > 0)
				array[j].swap(array[j + 1]);
		}
	}
}

void task05(Student *array, int len) // Нахождение минимума
{
	{
		int i, j, k = 0;

		for (i = 0; i < len - 1; i++)
		{
			for (j = i; j < len; j++)
			{
				if ((array[j] < (array[k])) > 0)
					k = j;
			}

			array[i].swap(array[k]);

			k = i + 1;
		}
	}
}

void task06(Student *array, int len)
{
	int i, j, k;
	Student tmp;

	for (i = 1; i < len; i++)
	{
		j = 0;

		while ((array[j] < (array[i])) > 0)
			j++;

		tmp = (Student &&) array[i];

		for (k = i; k > j; k--)
			array[k] = (Student &&) array[k - 1];

		array[j] = (Student &&) tmp;
	}
}

void task07(Student *array, int len)
{
	int i, j, k;
	Student tmp;

	if (len > 1)
	{
		for (i = 1; i < len; i++)
		{
			j = task01(i, array, array[i]);

			tmp = (Student &&) array[i];

			for (k = i; k > j; k--)
				array[k] = (Student &&) array[k - 1];

			array[j] = (Student &&) tmp;
		}
	}
}

void task08(Student *a, Student *b, int len)
{
	Student *a1 = a;
	Student *c = nullptr;
	int i, j = 2, k, last;

	last = len % 2;

	while (j <= len)
	{
		for (i = 0; i + j <= len; i += j)
			task02(a + i, a + i + j / 2, b + i, j / 2, j / 2);

		if (last != (len % j))
		{
			k = (len % j) - last;
			task02(a + i, a + i + k, b + i, k, last);
		}

		else
		{
			for (; last > 0; last--)
			{
				b[i].swap(a[i]); // Можно использовать реализацию (Student &&)
				i++;
			}
		}

		last = len % j;
		j *= 2;

		c = a;
		a = b;
		b = c;
	}

	if (len > j / 2)
	{
		task02(a, a + j / 2, b, j / 2, len - j / 2);
		a = b;
	}

	if (a1 != a)
	{
		for (i = 0; i < len; i++)
			a1[i] = (Student &&) a[i];
	}
}

int task09_01(Student *array, int len, int k)
{
	int i = -1, j = len;
	while (1)
	{
		while ((i < len - 1) && ((array[++i] < array[k]) > 0));
		while ((j > 0) && ((array[--j] > array[k]) > 0));
		if (i < j)
		{
			array[i].swap(array[j]);
			if (i == k)
				k = j;
			else
				if (j == k)
					k = i;
		}
		else
		{
			if (j < len - 1)
				j++;
			return j;
		}
	}
}
void task09(Student *array, int len)
{
	int k = 0;
	//	Student x;

	while (len > 1)
	{
		//	x = array[len / 2];
		k = task09_01(array, len, len / 2);

		if (k < len - k)
		{
			task09(array, k);
			len -= k;
			array += k;
		}

		else
		{
			task09(array + k, len - k);
			len = k;
		}
	}
}

/*(oid 	HEEEEEEEEEAP_SOoooooRT(Student *array,int len)
{

}
*/
int d_count(Student *array, int len)
{
	int count = 0;

	for (int i = 1; i < len; i++)
		if (!(array[i] == array[i - 1]))
			count++;

	return count;
}