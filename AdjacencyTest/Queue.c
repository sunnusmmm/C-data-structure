#include <malloc.h>
#include "Queue.h"

Queue *InitQueue() {
    Queue *Queue = malloc(sizeof(Queue));
    if (!Queue) exit(OVERFLOW);
    Queue->next = NULL;
    return Queue;
}

Status push(Queue *Q, VexNode *T) {
    Queue *p, *q;
    q = malloc(sizeof(Queue));
    p = Q->next;
    q->element = T;
    q->next = p;
    Q->next = q;
    return OK;
}

VexNode *pop(Queue *Q) {
    Queue *p, *q;
    q = malloc(sizeof(Queue));
    p = Q;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    return p->element;
}

Status empty(Queue Q) {
    if (Q.next == NULL) return TRUE;
    else return FALSE;
}
