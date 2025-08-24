#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
} Node;
int main(int ac, char **av)
{
	Node root;
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next->x = -2;
	root.next->next = malloc(sizeof(Node));
	root.next->next->x = 11;
	root.next->next->next = malloc(sizeof(Node));
	root.next->next->next->x = 20;
	root.next->next->next->next = NULL;

	int i = 0;
	Node* curr = &root;
	while (curr != NULL)
	{
		printf("the element %d == %d\n",i,curr->x);
		i++;
		curr = curr->next;
	}
	Node* tmp;
	curr = root.next;
	while(curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	return 0;
}

