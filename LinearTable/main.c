#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <mem.h>
#include "LinearTable.h"

int main() {
    TableList T;
    T.MaxSize = LISTINCREMENT;
    T.table=(SqList*)malloc(sizeof(SqList));
    T.length = 1;
    T.tableSize = 0;
    int op = 1;
    while (op) {
        system("cls");	printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty       10. ListInsert\n");
        printf("    	  5. ListLength      11. ListDelete\n");
        printf("    	  6. GetElem         12. ListTrabverse\n");
        printf("    	  13.SaveData        14. ReadData\n");
        printf("    	  15.ChooseTable     16.Multitable\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("Please choose your number: [0~16]:");
        scanf("%d", &op);
        switch(op){
            case 1:
                //printf("\n----IntiaList功能待实现！\n");
                if(T.table[T.tableSize].IsInitial != 1) {
                    if (IntiaList(&T.table[T.tableSize]) == OK) {
                        printf("The linear table was created successfully!\n");
                    } else printf("Linear table creation failed!\n");
                }
                else{
                    printf("Linear table already exists!\n");
                }
                system("pause");
                break;
            case 2:
                //printf("\n----DestroyList功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    if(DestroyList(&T.table[T.tableSize]) == OK){
                        printf("Linear table deletion successfully!\n");
                    }
                    else printf("Linear table deletion failed!\n");
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    if(ClearList(&T.table[T.tableSize]) == OK) printf("Linear table emptying successfully!\n");
                    else printf("Linear table already empty!\n");
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 4:
                //printf("\n----ListEmpty功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    if(ListEmpty(T.table[T.tableSize]) == OK) printf("Linear table is an empty table\n");
                    else printf("Linear table is not an empty table\n");
                }
                else{
                    printf("Linear table does not exist");
                }
                system("pause");
                break;
            case 5:
                //printf("\n----ListLength功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    printf("Linear-table's length is: %d\n", ListLength(T.table[T.tableSize]));
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 6:
                //printf("\n----GetElem功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1) {
                    int m;
                    ElemType x;
                    printf("Where you want to get the number: \n");
                    scanf("%d",&m);
                    if(GetElem(T.table[T.tableSize], m, &x) == OK) {
                        printf("The number is: %s %s\n", x.number, x.name);
                    } else{
                        printf("The number is not exist!\n");
                    }
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 7:
                //printf("\n----LocateElem功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1) {
                    //printf("\n----LocateElem功能待实现！\n");
                    printf("Enter the number you want: ");
                    ElemType e;
                    scanf("%s %s", e.number, e.name);
                    int g;
                    g = LocateElem(T.table[T.tableSize], e);
                    if(g == ERROR)
                        printf("The number is not exit!\n");
                    else{
                        printf("%d\n", g);
                    }
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 8:
                //printf("\n----PriorElem功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    printf("Enter the information: ");
                    ElemType m, n;
                    int h;
                    scanf("%s %s", n.number, n.name);
                    h = PriorElem(T.table[T.tableSize], n, &m);
                    if(h == OK){
                        printf("%s %s\n", m.number, m.name);
                    }
                    else if(h == ERROR)
                        printf("This information does not exist!\n");
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 9:
                // printf("\n----NextElem功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    printf("Enter the information: ");
                    ElemType m,n;
                    int h;
                    scanf("%s %s", n.number, n.name);
                    h = NextElem(T.table[T.tableSize], n, &m);
                    if(h == OK){
                        printf("%s %s\n", m.number, m.name);
                    }
                    else if(h == ERROR)
                        printf("This information does not exist!\n");
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 10:
                //printf("\n----ListInsert功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    printf("Enter the location and number to insert(Location and information): ");
                    int n;
                    scanf("%d", &n);
                    ElemType m;
                    scanf("%s%s", m.number, m.name);
                    if(ListInsert(&T.table[T.tableSize], n, m) == OK)
                        printf("Added successfully!\n");
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 11:
                //printf("\n----ListDelete功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1) {
                    if (T.table[T.tableSize].length == 0) {
                        printf("Empty Table!\n");
                    } else {
                        printf("The location you want to delete: \n");
                        int m;
                        ElemType n;
                        scanf("%d", &m);
                        if (ListDelete(&T.table[T.tableSize], m, &n) == OK)
                            printf("%s %s successfully deleted!\n", n.number, n.name);
                    }
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    if(!ListTrabverse(T.table[T.tableSize])) printf("Linear table is an empty table!\n");
                }
                else{
                    printf("Linear table does not exist!\n");
                }
                system("pause");
                break;
            case 13:
                //printf("\n----保存文件功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    if(Writein(T.table[T.tableSize]) == OK) printf("The data saved successfully!\n");
                }
                else{
                    printf("ERROR\n");
                }
                system("pause");
                break;
            case 14:
                //printf("\n----读取文件功能待实现！\n");
                if(T.table[T.tableSize].IsInitial == 1){
                    if(Readin(&T.table[T.tableSize]) == OK) printf("The data read successfully!\n");
                }
                else{
                    printf("ERROR\n");
                }
                system("pause");
                break;
            case 15:
                //printf("\n----ChooseTable功能待实现！\n");
                    printf("Please enter the table number: \n");
                    int n;
                    scanf("%d", &n);
                    if (n == T.tableSize + 1) {
                        printf("You already in this Linear Table!\n");
                    } else if (ChooseTable(&T, n) == OK)
                        printf("change successful!\n");
                    else {
                        printf("ERROR\n");
                    }
                system("pause");
                break;
            case 16:
                //printf("\n----Multitable功能待实现！\n");
                printf("Number of tables operated at the same time: ");
                int m;
                scanf("%d", &m);
                if(Multitable(&T, m) == OK){
                    printf("successfully!\n");
                }
                system("pause");
                break;
            case 0:
                break;
            default:
                printf("Please select the right action number you need!\n");
                system("pause");
                break;
        }
    }
    printf("Welcome to use this system next time!\n");
    system("pause");
    return 0;
}