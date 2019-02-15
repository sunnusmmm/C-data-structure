#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "TreeTest.h"

int main() {
    TableList T;
    T.MaxSize = LISTINCREMENT;
    T.table = malloc(sizeof(THeader));
    T.length = 1;
    T.tableSize = 0;
    int op = 1;
    while (op) {
        system("cls");
        printf("\n\n");
        printf("      Menu for Binary tree based on chain structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitTree             10. NodeParent\n");
        printf("    	  2. DestroyTree          11. NodeLeftChild\n");
        printf("    	  3. ClearTree            12. NodeRightChild \n");
        printf("    	  4. TreeEmpty            13. LeftSibling\n");
        printf("    	  5. CreateBiTree         14. RightSibling\n");
        printf("    	  6. TreeDepth            15. InsertChild\n");
        printf("    	  7. TreeRoot             16. DeleteChild\n");
        printf("    	  8. NodeValue            17. PreOrderTraverse\n");
        printf("    	  9. NodeAssign           18. InOrderTraverse\n");
        printf("         19. PostOrderTraverse    20. LevelOrderTraverse\n");
        printf("    	 21. ChooseTable          22. CreateTable\n");
        printf("         23. FileWrite            24. FileRead\n");
        printf("         25. outputTree            0. exit\n");
        printf("         26. DeleteTable           \n");
        printf("-------------------------------------------------\n");
        if (T.length == 0)printf("Currently no linked list exists!\n");
        else {
            printf("Now have %d Binary tree!      ", T.length);
            printf("Current table number: %d\n\n", T.tableSize + 1);
        }
        printf("Please choose your number: [0~25]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                //printf("\n----IntiaList功能待实现！\n");
                if (T.length == 0) {
                    printf("Please create a table first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] != 1) {
                    if (InitTree(&T.table[T.tableSize]) == OK) {
                        IsInitTree[T.tableSize] = 1;
                        printf("The Binary tree Initialization successful!\n");
                    } else printf("Binary tree initialization failed!\n");
                } else {
                    printf("Binary tree already exists!\n");
                }
                system("pause");
                break;
            case 2:
                if (T.length == 0) {
                    printf("Please create a table first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (DestroyTree(T.table[T.tableSize]) == OK) {
                        IsInitTree[T.tableSize] = 0;
                        IsCreate[T.tableSize] = 0;
                        printf("Destroy Successfully!\n");
                    } else {
                        printf("Destroy Failed!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 3:
                if (T.length == 0) {
                    printf("Please create a table first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*(T.table[T.tableSize])) == OK) {
                        printf("Binary tree is empty!");
                        system("pause");
                        break;
                    }
                    if (ClearTree(T.table[T.tableSize]) == OK) {
                        printf("ClearTree Successfully!\n");
                        IsCreate[T.tableSize] = 0;
                    } else {
                        printf("Failed!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 4:
                if (T.length == 0) {
                    printf("Please create a table first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == OK) {
                        printf("The Binary tree is empty!");
                    } else {
                        printf("The Binary tree is not empty!");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 5:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (IsCreate[T.tableSize] == 1) {
                        printf("The Binary tree has been created!\n");
                        system("pause");
                        break;
                    }
                    if (CreateBiTree(&T.table[T.tableSize]->header) == OK) {
                        IsCreate[T.tableSize] = 1;
                        printf("Create Successfully!\n");
                    } else {
                        printf("No more child!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 6:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    printf("The Binary-tree's depth is %d", TreeDepth(T.table[T.tableSize]->header));
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 7:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    Tree tree;
                    if (TreeRoot(T.table[T.tableSize], &tree) == OK) {
                        printf("number: %s   name: %s\n", tree.elem->number, tree.elem->name);
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 8:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    printf("Enter the number you want: ");
                    TreeType *num;
                    num = malloc(sizeof(TreeType));
                    pTree pNode;
                    scanf("%s", num->number);
                    if (NodeValue(T.table[T.tableSize]->header, *num, &pNode) == OK) {
                        printf("number: %s    name: %s\n", pNode->elem->number, pNode->elem->name);
                    } else {
                        printf("The information is not exit!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 9:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    TreeType *elem;
                    elem = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want: ");
                    scanf("%s", elem->number);
                    printf("Enter the name you want to change: ");
                    scanf("%s", elem->name);
                    if (NodeAssign(T.table[T.tableSize]->header, *elem, *elem) == OK) {
                        printf("Change successfully!\n");
                    } else {
                        printf("The information is not exit!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 10:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Tree is empty!\n");
                        system("pause");
                        break;
                    }
                    TreeType *mun;
                    pTree pNode1;
                    mun = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want it's Parent: ");
                    scanf("%s", mun->number);
                    if (strcmp(T.table[T.tableSize]->header->elem->number, mun->number) == 0) {
                        printf("It's the Binary-tree root!\n");
                        system("pause");
                        break;
                    }
                    if (NodeParent(T.table[T.tableSize]->header, *mun, &pNode1) == OK) {
                        printf("Parent's information is: number: %s    name: %s\n", pNode1->elem->number,
                               pNode1->elem->name);
                    } else {
                        printf("The information is not exit!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 11:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    TreeType *m;
                    pTree pNode2;
                    int V;
                    m = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want it's LeftChild: ");
                    scanf("%s", m->number);
                    V = NodeLeftChild(T.table[T.tableSize]->header, *m, &pNode2);
                    if (V == OK) {
                        printf("LeftChild's information is: number: %s    name: %s\n", pNode2->elem->number,
                               pNode2->elem->name);
                    } else if (V == ERROR) {
                        printf("The information is not exit!\n");
                    } else {
                        printf("It don't have LeftChild\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 12:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    TreeType *u;
                    pTree pNode3;
                    int W;
                    u = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want it's RightChild: ");
                    scanf("%s", u->number);
                    W = NodeRightChild(T.table[T.tableSize]->header, *u, &pNode3);
                    if (W == OK) {
                        printf("RightChild's information is: number: %s    name: %s\n", pNode3->elem->number,
                               pNode3->elem->name);
                    } else if (W == ERROR) {
                        printf("The information is not exit!\n");
                    } else {
                        printf("It don't have RightChild\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 13:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Tree is empty!\n");
                        system("pause");
                        break;
                    }
                    TreeType *n;
                    pTree pNode4;
                    int E;
                    n = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want it's LeftSibling: ");
                    scanf("%s", n->number);
                    if (strcmp(T.table[T.tableSize]->header->elem->number, n->number) == 0) {
                        printf("It's the Binary tree header!\n");
                        system("pause");
                        break;
                    }
                    E = LeftSibling(T.table[T.tableSize]->header, *n, &pNode4);
                    if (E == OK) {
                        printf("LeftSibling's information is: number: %s    name: %s\n", pNode4->elem->number,
                               pNode4->elem->name);
                    } else if (E == ERROR) {
                        printf("The information is not exit!\n");
                    } else if (E == NO) {
                        printf("Not have LeftSibling!\n");
                    } else {
                        printf("It's LeftSibling!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 14:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    TreeType *mn;
                    pTree pNode5;
                    int Q;
                    mn = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want it's RightSibling: ");
                    scanf("%s", mn->number);
                    if (strcmp(T.table[T.tableSize]->header->elem->number, mn->number) == 0) {
                        printf("It's the Binary-tree's header!\n");
                        system("pause");
                        break;
                    }
                    Q = RightSibling(T.table[T.tableSize]->header, *mn, &pNode5);
                    if (Q == OK) {
                        printf("RightSibling's information is: number: %s    name: %s\n", pNode5->elem->number,
                               pNode5->elem->name);
                    } else if (Q == ERROR) {
                        printf("The information is not exit!\n");
                    } else if (Q == NO) {
                        printf("Not have RightSibling!\n");
                    } else {
                        printf("It's RightChild!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 15:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Binary tree is empty!\n");
                        system("pause");
                        break;
                    }
                    Tree *pT;
                    int orient1, h;
                    TreeType *A, *B;
                    A = malloc(sizeof(TreeType));
                    B = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want to insert: ");
                    scanf("%s", A->number);
                    printf("Enter the number you want to insert (0-lchild 1-rchild): ");
                    scanf("%d", &orient1);
                    if (orient1 != 0 && orient1 != 1) {
                        printf("Illegal number\n");
                        system("pause");
                        break;
                    }
                    printf("Enter the Tree you want to insert: \n");
                    CreateBiTree(&pT);
//                    printf("Enter the child's number you want to insert: ");
//                    scanf("%s", B->number);
//                    printf("Enter the child's name you want to insert: ");
//                    scanf("%s", B->name);
                    h = InsertChild(T.table[T.tableSize]->header, *A, orient1, pT);
                    if (h == OK) {
                        printf("Insert successfully!\n");
                    } else if (h == FALSE) {printf("The insert tree has rchild!\n");}
                    else {
                        printf("The information is not exit!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 16:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (TreeEmpty(*T.table[T.tableSize]) == TRUE) {
                        printf("The Tree is empty!\n");
                        system("pause");
                        break;
                    }
                    int orient2;
                    TreeType *nu;
                    nu = malloc(sizeof(TreeType));
                    printf("Enter the Tree's number you want to delete: ");
                    scanf("%s", nu->number);
                    printf("Enter the number you want to delete(0-lchild 1-rchild): ");
                    scanf("%d", &orient2);
                    if (DeleteChild(T.table[T.tableSize]->header, *nu, orient2) == OK) {
                        printf("Delete successfully!\n");
                    } else {
                        printf("The information is not exit!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 17:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    printf("PreOrderTraverse: \n");
                    if (PreOrderTraverse((T.table[T.tableSize])->header) != OK)
                        printf("The Binary tree is an empty tree!\n");
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 18:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    printf("InOrderTraverse: \n");
                    if (InOrderTraverse((T.table[T.tableSize])->header) != OK)
                        printf("The Binary tree is an empty tree!\n");
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 19:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    printf("PostOrderTraverse: \n");
                    if (PostOrderTraverse((T.table[T.tableSize])->header) != OK)
                        printf("The Binary tree is an empty tree!\n");
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 20:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    printf("LevelOrderTraverse: \n");
                    if (LevelOrderTraverse((T.table[T.tableSize])->header) != OK)
                        printf("The Binary tree is an empty tree!\n");
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 21:
                //printf("\n----ChooseTable功能待实现！\n");
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                printf("Please enter the Binary tree number: \n");
                int n;
                scanf("%d", &n);
                if (n == T.tableSize + 1) {
                    printf("You already in this Binary tree!\n");
                } else if (ChooseTable(&T, n) == OK)
                    printf("change successful!\n");
                else {
                    printf("ERROR\n");
                }
                system("pause");
                break;
            case 22:
                printf("Do you want to create a Binary tree? (1/0)\n");
                int w;
                scanf("%d", &w);
                if (w == 0) {
                    printf("Operation cancellation!\n");
                    system("pause");
                    break;
                } else {
                    if (CreateTable(&T) == OK) {
                        printf("CreateTable successfully!\n");
                    }
                }
                system("pause");
                break;
            case 23:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (FileWrite(T.table[T.tableSize]->header) == OK) {
                        printf("FileWrite Successfully!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 24:
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (FileRead(&T.table[T.tableSize]->header) == OK) {
                        IsCreate[T.tableSize] = 1;
                        printf("FileRead Successfully!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
                }
                system("pause");
                break;
            case 26:
                //printf("\n----DeleteTable功能待实现！\n");
                if (T.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (T.length == 0) {
                    printf("The table is empty!\n");
                    system("pause");
                    break;
                }
                printf("Do you want to delete a Binary tree? (1/0)\n");
                int q;
                scanf("%d", &q);
                if (q == 1) {
                    printf("The Binary tree number you want to delete: ");
                    int k;
                    scanf("%d", &k);
                    if (DeleteTable(&T, k) == OK) {
                        printf("DeleteTable successfully!\n");
                    }
                    system("pause");
                    break;
                } else {
                    printf("Operation cancellation!\n");
                }
                system("pause");
                break;
            case 25:
                if (T.length == 0) {
                    printf("Please create a table first!\n");
                    system("pause");
                    break;
                }
                if (IsInitTree[T.tableSize] == 1) {
                    if (outputTree(T.table[T.tableSize]->header, 0) == OK) {
                        printf("output successfully!\n");
                    } else {
                        printf("The Binary tree is an empty tree!\n");
                    }
                } else {
                    printf("The Binary tree does not init!\n");
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