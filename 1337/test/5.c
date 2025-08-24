#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p = malloc(sizeof(int) * 5);
	if (!p)
		return 1;
	int i = 1;
	int *ptr = p;
	while(i <= 5)
	{
		*ptr = i;
		ptr++;
		i++;
	}
	ptr = p;
	i = 0;
	while(i < 5)
	{
		printf("%d",*ptr);
		ptr++;
		i++;
	}
	free(p);
	return 0;
}
// Question:
// 1. Allocate an array of 5 integers using malloc.
// 2. Fill it with numbers 1 to 5 using a pointer.
// 3. Print all values using pointer arithmetic.
// 4. Free the memory.

