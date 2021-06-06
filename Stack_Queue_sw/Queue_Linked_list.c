#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node
{
	int data;
	struct queue_node *next ;
}Queue_Node;

typedef struct queue
{
    Queue_Node *reer;
    Queue_Node *front;
	int size;

}Queue;


void init_queue(Queue *qptr);
void queue_append(int data ,Queue *qptr);
void queue_serve (int*data ,Queue *qptr);


int main()
{
	Queue_Node queue_node_obj;
	Queue queue_obj;

    init_queue(&queue_obj);

	int data,i=0,outdata=0;

	for(i=0; i<=3; i++)
    {
    printf("PLZ Input your data : ");
	scanf("%i",&data);
	queue_append(data, &queue_obj);
    }

    printf("===================================\n");
    for(i=0; i<=3; i++)
    {
    printf(" the data entered : ");
	queue_serve(&outdata ,&queue_obj);
	printf("%d\n",outdata);
    }

	return 0;
}

void init_queue(Queue *qptr)
{
	qptr ->reer =NULL;
	qptr ->front=NULL;
	qptr ->size=0;
}

void queue_append(int data ,Queue *qptr )
{
	if(qptr ->reer == NULL)
	{
		Queue_Node* lptr =(Queue_Node*)malloc(sizeof(Queue_Node));
		lptr ->data  = data;
		lptr ->next  = NULL;
		qptr ->reer  = lptr;
		qptr ->front = lptr;
		qptr ->size ++;
	}
	else
	{
		Queue_Node* lptr =(Queue_Node*)malloc(sizeof(Queue_Node));
		lptr ->data  = data;
		lptr ->next  = NULL;
		qptr-> reer-> next = lptr;
		qptr-> reer = lptr;
		qptr-> size++;
	}
}
void queue_serve (int*data ,Queue *qptr)
{
    Queue_Node* lptr =qptr ->front;
    *data = lptr->data;
    qptr ->front = lptr->next;
    qptr->size --;
    free(lptr);
    if(qptr ->front == NULL)
        qptr ->reer =NULL;
}
