#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
    int arr[SIZE];
    int top;
};


void init_top(struct stack *ps);
void push(struct stack *ps,int data);
void pop(struct stack *ps);
int peek(struct stack *ps);
int stack_full(struct stack *ps);
int stack_empty(struct stack *ps);

int main()
{
    struct stack S; 
    init_top(&S);

    int choice;
do{
    printf("0.Exit\n1.Push\n2.Pop\n3.Peek\n");
    printf("Enter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
                exit(0);
        case 1: // push
                if(stack_full(&S)) // if(1)
                    printf("Stack is Full !\n");
                else
                {
                    int data;
                    printf("Enter the data to be pushed :");
                    scanf("%d",&data);
                    push(&S,data);
                    printf("Data pushed : %d\n",data);
                }
                break;
        case 2: // pop
                if(stack_empty(&S))
                    printf("Cannot pop, stack is empty !\n");
                else
                {
                    int value = peek(&S);
                    pop(&S);
                    printf("The value popped = %d\n",value);
                }
                break;
        case 3: // peek
                if(stack_empty(&S))
                    printf("Stack is empty, peek not possible !\n");
                else
                {
                    int value = peek(&S);
                    printf("the topmost value is %d\n",value);
                }
                break;
        default :
                printf("Invalid choice .\n");
    }
}while(choice != 0);

    return 0;
}

void init_top(struct stack *ps) // G G G G G  G
{
    ps->top = -1;
}


void push(struct stack *ps,int data)
{
    // increment the top 
    ps->top++;
    
    // insert the data at the top index
    ps->arr[ps->top] = data;
}

void pop(struct stack *ps)
{
    // optional
    ps->arr[ps->top] = 0;


    ps->top--;
}

int peek(struct stack *ps)
{
    return ps->arr[ps->top];
}

int stack_full(struct stack *ps)
{
    if(ps->top == SIZE-1)
        return 1;
    else
        return 0;
}

int stack_empty(struct stack *ps)
{
    if(ps->top == -1)
        return 1;
    else
        return 0;
}
