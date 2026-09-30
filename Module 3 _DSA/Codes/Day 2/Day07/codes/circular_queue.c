// Circular Queue

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct queue
{
    int arr[SIZE];
    int front; 
    int rear;
}queue;
 
void init_queue(queue *pq);
void enqueue(queue *pq,int val);
void dequeue(queue *pq);
int is_queue_full(queue *pq);
int is_queue_empty(queue *pq);
int peek(queue *pq);

int main()
{
    int choice,value;
    queue Q;
    init_queue(&Q);
do
{
    printf("\nEnter the choice \n");
    printf("0. Exit\n1.Enqueue\n2.Dequeue\n3.Peek\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
            exit(0);
        case 1: // Enqueue
            if(is_queue_full(&Q))
                printf("Queue is full !");
            else
            {
                printf("enter the value !");
                scanf("%d",&value);
                enqueue(&Q,value);
                printf("%d is pushed into queue !",value);
            }
            break;
        case 2: // dequeue
            if(is_queue_empty(&Q))
                printf("Queue is empty !");
            else
            {
                int num = peek(&Q);
                dequeue(&Q);
                printf("Value deleted = %d\n",num);

            }
            break;
        case 3: // peek
            if(is_queue_empty(&Q))
                printf("Queue is empty !Nothing to Peek !");
            else
            {
                int data = peek(&Q) ;
                printf("Frontmost element = %d\n",data);
            }
            break;
        default :
            printf("enter valid choice !");
    }
}while(choice != 0);

    return 0;
}

void init_queue(queue *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

void enqueue(queue *pq,int val)
{
    pq->rear = (pq->rear+1) % SIZE; // instead of pq->rear++
    pq->arr[pq->rear] = val;
    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
{
    if(pq->front == pq->rear) // deleteing last element
        pq->front = pq->rear = -1; // reset the queue
    else
    {
        pq->arr[pq->front] = 0; // optional
        pq->front = (pq->front+1) % SIZE; // instead of pq->front++
        
    }
}

int is_queue_full(queue *pq)
{
    if(pq->front == (pq->rear +1) % SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_queue_empty(queue *pq)
{
    if(pq->rear == -1 )
        return 1;
        else
        return 0;
}

int peek(queue *pq)
{
    return pq->arr[pq->front];
}

