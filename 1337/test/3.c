#include <stdio.h>
void swap(int *x, int *y)
{
	int	tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int a = 5;
	int b = 10;
	printf("valeur de a before swap is %d\n",a);
	printf("valeur de b before swap is %d\n",b);
	int *c = &a;
	int *d = &b;
	swap(c,d);
	printf("valeur de a after swap is %d\n",a);
	printf("valeur de b after swap is %d\n",b);
}
// Question:
// 1. Implement swap so that it swaps the values of two integers.
// 2. Test swap with int a = 5, b = 10.

