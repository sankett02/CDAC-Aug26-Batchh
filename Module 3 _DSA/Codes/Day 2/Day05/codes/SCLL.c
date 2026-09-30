#include<stdio.h>
#include<stdlib.h>



typedef struct node
{
    int data;
    struct node *next;
}node_t;

struct node *head = NULL;

node_t* create_node();
void add_first_node(int value);
void display();
void add_last_node(int value);
void delete_first_node();
void delete_last_node();

int main()
{
    add_first_node(11);
    add_first_node(22);
    add_first_node(33);
    printf("\n Add First node :\n");
    display();
   // Head->33->22->11

   add_last_node(55);
   add_last_node(77);
   add_last_node(44);
    printf("\n Add Last node :\n");
    display();
   // Head->33->22->11->55->77->44

   delete_first_node();
    printf("\n Delete First node :\n");
    display();
   // Head->22->11->55->77->44

   delete_last_node();
    printf("\n Delete Last node :\n");
    display();
   // Head->22->11->55->77
   
    return 0;
}

node_t* create_node()
{
     node_t *ptr = malloc(sizeof(node_t));
     if(ptr == NULL)
        printf("malloc Failed.\n");
    else
    {
        ptr->data = 0;
        ptr->next = NULL;
    }
     return ptr;
}

void add_first_node(int value)
{
   node_t* new_node= create_node();
   new_node->data = value;

   if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        struct node *trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }
        new_node->next = head;
        head = new_node;
        trav->next = head;

    }

}

void display()
{
    if(head == NULL)
        printf("List is empty.\n");
    else
    {
        struct node *trav = head;
        printf("Head");
        do
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }while(trav != head);
    }
}


void add_last_node(int value)
{
    struct node *new_node = create_node();
    new_node->data = value;

    if(head == NULL)
    {
        head = new_node;
        head->next = new_node; // to make it circular
    }
    else
    {
        struct node *trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }

        trav->next = new_node;
        new_node->next = head; // circular
    }

}

void delete_first_node()
{
    if(head == NULL)
        printf("List is empty.\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;
        while(trav->next != head)
            trav = trav->next;

        struct node *temp = head;
        head = head->next; 
        // OR head = temp->next;

        free(temp);
        temp = NULL;

        trav->next = head;
    }
}

void delete_last_node()
{
    if(head == NULL)
        printf("List is empty.\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;
        while(trav->next->next != head)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head; // circular
    }
}