#ifndef CLION_FILE_LINEARTABLE_H
#define CLION_FILE_LINEARTABLE_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASTABLE -1
#define OVERFLOW -2

int Isinitial[10];

typedef int status;
typedef struct{
    char number[10];
    char name[10];
}ElemType;//数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct Node{
    ElemType elem;
    struct Node* next;
}LNode, *LinkList;//顺序表（顺序结构）的定义

typedef struct{
    LinkList * table;
    int tableSize;
    int length;
    int MaxSize;
}TableList;//多表操作结构的定义

status IntiaList(LinkList *L);
status DestroyList(LinkList L);
status ClearList(LinkList L);
status ListEmpty(LinkList L);
status ListLength(LinkList L);
status GetElem(LinkList L,int i,ElemType *e);
status LocateElem(LinkList L,ElemType e);
status PriorElem(LinkList L,ElemType cur,ElemType *pre_e);
status NextElem(LinkList L,ElemType cur,ElemType *next_e);
status ListInsert(LinkList L,int i,ElemType e);
status ListDelete(LinkList L,int i,ElemType *e);
status ListTrabverse(LinkList L);
status Readin(LinkList L);
status Writein(LinkList L);
status compare(ElemType L, ElemType m);
status visit(ElemType L);

status ChooseTable(TableList *T, int n);
status CreateTable(TableList *T);
status DeleteTable(TableList *T, int n);

#endif //CLION_FILE_LINEARTABLE_H

