#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdlib.h>
#include <stdio.h>

/**
 * Structure that represents type of node.
 */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/**
 * Function initialize linked list based stack.
 */
void initList();

/**
 * Function add element into linked list based stack.
 * @param element Represents integer value to add
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int push(int element);

/**
 * Function read element and remove from stack.
 * @param element Represents pointer to integer variable to return data.
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int pop(int *element);

/**
 * Function read element without removing it from stack.
 * @param element Represents pointer to integer variable to return data.
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int read(int *element);

/**
 * Function prints all elements in stack.
 */
void display();

#endif // LINKEDSTACK_H
