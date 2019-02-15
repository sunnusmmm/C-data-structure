#include "Adjacency.h"
#include "Queue.h"
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

Status CreateGraph(pGraph *G, VertexType V[], EdgeType VR[]) {
    int i, j = 0, h = N;
    (*G) = malloc(sizeof(Graph));
    (*G)->Vex = malloc(h * sizeof(VexNode));
    for (i = 0; V[i].V != 0; ++i) {
        if (i > h - 1) {
            h += N;
            (*G)->Vex = realloc((*G)->Vex, (h) * sizeof(VexNode));
        }
        (*G)->Vex[i].Elem = V[i];
        (*G)->Vex[i].next = NULL;
    }
    (*G)->Size = i;

    VexNode *n, *m;
    n = malloc(sizeof(VexNode));
    m = malloc(sizeof(VexNode));
    while (VR[j].from != 0) {
        n->Elem.V = VR[j].from;
        n->next = NULL;
        m->Elem.V = VR[j].to;
        m->next = NULL;
        InsertArc(*G, *n, *m);
        j++;
    }
    return OK;
}

Status DestroyGraph(Graph **G) {
    if (!*G) return ERROR;
    int i;
    for (i = (*G)->Size - 1; i >= 0; i--) {
        DeleteVex(G, (*G)->Vex[i]);
    }
    free(*G);
    return OK;
}

Status LocateVex(Graph G, VexNode node, int *pPos) {
    int i;
    for (i = 0; i < G.Size; i++) {
        if (G.Vex[i].Elem.V == node.Elem.V) {
            *pPos = i;
            return OK;
        }
    }
    return ERROR;
}

Status GetVex(Graph G, int k, VertexType *elem) {
    int i = 0;
    for (; i < G.Size; i++) {
        if (G.Vex[i].Elem.V == k) {
            *elem = G.Vex[i].Elem;
            return OK;
        }
    }
    return ERROR;
}

Status PutVex(Graph *G, int k, VertexType elem) {
    int i;
    for (i = 0; i < G->Size; i++) {
        if (G->Vex[i].Elem.V == k) {
            G->Vex[i].Elem = elem;
            return OK;
        }
    }
    return ERROR;
}

Status FirstAdjVex(Graph G, int k, VexNode *pNode) {
    int i;
    for (i = 0; i < G.Size; i++) {
        if (G.Vex[i].Elem.V == k) {
            if (G.Vex[i].next == NULL) {
                return ERROR;
            }
            (*pNode) = G.Vex[G.Vex[i].next->Vex];
            return OK;
        }
    }
    return ERROR;
}

Status NextAdjVex(Graph G, VexNode curNode, VexNode adjNode, VexNode *pNextAdjNode) {
    int *i, *j;
    i = malloc(sizeof(int));
    j = malloc(sizeof(int));
    if (LocateVex(G, curNode, i) != OK) {
        return ERROR1;
    }
    if (LocateVex(G, adjNode, j) != OK) {
        return ERROR2;
    }
    ToEdge *e;
    e = G.Vex[*i].next;
    while (e != NULL) {
        if (e->Vex == *j) {
            if (e->next != NULL)
                (*pNextAdjNode) = G.Vex[e->next->Vex];
            else {
                return FALSE;
            }
            return OK;
        }
        e = e->next;
    }
    return ERROR3;
}

Status InsertVex(Graph *G, VexNode node) {
    if (!G) return ERROR;
    node.next = NULL;
    int i;
    for (i = 0; i < G->Size; i++) {
        if (G->Vex[i].Elem.V == node.Elem.V)
            return ERROR;
    }
    G->Vex[G->Size] = node;
    G->Size += 1;
    return OK;
}

Status DeleteVex(pGraph *G, VexNode node) {
    if (!G) return ERROR;
    int *i, k = 0, j, h;
    ToEdge *p, *q;
    i = malloc(sizeof(int));

    if (LocateVex(**G, node, i) != OK) {
        return ERROR;
    }

    p = (*G)->Vex[*i].next;
    (*G)->Vex[*i].next = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    for (; k < (*G)->Size; k++) {
        DeleteArc(*G, (*G)->Vex[k], node);
    }
    for (j = *i; j < (*G)->Size - 1; j++) {
        (*G)->Vex[j] = (*G)->Vex[j + 1];
    }
    (*G)->Size -= 1;

    for (h = 0; h < (*G)->Size; h++) {
        p = (*G)->Vex[h].next;
        while (p != NULL) {
            if (p->Vex >= *i)
                p->Vex = p->Vex - 1;
            p = p->next;
        }
    }
    return OK;
}

Status InsertArc(Graph *G, VexNode curNode, VexNode adjNode) {
    if (!G) return ERROR;
    int *i, *j;
    i = malloc(sizeof(int));
    j = malloc(sizeof(int));

    if (LocateVex(*G, curNode, i) != OK) {
        return ERROR1;
    }
    if (LocateVex(*G, adjNode, j) != OK) {
        return ERROR2;
    }
    ToEdge *num, *mun;;
    mun = malloc(sizeof(ToEdge));
    num = G->Vex[*i].next;
    while (num != NULL) {
        if (num->Vex == *j) return ERROR3;
        num = num->next;
    }
    mun->Vex = *j;
    mun->next = G->Vex[*i].next;
    G->Vex[*i].next = mun;
    return OK;
}

Status DeleteArc(Graph *G, VexNode curNode, VexNode adjNode) {
    if (!G) return ERROR;
    int *i, *j;
    i = malloc(sizeof(int));
    j = malloc(sizeof(int));

    if (LocateVex(*G, curNode, i) != OK) {
        return ERROR1;
    }
    if (LocateVex(*G, adjNode, j) != OK) {
        return ERROR2;
    }
    if (G->Vex[*i].next == NULL)
        return ERROR3;
    ToEdge *b;
    b = G->Vex[*i].next;
    if (b->Vex == *j) {
        G->Vex[*i].next = b->next;
        free(b);
        return OK;
    } else {
        while (b->next != NULL) {
            if (b->next->Vex == *j) {
                b->next = b->next->next;
                return OK;
            }
            b = b->next;
        }
        return ERROR3;
    }
}

Status Visit(VexNode V) {
    printf("The Vertex information is Key: %d  number: %s  name: %s\n",
           V.Elem.V, V.Elem.number, V.Elem.name);
    return OK;
}

Status DFSTraverse(Graph G) {
    if (G.Size == 0) {
        printf("The Graph is empty!\n");
        return ERROR;
    }
    int marked[G.Size + 1];
    int i = 0;
    for (; i < G.Size; i++) {
        marked[i] = 0;
    }
    for (i = 0; i < G.Size; i++) {
        if (marked[i] != 1)
            dfs(G, G.Vex[i], marked);
    }
    return OK;
}

Status dfs(Graph G, VexNode v, int marked[]) {
    int i;
    Visit(v);
    for (i = 0; i < G.Size; ++i) {
        if (G.Vex[i].Elem.V == v.Elem.V) {
            marked[i] = 1;
            break;
        }
    }
    VexNode *pNode;
    pNode = malloc(sizeof(VexNode));
    if (FirstAdjVex(G, v.Elem.V, pNode) != OK) return OK;
    while (1) {
        for (i = 0; i < G.Size; ++i) {
            if (G.Vex[i].Elem.V == pNode->Elem.V) {
                break;
            }
        }
        if (marked[i] == 0)
            dfs(G, *pNode, marked);
        if (NextAdjVex(G, v, *pNode, pNode) != OK) break;
    }
}

Status BFSTraverse(Graph G) {
    if (G.Size == 0) {
        printf("The Graph is empty!\n");
        return ERROR;
    }
    int marked[G.Size];
    int i = 0, k;
    for (; i < G.Size; i++) {
        marked[i] = 0;
    }
    ToEdge *p;
    Queue *Q = InitQueue();
    for (k = 0; k < G.Size; k++) {
        if (marked[k] != 1) {
            push(Q, &G.Vex[k]);
            marked[k] = 1;
            while (empty(*Q) != TRUE) {
                VexNode *q;
                q = pop(Q);
                Visit(*q);
                p = q->next;
                while (p != NULL) {
                    if (marked[p->Vex] != 1) {
                        push(Q, &G.Vex[p->Vex]);
                        marked[p->Vex] = 1;
                    }
                    p = p->next;
                }
            }
        }
    }
    return OK;
}

Status FileWrite(Graph G) {
    char filename[30];
    int i;
    ToEdge *e;
    printf("input file name: ");
    scanf("%s", filename);
    FILE *fp;
    if ((fp = fopen(filename, "w")) == NULL) {
        printf("File open error\n ");
        return FALSE;
    }
    for (i = 0; i < G.Size; ++i) {
        fprintf(fp, "%d ", G.Vex[i].Elem.V);
        fprintf(fp, "%s ", G.Vex[i].Elem.number);
        fprintf(fp, "%s ", G.Vex[i].Elem.name);
    }
    fprintf(fp, "0 ");
    for (i = 0; i < G.Size; ++i) {
        e = G.Vex[i].next;
        while (e != NULL) {
            fprintf(fp, "%d ", G.Vex[i].Elem.V);
            fprintf(fp, "%d ", G.Vex[e->Vex].Elem.V);
            e = e->next;
        }
    }
    fprintf(fp, "0 0 ");
    fclose(fp);
    return OK;
}

Status FileRead(Graph **G) {
    char filename[30];
    int i;
    printf("input file name: ");
    scanf("%s", filename);
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("File open error\n ");
        return FALSE;
    }
    VertexType V[N];
    EdgeType VR[N];
    for (i = 0;; i++) {
        fscanf(fp, "%d", &V[i].V);
        if (V[i].V == 0) break;
        fscanf(fp, "%s", V[i].number);
        fscanf(fp, "%s", V[i].name);
    }
    for (i = 0;; i++) {
        fscanf(fp, "%d", &VR[i].from);
        fscanf(fp, "%d", &VR[i].to);
        if (VR[i].from == 0) break;
    }
    fclose(fp);
    CreateGraph(G, V, VR);
    return OK;
}

Status ChooseTable(GraphTable *G, int n) {
    if (n > G->length || n < 1) {
        printf("Enter the right number(0-%d]\n", G->length);
        return ERROR;
    }
    G->tableSize = n - 1;
    return OK;
}


Status CreateTable(GraphTable *G) {
    if (G->length >= G->MaxSize) {
        Graph *newSize;
        newSize = realloc(G->table, (G->MaxSize + LISTINCREMENT) * sizeof(Graph));
        *G->table = newSize;
        G->MaxSize += LISTINCREMENT;
    }
    G->length++;
    G->tableSize = G->length - 1;
    return OK;
}

Status DeleteTable(GraphTable *G, int n) {
    if (G->length < n) {
        printf("Illegal number!\n");
        return ERROR;
    }
    DestroyGraph(&G->table[G->tableSize]);
    for (; n < G->length; n++) {
        G->table[n - 1] = G->table[n];
    }
    G->length--;
    IsCreate[G->length] = 0;
    G->tableSize = 0;
    return OK;
}