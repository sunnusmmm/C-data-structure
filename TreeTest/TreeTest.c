#include <mem.h>
#include <stdio.h>
#include <malloc.h>
#include "TreeTest.h"
#include "Queue.h"

Status InitTree(THeader **pTree) {
    *pTree = malloc(sizeof(THeader));
    if (!(*pTree)) exit(OVERFLOW);
    (*pTree)->header = NULL;
    return OK;
}

Status CreateBiTree(Tree **T) {
    TreeType *c;
    c = malloc(sizeof(TreeType));
    printf("Please enter the information number(EOF end!): ");
    if (scanf("%s", c->number) == EOF) {
        return OK;
    } else if (strcmp(c->number, "#") == 0) {
        *T = NULL;
        return ERROR;
    } else {
        printf("Please enter the information name: ");
        scanf("%s", c->name);
        *T = malloc(sizeof(Tree));
        if (!*T) {
            printf("ERROR!");
            exit(ERROR);
        }
        (*T)->elem = c;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    if (CreateBiTree(&(*T)->lchild) == OK || CreateBiTree(&(*T)->rchild) == OK) {
        return OK;
    }
}

Status DestroyTree(THeader *T) {
    if (T) {
        DestroyTree2(&T->header);
        free(T);
    }
    return OK;
}

Status DestroyTree2(Tree **T) {
    if (!*T) {
        return ERROR;
    }
    DestroyTree2(&(*T)->lchild);
    DestroyTree2(&(*T)->rchild);
    free(*T);
    *T = NULL;
    return OK;
}

Status ClearTree(THeader *T) {
    if (!T->header) return ERROR;
    DestroyTree2(&T->header);
    T->header = NULL;
    return OK;
}

Status TreeEmpty(THeader T) {
    if (T.header == NULL)
        return OK;
    else
        return FALSE;
}

Status TreeDepth(Tree *T) {
    if (!T) return 0;
    int right = TreeDepth(T->rchild);
    int left = TreeDepth(T->lchild);
    return right > left ? right + 1 : left + 1;
}

Status TreeRoot(THeader*T, Tree *root) {
    if (!T) return ERROR;
    root->rchild = T->header->rchild;
    root->lchild = T->header->lchild;
    root->elem = T->header->elem;
    return OK;
}

Status NodeValue(Tree *T, TreeType num, pTree *pNode) {
    if (T) {
        if (Compare(num, *(T->elem)) == OK) {
            *(pNode) = T;
            return OK;
        }
        if (NodeValue(T->lchild, num, pNode) == OK || NodeValue(T->rchild, num, pNode) == OK) {
            return OK;
        }
    }
    return ERROR;
}

Status NodeAssign(Tree *T, TreeType num, TreeType elem) {
    if (!T)return ERROR;
    if (Compare(*(T->elem), num) == OK) {
        *(T->elem) = elem;
        return OK;
    }
    if (NodeAssign(T->lchild, num, elem) == OK || NodeAssign(T->rchild, num, elem) == OK) {
        return OK;
    }
    return ERROR;
}

Status NodeParent(Tree *T, TreeType num, pTree *pNode) {
    if (!T) return ERROR;
    if (T->lchild) {
        if (Compare(*(T->lchild->elem), num) == OK) {
            *(pNode) = T;
            return OK;
        }
    }
    if (!T->rchild) {
        if (Compare(*(T->rchild->elem), num) == OK) {
            *(pNode) = T;
            return OK;
        }
    }
    if (NodeParent(T->lchild, num, pNode) == OK || NodeParent(T->rchild, num, pNode) == OK) {
        return OK;
    }
    return ERROR;
}

Status NodeLeftChild(Tree *T, TreeType num, pTree *pNode) {
    if (!T) return ERROR;
    if (Compare(*(T->elem), num)) {
        if (T->lchild) {
            *(pNode) = T->lchild;
            return OK;
        } else return FALSE;
    }
    if (NodeLeftChild(T->lchild, num, pNode) == OK || NodeLeftChild(T->rchild, num, pNode) == OK) {
        return OK;
    }
    if (NodeLeftChild(T->lchild, num, pNode) == FALSE || NodeLeftChild(T->rchild, num, pNode) == FALSE) {
        return FALSE;
    }
    return ERROR;
}

Status NodeRightChild(Tree *T, TreeType num, pTree *pNode) {
    if (!T) return ERROR;
    if (Compare(*(T->elem), num)) {
        if (T->rchild) {
            *(pNode) = T->rchild;
            return OK;
        } else return FALSE;
    }
    if (NodeRightChild(T->lchild, num, pNode) == OK || NodeRightChild(T->rchild, num, pNode) == OK) {
        return OK;
    }
    if (NodeRightChild(T->lchild, num, pNode) == FALSE || NodeRightChild(T->rchild, num, pNode) == FALSE) {
        return FALSE;
    }
    return ERROR;
}

Status LeftSibling(Tree *T, TreeType num, pTree *pNode) {
    if (!T) return ERROR;
    if (T->rchild) {
        if (Compare(*(T->rchild->elem), num) == OK) {
            if (T->lchild) {
                *(pNode) = T->lchild;
                return OK;
            } else
                return NO;
        }
    }
    if (T->lchild) {
        if (Compare(*(T->lchild->elem), num)) return FALSE;

    }
    if (LeftSibling(T->lchild, num, pNode) == OK || LeftSibling(T->rchild, num, pNode) == OK) {
        return OK;
    }
    if (LeftSibling(T->lchild, num, pNode) == FALSE || LeftSibling(T->rchild, num, pNode) == FALSE) {
        return FALSE;
    }
    if (LeftSibling(T->lchild, num, pNode) == NO || LeftSibling(T->rchild, num, pNode) == NO) {
        return NO;
    }
    return ERROR;
}

Status RightSibling(Tree *T, TreeType num, pTree *pNode) {
    if (!T) return ERROR;
    if (T->lchild) {
        if (Compare(*(T->lchild->elem), num) == OK) {
            if (T->rchild) {
                *(pNode) = T->rchild;
                return OK;
            } else
                return NO;
        }
    }
    if (T->rchild) {
        if (Compare(*(T->rchild->elem), num)) return FALSE;
    }
    if (RightSibling(T->lchild, num, pNode) == OK || RightSibling(T->rchild, num, pNode) == OK) {
        return OK;
    }
    if (RightSibling(T->lchild, num, pNode) == FALSE || RightSibling(T->rchild, num, pNode) == FALSE) {
        return FALSE;
    }
    if (RightSibling(T->lchild, num, pNode) == NO || RightSibling(T->rchild, num, pNode) == NO) {
        return NO;
    }
    return ERROR;
}

Status InsertChild(Tree *T, TreeType num, int orient, Tree *pT) {
    if (!T) return ERROR;
    if (Compare(*(T->elem), num) == OK) {
        if(pT->rchild != NULL) return FALSE;
        if (orient == 0) {
            if (!T->lchild) {
                T->lchild = pT;
                return OK;
            } else {
                pT->rchild = T->lchild;
                T->lchild = pT;
                return OK;
            }
        } else {
            if (!T->rchild) {
                T->rchild = pT;
                return OK;
            } else {
                pT->rchild = T->rchild;
                T->rchild = pT;
                return OK;
            }
        }
    }
    if (InsertChild(T->lchild, num, orient, pT) == OK || InsertChild(T->rchild, num, orient, pT) == OK) {
        return OK;
    }
    return ERROR;
}

Status DeleteChild(Tree *T, TreeType num, int orient) {
    if (!T) return ERROR;
    if (Compare(*(T->elem), num)) {
        if (orient == 0) {
            if (T->lchild) {
                DestroyTree2(&T->lchild);
                return OK;
            } else {
                return ERROR;
            }
        } else {
            if (T->rchild) {
                DestroyTree2(&T->rchild);
                return OK;
            } else {
                return ERROR;
            }
        }
    }
    if (DeleteChild(T->lchild, num, orient) == OK || DeleteChild(T->rchild, num, orient) == OK) {
        return OK;
    }
}

Status PreOrderTraverse(Tree *T) {
    if (!T) {
        return ERROR;
    }
    if (strcmp(T->elem->number, "#") != 0)
        visit(*(T->elem));
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return OK;
}

Status InOrderTraverse(Tree *T) {
    if (!T) {
        return ERROR;
    }
    InOrderTraverse(T->lchild);
    if (strcmp(T->elem->number, "#") != 0)
        visit(*(T->elem));
    InOrderTraverse(T->rchild);
    return OK;
}

Status PostOrderTraverse(Tree *T) {
    if (!T) {
        return ERROR;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    if (strcmp(T->elem->number, "#") != 0)
        visit(*(T->elem));
    return OK;
}

Status LevelOrderTraverse(Tree *T) {
    if (!T) return ERROR;
    Queue *Q;
    Tree *e;
    Q = InitQueue();
    push(Q, T);
    while (empty(*Q) != TRUE) {
        e = pop(Q);
        printf("number: %s    name: %s\n", e->elem->number, e->elem->name);
        if (e->lchild) {
            push(Q, e->lchild);
        }
        if (e->rchild) {
            push(Q, e->rchild);
        }
    }
    free(Q);
    return OK;
}

Status FileWrite(Tree *T) {
    if (!T) {
        printf("Please create Tree first!\n");
        return ERROR;
    }
    char filename[30];
    printf("input file name: ");
    scanf("%s", filename);
    FILE *fp;
    if ((fp = fopen(filename, "w")) == NULL) {
        printf("File open error\n ");
        return FALSE;
    }
    Write(T, fp);
    fclose(fp);
    return OK;
}

Status Write(Tree *T, FILE *fp) {
    if (!T) {
        fprintf(fp, "# ");
        return OK;
    } else {
        fprintf(fp, "%s ", T->elem->number);
        fprintf(fp, "%s ", T->elem->name);
    }
    Write(T->lchild, fp);
    Write(T->rchild, fp);
    return OK;
}

Status FileRead(Tree **T) {
    FILE *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    DestroyTree2(T);
    Read(T, fp);
    fclose(fp);
    return OK;
}

Status Read(Tree **T, FILE *fp) {
    TreeType *e;
    e = malloc(sizeof(TreeType));
    fscanf(fp, "%s", e->number);
    if (strcmp(e->number, "#") == 0) {
        *T = NULL;
        return OK;
    } else {
        fscanf(fp, "%s", e->name);
        *T = malloc(sizeof(Tree));
        (*T)->elem = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    Read(&(*T)->lchild, fp);
    Read(&(*T)->rchild, fp);
    return OK;
}


Status Compare(TreeType L, TreeType M) {
    if (strcmp(L.number, M.number) == 0) return OK;
    else return FALSE;
}

Status visit(TreeType L) {
    printf("Number: %s     Name: %s\n", L.number, L.name);
    return OK;
}

Status ChooseTable(TableList *T, int n) {
    if (n > T->length || n < 1) {
        printf("Enter the right number(0-%d]\n", T->length);
        return ERROR;
    }
    T->tableSize = n - 1;
    return OK;
}


Status CreateTable(TableList *T) {
    if (T->length >= T->MaxSize) {
        THeader *newSize;
        newSize = realloc(T->table, (T->MaxSize + LISTINCREMENT) * sizeof(THeader));
        *T->table = newSize;
        T->MaxSize += LISTINCREMENT;
    }
    T->length++;
    T->tableSize = T->length - 1;
    return OK;
}

Status DeleteTable(TableList *T, int n) {
    if (T->length < n) {
        printf("Illegal number!\n");
        return ERROR;
    }
    DestroyTree(T->table[T->tableSize]);
    IsInitTree[T->tableSize] = 0;
    for (; n < T->length; n++) {
        T->table[n - 1] = T->table[n];
    }
    T->length--;
    IsCreate[T->length] = 0;
    T->tableSize = 0;
    return OK;
}

Status outputTree(Tree *T, int n) {
    if (!T) return ERROR;
    int i;
    while (T != NULL) {
        outputTree(T->rchild, n + 5);
        for (i = 1; i <= n; i++) {
            printf(" ");
        }
        printf("%s\n", T->elem->number);
        outputTree(T->lchild, n + 5);
        T = NULL;
    }
    return OK;
}