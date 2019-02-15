#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "LinearTable.h"

status IntiaList(SqList *L){
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if( !L->elem ) exit(OVERFLOW);
    L->listSize = LIST_INIT_SIZE;
    L->length = 0;
    printf("Enter the information! (EOF end): \n");
    while(scanf("%s %s", L->elem[L->length].number, L->elem[L->length].name)!=EOF){
        if(L->length< LIST_INIT_SIZE-1){
            printf("successfully!\n");
            L->length++;
            printf("Enter the information! (EOF end): \n");
        }
        else{
            printf("Is full!\n");
            break;
        }
    }
    L->IsInitial = 1;
    return OK;
}

status DestroyList(SqList *L){
    free(L->elem);
    L->IsInitial = 0;
    return OK;
}

status ClearList(SqList *L){
    if(L->length == 0)
        return FALSE;
    L->length = 0;
    return OK;
}

status ListEmpty(SqList L){
    if (L.length == 0 ) return TRUE;
    else return FALSE;
}

status ListLength(SqList L){
    return L.length;
}

status GetElem(SqList L, int i, ElemType *e){
    if(L.length == 0 || i < 1 || L.length < i){
        printf("This information does not exist!\n");
        return ERROR;
    }
    *e = L.elem[i-1];
    return OK;
}

status LocateElem(SqList L, ElemType e){
    for(int i = 1; i <= L.length; i++){
        if(compare(L.elem[i-1], e) == OK){
            return i;
        }
    }
    return ERROR;
}

status PriorElem(SqList L, ElemType cur, ElemType *pre_e){
    if (compare(L.elem[0], cur)) {
        printf("Don't have PriorElem!\n");
        return FALSE;
    }
    for(int i = 0; i < L.length; i++){
        if(compare(L.elem[i], cur)){
            *pre_e = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

status NextElem(SqList L, ElemType cur, ElemType *next_e){
    for(int m = 0; m < L.length ; m++){
        if(compare(L.elem[m], cur) == OK){
            if(m == L.length - 1){
                printf("Don't have NextElem!\n");
                return FALSE;
            }
            *next_e = L.elem[m +1];
            return OK;
        }
    }
    return ERROR;
}

status ListInsert(SqList *L,int i, ElemType e){
    if (!L->elem) return  ERROR;
    else if (i < 1 || i > L->length + 1) {
        printf("Enter a valid number!\n");
        return ERROR;
    }
    else {
        if(L->length >= L->listSize) {
            ElemType *newbase;
            newbase = (ElemType*)realloc(L->elem,(L->listSize + LISTINCREMENT)* sizeof(ElemType));
            if(!newbase) exit(OVERFLOW);
            L->elem = newbase;
            L->listSize += LISTINCREMENT;
        }
        for(int m = 0; m <= L->length - i ; m++){
            L->elem[L->length-m] = L->elem[L->length-m-1];
        }
    }
    L->elem[i-1] = e;
    ++L->length;
    return OK;
}

status ListDelete(SqList *L, int i, ElemType *e){
    if (!L) return ERROR;
    else if(L->length == 0){
        return ERROR;
    }
    else if(i > L->length || i < 1) return ERROR;
    *e = L->elem[i-1];
    for(int j = i-1; j < L->length; j++)
        L->elem[j] = L->elem[j+1];
    L->length--;
    return OK;
}

status ListTrabverse(SqList L){
    int i;
    printf("\n----------- all elements -----------------------\n");
    for (i = 0; i < L.length; i++) visit(L.elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L.length;
}

status Writein(SqList L){
    FILE  *fp;  char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL)
    {
        printf("File open erroe\n ");
        return ERROR;
    }
    fwrite(L.elem, sizeof(ElemType), (size_t) L.length, fp);
    fclose(fp);
    return OK;
}

status Readin(SqList *L){
    FILE  *fp;
    L->length=0;char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
    {
        printf("File open erroe\n ");
        return ERROR;
    }
    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
        L->length++;
//这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读//取的数据元素恢复内存中的物理结构。
    fclose(fp);
    return OK;
}

status compare(ElemType L, ElemType m ){
    if((strcmp(L.number, m.number) == 0) && (strcmp(L.name, m.name) == 0)) return OK;
    else return FALSE;
}

status visit(ElemType L){
    printf("%s %s\n", L.name, L.number);
    return OK;
}

status Multitable(TableList *T, int n){
    T->MaxSize = n;
    free(T);
    T->table=(SqList*)malloc(T->MaxSize*sizeof(SqList));
    T->length = T->MaxSize;
    T->tableSize = 0;
    return OK;
}

status ChooseTable(TableList *T, int n){
    if(n > T->length || n < 1) {
        printf("Enter the right number(0-%d)\n", T->length);
        return ERROR;
    }
    T->tableSize = n - 1;
    return OK;
}