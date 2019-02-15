#ifndef CLION_FILE_LINEARTABLE_H
#define CLION_FILE_LINEARTABLE_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef struct{
    char number[10];
    char name[10];
}ElemType;//数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{
    ElemType * elem;
    int length;
    int listSize;
    int IsInitial;
}SqList;//顺序表（顺序结构）的定义

typedef struct{
    SqList * table;
    int tableSize;
    int length;
    int MaxSize;
}TableList;//多表操作结构的定义

status IntiaList(SqList *L);
status DestroyList(SqList *L);
status ClearList(SqList *L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L,int i,ElemType *e);
status LocateElem(SqList L,ElemType e);
status PriorElem(SqList L,ElemType cur,ElemType *pre_e);
status NextElem(SqList L,ElemType cur,ElemType *next_e);
status ListInsert(SqList *L,int i,ElemType e);
status ListDelete(SqList *L,int i,ElemType *e);
status ListTrabverse(SqList L);
status Readin(SqList *L);
status Writein(SqList L);
status compare(ElemType L, ElemType m);
status visit(ElemType L);

status Multitable(TableList *T, int n);
status ChooseTable(TableList *T, int n);

#endif //CLION_FILE_LINEARTABLE_H
