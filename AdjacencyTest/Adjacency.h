#ifndef ADJACENCYTEST_ADJACENCY_H
#define ADJACENCYTEST_ADJACENCY_H

#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define ERROR1 -1
#define ERROR2 -2
#define ERROR3 -3
#define OVERFLOW -2
#define N 15

int IsCreate[10];

typedef int Status;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct VertexType {
    int V;
    char number[10];
    char name[10];
} VertexType;//数据元素类型定义

typedef struct EdgeType {
    int from;
    int to;
} EdgeType;//边与边的关系

typedef struct ToEdge {
    int Vex;
    struct ToEdge *next;
} ToEdge;//

typedef struct VexNode {
    VertexType Elem;
    struct ToEdge *next;
} VexNode, *PVexNode;

typedef struct {
    VexNode *Vex;
    int Size;
} Graph, *pGraph;

typedef struct {
    pGraph *table;
    int tableSize;
    int length;
    int MaxSize;
} GraphTable;


Status CreateGraph(Graph **G, VertexType V[], EdgeType VR[]);

Status DestroyGraph(Graph **G);

Status LocateVex(Graph G, VexNode node, int *pPos);

Status GetVex(Graph G, int k, VertexType *elem);

Status PutVex(Graph *G, int k, VertexType elem);

Status FirstAdjVex(Graph G, int k, VexNode *pNode);

Status NextAdjVex(Graph G, VexNode curNode, VexNode adjNode, VexNode *pNextAdjNode);

Status InsertVex(Graph *G, VexNode node);

Status DeleteVex(pGraph *G, VexNode node);

Status InsertArc(Graph *G, VexNode curNode, VexNode adjNode);

Status DeleteArc(Graph *G, VexNode curNode, VexNode adjNode);

Status DFSTraverse(Graph G);

Status dfs(Graph G, VexNode v, int marked[]);

Status BFSTraverse(Graph G);

Status FileWrite(Graph G);

Status FileRead(Graph **G);

Status Visit(VexNode V);

Status ChooseTable(GraphTable *T, int n);

Status CreateTable(GraphTable *T);

Status DeleteTable(GraphTable *T, int n);


#endif //ADJACENCYTEST_ADJACENCY_H