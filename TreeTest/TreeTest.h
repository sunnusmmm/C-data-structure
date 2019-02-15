#ifndef TREETEST_TREETEST_H
#define TREETEST_TREETEST_H

#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define NO -2
#define INFEASTABLE -1
#define OVERFLOW -2
#define LISTINCREMENT  10

int IsInitTree[100];
int IsCreate[100];

typedef int Status;

typedef struct {
    char number[10];
    char name[10];
} TreeType;

typedef struct plTree {
    TreeType *elem;
    struct plTree *lchild;
    struct plTree *rchild;
} Tree, *pTree;

typedef struct {
    pTree header;
} THeader;

typedef struct {
    THeader **table;
    int tableSize;
    int length;
    int MaxSize;
} TableList;

Status InitTree(THeader **T);

Status CreateBiTree(Tree **T);

Status DestroyTree(THeader *T);

Status DestroyTree2(Tree **T);

Status ClearTree(THeader *T);

Status TreeEmpty(THeader T);

Status TreeDepth(Tree *T);

Status TreeRoot(THeader *T, Tree *root);

Status NodeValue(Tree *T, TreeType num, pTree *pElem);

Status NodeAssign(Tree *T, TreeType num, TreeType elem);

Status NodeParent(Tree *T, TreeType num, pTree *pNode);

Status NodeLeftChild(Tree *T, TreeType num, pTree *pNode);

Status NodeRightChild(Tree *T, TreeType num, pTree *pNode);

Status LeftSibling(Tree *T, TreeType num, pTree *pNode);

Status RightSibling(Tree *T, TreeType num, pTree *pNode);

Status InsertChild(Tree *T, TreeType num, int orient, Tree *pT);

Status DeleteChild(Tree *T, TreeType num, int orient);

Status PreOrderTraverse(Tree *T);

Status InOrderTraverse(Tree *T);

Status PostOrderTraverse(Tree *T);

Status LevelOrderTraverse(Tree *T);

Status FileWrite(Tree *T);

Status Write(Tree *T, FILE *fp);

Status FileRead(Tree **T);

Status Read(Tree **T, FILE *fp);

Status Compare(TreeType L, TreeType M);

Status visit(TreeType);

Status ChooseTable(TableList *T, int n);

Status CreateTable(TableList *T);

Status DeleteTable(TableList *T, int n);

Status outputTree(Tree *T, int n);

#endif //TREETEST_TREETEST_H