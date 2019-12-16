#include "../headers/linkedstack.h"

node_t* head = NULL;

void initList()
{
    head = NULL;
}

int push(int element)
{
    node_t* temp;
    if (head == NULL)
    {
        head = (node_t*)malloc(1*sizeof(node_t));
        if (head == NULL)
        {
            printf("<Error> No free memory\n");
            return 1;
        }
        head->next = NULL;
        head->data = element;
    }
    else
    {
        temp = (node_t*)malloc(1*sizeof(node_t));
        if (temp == NULL)
        {
            printf("<Error> No free memory\n");
            return 1;
        }
        temp->next = head;
        temp->data = element;
        head = temp;
    }
        
    return 0;
}

int pop(int *element)
{
    node_t* current;
    if (head == NULL)
    { 
        printf("Stack is empty!\n");
        return 1;
    } 
    else
    { 
        // head assign into current 
        current = head;
        
        *element = current->data;
        
        // assign second node to head
        head = head->next;
        // destroy connection between first and second
        current->next = NULL;
        // release memory of top node
        free(current);
    }
    return 0;
}

int read(int *element)
{
    if (head == NULL)
    { 
        printf("Stack is empty!\n");
        return 1;
    } 
    else
    {
        *element = head->data;
    }
    return 0;
}

void display()
{
    node_t* temp;
    temp = head;
 
    if (temp == NULL)
    {
        printf("Stack is empty");
    }
 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
 }
