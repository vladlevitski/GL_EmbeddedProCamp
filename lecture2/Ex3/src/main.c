#include <stdio.h>
#include "../headers/linked_list.h"

int main ()
{
    node_t *head = list_init();
    node_t *node = list_init();

    if(list_add(head, 1))
    {
        printf("Emlement not added");
    }
    if(list_add(head, 15))
    {
        printf("Emlement not added");
    }
    if(list_add(head, 118))
    {
        printf("Emlement not added");
    }

    node = head->next;

    printf("Element %d is in list? - ", node->data);
    printf((list_is(head, node)) ? "Yes\n" : "No\n");
    list_print(head);

    list_remove(head, head->next);
    printf("Element %d is in list? - ", node->data);
    printf((list_is(head, node)) ? "Yes\n" : "No\n");
    list_print(head);

    list_remove(head, head->next);
    list_print(head);

    if(list_add(head, 11))
    {
        printf("Emlement not added");
    }
    list_print(head);

    return 0;
}
