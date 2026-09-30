#include<stdio.h>
#include<stdlib.h>
#define SIZE 5


typedef struct queue
{
    int arr[SIZE];
    int rear;
    int front;
}queue_t;

void init_queue(queue_t *pq);
void enqueue(queue_t *pq,int data);
void dequeue(queue_t *pq);
int peek(queue_t *pq);
int queue_full(queue_t *pq);
int queue_empty(queue_t *pq);

int main()
{
    queue_t Q;
    init_queue(&Q);
    int choice;
do{
    printf("0.exit\n1.enqueue\n2.dequeue\n3.peek\n");
    printf("Enter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 :
                exit(0);
        case 1:
                if(queue_full(&Q))
                    printf("Q is full.\n");
                else
                {
                    int data;
                    printf("Enter the data to insert :");
                    scanf("%d",&data);
                    enqueue(&Q,data);
                    printf("data enetered = %d.\n",data);
                }
                break;
        case 2:
                if(queue_empty(&Q))
                    printf("Q is empty, cannot pop.\n");
                else
                {
                    int value = peek(&Q);
                    dequeue(&Q);
                    printf("The value popped = %d\n",value);
                }
                break;
        case 3:
                if(queue_empty(&Q))
                    printf("Q id empty, cannot peek.\n");
                else
                {
                    int value  = peek(&Q);
                    printf("The frontmost value = %d\n",value);
                }
                break;
        default :
                printf("Invalid Choice.\n");
    }
}while(choice != 0);
    return 0;
}

void init_queue(queue_t *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

void enqueue(queue_t *pq,int data)
{
    pq->rear++;
    pq->arr[pq->rear] = data;

    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue_t *pq)
{
    pq->arr[pq->front] = 0;
    pq->front++;
}

int peek(queue_t *pq)
{
    return pq->arr[pq->front];
}

int queue_full(queue_t *pq)
{
    if(pq->rear == SIZE-1)
        return 1;
    else
        return 0;
}

int queue_empty(queue_t *pq)
{
    if(pq->rear == -1 || pq->front > pq->rear)
        return 1;
    else
        return 0;
}