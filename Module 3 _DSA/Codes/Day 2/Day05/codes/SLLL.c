#include<stdio.h>
#include<stdlib.h>

struct node* create_node();
void add_first_node(int value);
void display();
void add_last_node(int value);
int count_nodes();
void add_at_pos(int value,int pos);
void delete_first_node();
void delete_last_node();
void delete_specific_node(int pos);

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    add_first_node(10);
    add_first_node(20);
    add_first_node(30);
    printf("\n Add First :\n");
    display();
    // Head->30->20->10
    add_last_node(70);
    add_last_node(50);
    add_last_node(40);
    printf("\n\n Add Last :\n");
    display();
    // Head->30->20->10->70->50->40

    add_at_pos(55,4);
    printf("\n\n Add at 4th pos :\n");
    display();
    // Head->30->20->10->55->70->50->40

    delete_first_node();
    printf("\n\n Delete First node :\n");
    display();
    // Head->20->10->55->70->50->40

    delete_last_node();
    printf("\n\n Delete Last node :\n");
    display();
    // Head->20->10->55->70->50

    delete_specific_node(4);
    printf("\n\n Delete 4th node :\n");
    display();
    // Head->20->10->55->50

    return 0;
}

struct node* create_node()
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr; // return 500
}

void add_first_node(int value)
{
    // create a node
    struct node *ptr = create_node();

    // assign the data value 
    ptr->data = value;

    // attach the node to the linked list
    // a. if the list is empty 
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        // ptr->next = 100
        head = ptr;
    }

}

void display()
{
    // take a trav pointer starting from the first node.
    struct node *trav = head;

    printf("Head");
    while(trav != NULL)
    {
        printf("->%d",trav->data);
        trav = trav->next;
    }
    // Head->10->20->30
}

void add_last_node(int value)
{
    // create a node
    struct node *ptr = create_node();

    // assign the value
    ptr->data = value;

    // attach the node to the list
    // a. if the list is empty
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        // traverse till the last node
        struct node *trav = head;

        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        // attach the node 
        trav->next = ptr;
    }
}

void add_at_pos(int value,int pos)
{
    if(head == NULL)
    {
        if(pos == 1)
            add_first_node(value);
        else
            printf("Cannot attach the node.\n");
    }   
    else if(pos == 1)
            add_first_node(value);
    else if(pos == count_nodes()+1)
            add_last_node(value);
    else if(pos < 1 || pos > count_nodes()+1)
            printf("Cannot attach the node.\n");
    else
    {
        // create a node
        struct node *ptr = create_node();
        ptr->data = value;

           struct node *trav = head;

           for(int i = 1; i < pos-1; i++)
                trav = trav->next;

            ptr->next =  trav->next;
            trav->next = ptr;
        }
}

int count_nodes()
{
    int count =0;
    if(head == NULL)
        printf("empty !");
    else
    {
        struct node *trav = head;

        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first_node()
{
    if(head == NULL)
        printf("List is empty.\n");
    else if(head->next == NULL) // if list contains only 1 node.
    {
        free(head);
        head = NULL;
    }
    else // if list contains multiple nodes.
    {
        struct node *temp = head;
        
        head = head->next;
        // OR head = temp->next;

        free(temp);
        temp = NULL;
    }
}

void delete_last_node()
{
    if(head == NULL)
        printf("List is empty.\n");
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;

        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}

void delete_specific_node(int pos)
{
    if(head == NULL)
        printf("List is Empty.\n");
    else if(pos == 1)
        delete_first_node();
    else if(pos == count_nodes())
        delete_last_node();
    else if(pos < 1 || pos > count_nodes())
        printf("Cannot delete the node.\n");
    else
    {
        struct node *trav = head;
        for(int i =1; i< pos-1; i++)
            trav = trav->next;

        struct node *temp = trav->next;

        trav->next = temp->next;

        free(temp);
        temp = NULL;
    }
}