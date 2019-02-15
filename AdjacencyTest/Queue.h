#ifndef ADJACENCYTEST_QUEUE_H
#define ADJACENCYTEST_QUEUE_H

#include <stddef.h>
#include "Adjacency.h"

#define FALSE 0
#define OK 1
#define TRUE 1
#define OVERFLOW -2
#define ERROR -1

typedef struct Queue {
    VexNode *element;
    struct Queue *next;
} Queue;


Queue *InitQueue();

Status push(Queue *Q, VexNode *T);

VexNode *pop(Queue *Q);

Status empty(Queue Q);

#endif //ADJACENCYTEST_QUEUE_H