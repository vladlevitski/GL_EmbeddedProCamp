#include <stdlib.h>
#include <stdio.h>
#include "../headers/linked_list.h"

node_t *list_init()
{
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    head->data = 0;
    head->next = NULL;

    return head;
}

int list_add(node_t *head, int data)
{
    node_t *new_node = NULL;
    new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return 1;
    }
    new_node->data = data;
    new_node->next = NULL;

    node_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;

    return 0;
}

int list_is(node_t *head, node_t *node)
{
    int elem_exists = 0;
    node_t *current = head;

    while (current != NULL)
    {
        if (current == node)
        {
            elem_exists = 1;
            break;
        }
        current = current->next;
    }
    return elem_exists;
}

void list_remove(node_t *head, node_t *node)
{
    node_t *current = head;
    while (current != NULL)
    {
        if (current->next == node)
        {
            current->next = node->next;
            free(node);
            break;
        }
        current = current->next;
    }
}

void list_print(node_t *head)
{
    node_t *current = head;
    int i = 0;

    while (current != NULL)
    {
        printf("Element[%d] 0x%x\tdata = %d\tnext element 0x%x\n",
               i,
               current,
               current->data,
               current->next);
        ++i;
        current = current->next;
    }

    printf("\n");
}
