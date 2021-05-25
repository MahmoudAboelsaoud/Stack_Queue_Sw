#include <stdio.h>
#include <stdlib.h>

typedef struct stack_entry
{
	int data;
	struct stack_entry *next ;
}Stack_Entry;

typedef struct stack
{
	Stack_Entry *top;

}Stack;

void push(int data, Stack *sptr);
void pop(int *data,Stack *sptr);

int main()
{

	Stack sptr ;
	Stack_Entry s;

	int data,i=0,outdata=0;

	for(i=0; i<=3; i++)
    {
    printf("PLZ Input your data : ");
	scanf("%i",&data);
	push(data, &sptr);
    }

    printf("===================================\n");
    for(i=0; i<=3; i++)
    {
    printf(" the data entered : ");
	pop(&outdata ,&sptr);
	printf("%d\n",outdata);
    }


	return 0;
}

void push(int data, Stack *sptr)
{
	if(sptr->top == NULL)
	{
		Stack_Entry *lptr = (Stack_Entry*)malloc(sizeof(Stack_Entry));
		sptr ->top = lptr;
		lptr->next = NULL;
	}
	else
	{
		Stack_Entry *lptr = (Stack_Entry*)malloc(sizeof(Stack_Entry));
		lptr ->data = data;
		lptr ->next = sptr ->top;
		sptr ->top  = lptr;
	}
}

void pop(int *data,Stack *sptr)
{

    if(sptr->top== NULL)
    {
     Stack_Entry *lptr = sptr ->top;
     *data = ((Stack_Entry*)(sptr->top))->data;
    }
    else
    {
    Stack_Entry *lptr = sptr ->top;
    *data = lptr ->data;
	sptr ->top = lptr->next;
	free(lptr);
    }
}
