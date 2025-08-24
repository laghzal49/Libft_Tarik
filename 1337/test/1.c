#include <stdio.h>
int main()
{
	int a = 42;
	int *p = &a;
	printf("%d",*p);
	*p = 100;
	printf("%p",*a);
}

// Question:
// 1. Print the value of 'a' using the pointer 'p'.
// 2. Change the value of 'a' to 100 using the pointer.

