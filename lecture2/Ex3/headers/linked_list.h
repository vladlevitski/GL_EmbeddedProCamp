#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * Structure that represents type of node in linked list.
 */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/**
 * Function creates first element of linked list.
 * @return Pointer to first element
 */
node_t *list_init(void);

/**
 * Function add new element into linked list.
 * @param head Represents pointer to head of linked list
 * @param data Represents element that need to be added
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int list_add(node_t *head, int data);

/**
 * Function remove element from linked list.
 * @param head Represents pointer to head of linked list
 * @param node Represents pointer to element that need to be removed
 */
void list_remove(node_t *head, node_t *node);

/**
 * Function check whether if element exists in the linked list.
 * @param head Represents pointer to head of linked list
 * @param data Represents element that need to be added
 * @return 0 - in case of element exists
 *         1 - in case of element not exists
 */
int list_is(node_t *head, node_t *node);

/**
 * Function prints all elements in linked list.
 * @param head Represents pointer to head of linked list
 */
void list_print(node_t *head);

#endif // LINKED_LIST_H
