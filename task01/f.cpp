#include "func.h"

double f(int i, int n, int s)
{
	switch (i)
	{
	case 1:
		return i;
		break;
	case 2:
		return n - i;
		break;
	case 3:
		return i / 2;
		break;
	case 4:
		return n - i / 2;
		break;

	default:
		break;
	}
}