#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <stdlib.h>
#include <stdio.h>

/**
 * Queue size
 */
#define MAX_SIZE 10

/**
 * Queue front position.
 */
int front =  0;

/**
 * Queue rear position.
 */
int rear = -1;

/**
 * Quantity of elements in queue.
 */
int quantity = 0;

/**
 * Array that contain the queue.
 */
int arrayqueue[MAX_SIZE];

/**
 * Function add element into array based queue.
 * @param element Represents integer value to add
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int put(int element);

/**
 * Function read element and remove from queue.
 * @param element Represents pointer to integer variable to return data.
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int get(int *element);

/**
 * Function read element without removing it from queue.
 * @param element Represents pointer to integer variable to return data.
 * @return 0 - in case of successful execution
 *         1 - in case of unsuccessful execution
 */
int read(int *element);

#endif // ARRAYQUEUE_H
