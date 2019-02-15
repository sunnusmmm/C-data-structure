#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "LinkList.h"

status IntiaList(LinkList *L){
    ElemType e;
    int i= 1;
    (*L)= (LinkList)malloc(sizeof(LNode));
    if( !(*L) ) exit(OVERFLOW);
    (*L)->next= NULL;
    printf("Enter the information! (EOF end): \n");
    while(scanf("%s %s", e.number, e.name) != EOF){
        if(ListInsert(*L,i,e) == OK){
            printf("Successfully!\n");
            i++;
        }
    }
    return OK;
}

status DestroyList(LinkList L){
    if (!L)
        return ERROR;
    LinkList p, q;
    p = L; q = p->next;
    if(q != NULL){
        free(q);
        q = p;
        p = q->next;
    }
    free(L);
    return OK;
}

status ClearList(LinkList L){
    LinkList p, q;
    p = L->next;
    L->next = NULL;
    if(p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

status ListEmpty(LinkList L){
    if (L->next == NULL ) return TRUE;
    else return FALSE;
}

status ListLength(LinkList L){
    int k;
    LinkList p = L;
    for(k = 0; p->next != NULL; k++){
        p=p->next;
    }
    return k;
}

status GetElem(LinkList L,int i, ElemType *e){
    int k = 1;
    LinkList p = L->next;
    while(p && k < i){
        p = p->next; ++k;
    }
    if(!p || k > i)return ERROR;
    *e = p->elem;
    return OK;
}

status LocateElem(LinkList L, ElemType e){
    LinkList p = L; int m = 0;
    for( int k = 1; p->next != NULL; k++){
        p = p->next;
        if(compare((p->elem), e) == OK){
            printf("%d     ", k); m++;
        }
    }
    printf("\n");
    if(m == 0)
        return ERROR;
    else
        return OK;
}

status PriorElem(LinkList L, ElemType cur, ElemType *pre_e){
    LinkList p = L;
    if(compare(p->next->elem, cur) == OK){
        return FALSE;
    }
    for(; p->next != NULL; p = p->next){
        if(compare((p->next->elem), cur) == OK){
            *pre_e = (p->elem);
            return OK;
        }
    }
    return ERROR;
}

status NextElem(LinkList L, ElemType cur, ElemType *next_e){
    LinkList p = L;
    for(; p->next != NULL; p = p->next){
        if(compare((p->elem), cur) == OK){
            *next_e = (p->next->elem);
            return OK;
        }
    }
    if(compare((p->elem), cur) == OK){
        printf("Don't have NextElem!\n");
        return FALSE;
    }
    return ERROR;
}

status ListInsert(LinkList L,int i, ElemType e){
    LinkList p = L; int j = 0;
    if(!p) return ERROR;
    while(p && j < i - 1){
        p = p->next;
        ++j;
    }
    if((!p && j < i) || i < 1) {
        printf("Please enter the right number(1-%d)!\n", j);
        return ERROR;
    }
    LinkList s;
    s = (LinkList) malloc(sizeof(LNode));
    s->elem = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

status ListDelete(LinkList L, int i, ElemType *e){
    LinkList p = L; int j = 0;
    LinkList q;
    if(!p) return ERROR;
    while(p && j < i - 1){
        p = p->next;
        ++j;
    }
    if((!p && j < i) || i < 1) {
        printf("Please enter the right number(1-%d)!\n", j);
        return ERROR;
    }
    q = p->next; p->next = q->next;
    *e = (q->elem); free(q);
    return OK;
}

status ListTrabverse(LinkList L){
    if(ListEmpty(L))
        return FALSE;
    printf("\n----------- all elements -----------------------\n");
    for (LinkList p = L->next; p != NULL; p = p->next) visit(p->elem);
    printf("\n------------------ end ------------------------\n");
    return OK;
}

status Writein(LinkList L){
    FILE  *fp;  char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL)
    {
        printf("File open error\n ");
        return ERROR;
    }
    LinkList p = L;
    int i=0;
    while (p->next != NULL){
        p = p->next;
        i++;
    }
    p = L->next;
    for(int m = 0;m < i; m++){
        fwrite(&p->elem, sizeof(ElemType), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return OK;
}

status Readin(LinkList L){
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
    {
        printf("File open error\n ");
        return ERROR;
    }
    ClearList(L);
    int m = 1;
    ElemType e;
    while(fread(&e,sizeof(ElemType),1,fp)){
        ListInsert(L, m, e);
        m++;
    }
    fclose(fp);
    return OK;
}

status compare(ElemType L, ElemType m ){
    if(strcmp(L.number, m.number) == 0) return OK;
    else return FALSE;
}

status visit(ElemType L){
    printf("Number: %s     Name: %s\n",L.number, L.name);
}

status ChooseTable(TableList *T, int n){
    if(n > T->length || n < 1){
        printf("Enter the right number(0-%d]\n", T->length);
        return ERROR;
    }
    T->tableSize = n - 1;
    return OK;
}

status CreateTable(TableList *T){
    if(T->length >= T->MaxSize){
        LinkList * newSize;
        newSize = realloc(T->table,(T->MaxSize+LISTINCREMENT)* sizeof(LinkList));
        T->table = newSize;
        T->MaxSize = LISTINCREMENT;
    }
    T->length++;
    T->tableSize = T->length - 1;
    return OK;
}

status DeleteTable(TableList *T, int n){
    if(T->length < n){
        printf("Illegal number!\n");
        return ERROR;
    }
    DestroyList(T->table[n-1]);
    Isinitial[T->tableSize] = 0;
    for(; n < T->length; n++){
        T->table[n-1] = T->table[n];
    }
    T->length--;
    T->tableSize = 0;
    return OK;
}

