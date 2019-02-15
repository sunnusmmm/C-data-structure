#ifndef TREETEST_QUEUE_H
#define TREETEST_QUEUE_H

#include <stddef.h>
#include "TreeTest.h"

#define FALSE 0
#define OK 1
#define TRUE 1
#define OVERFLOW -2
#define ERROR -1

typedef struct Queue {
    Tree* element;
    struct Queue *next;
} Queue;


Queue* InitQueue();

Status push(Queue *Q, Tree *T);

Tree* pop(Queue *Q);

Status empty(Queue Q);

#endif //TREETEST_QUEUE_H
