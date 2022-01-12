#include "func.h"

int f(int i, int n, int s)
{
	switch (s)
	{
	case 1:
		return i + 1;
	case 2:
		return n - (i + 1);
	case 3:
		return (i + 1) / 2;
	default:
		return n - (i + 1) / 2;
	}
}