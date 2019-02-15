#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <mem.h>
#include "Adjacency.h"

int main() {
    GraphTable G;
    G.MaxSize = LISTINCREMENT;
    G.table = malloc(G.MaxSize * sizeof(Graph));
    G.length = 1;
    G.tableSize = 0;
    int op = 1;
    while (op) {
        system("cls");
        printf("\n\n");
        printf("      Menu for Graph based on adjacency list \n");
        printf("-------------------------------------------------\n");
        printf("         1. CreateGraph      8. InsertVex \n");
        printf("         2. DestroyGraph     9. DeleteVex\n");
        printf("         3. LocateVex       10. InsertArc \n");
        printf("         4. GetVex          11. DeleteArc\n");
        printf("         5. PutVex          12. DFSTraverse\n");
        printf("         6. FirstAdjVex     13. BFSTraverse\n");
        printf("         7. NextAdjVex      14. CreateGraph\n");
        printf("        15. DestroyGraph    16. ChooseGraph\n");
        printf("        17. FileWrite       18. FileRead\n");
        printf("         0. Exit\n");
        printf("-------------------------------------------------\n");
        if (G.length == 0)printf("Currently no Graph exists!\n");
        else {
            printf("Now have %d Graph!      ", G.length);
            printf("Current Graph number: %d\n\n", G.tableSize + 1);
        }
        printf("Please choose your number: [0~18]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if (IsCreate[G.tableSize] == 0) {
                    printf("Vertices are there:\n");
                    int i = 0, k = 0, h = N;
                    VertexType V[h];
                    EdgeType VR[h];
                    while (1) {
                        printf("Vex %d: \n", i + 1);
                        printf("Please enter the Vex Key(Don't enter the same Key): ");
                        scanf("%d", &V[i].V);
                        if (V[i].V == 0) break;
                        printf("Please enter the Vex number information: ");
                        scanf("%s", V[i].number);
                        printf("Please enter the Vex name information: ");
                        scanf("%s", V[i].name);
                        printf("\n");
                        i++;
                    }
                    printf("Please enter the edge and edge relationship:\n");
                    while (1) {
                        scanf("%d  %d", &VR[k].from, &VR[k].to);
                        if (VR[k].from == 0) break;
                        k++;
                    }
                    if (CreateGraph(&G.table[G.tableSize], V, VR) == OK) {
                        printf("The Graph was created successfully!\n");
                        IsCreate[G.tableSize] = 1;
                    } else printf("The Graph creation failed!\n");
                } else {
                    printf("The Graph has exited!\n");
                }
                system("pause");
                break;
            case 2:
                if (IsCreate[G.tableSize] == 1) {
                    if (DestroyGraph(&G.table[G.tableSize]) == OK) {
                        IsCreate[G.tableSize] = 0;
                        printf("The Graph deletion successfully!\n");
                    }
                } else {
                    printf("The Graph has exited!\n");
                }
                system("pause");
                break;
            case 3:
                if (IsCreate[G.tableSize] == 1) {
                    printf("Enter the VexNode information you need: ");
                    VexNode *a;
                    a = malloc(sizeof(VexNode));
                    int pPos;
                    scanf("%d", &a->Elem.V);
                    if (LocateVex(*G.table[G.tableSize], *a, &pPos) == OK)
                        printf("Vertex position information is: %d\n", pPos);
                    else printf("This information does not exist!\n");
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 4:
                if (IsCreate[G.tableSize] == 1) {
                    printf("Enter the VexNode information you need: ");
                    int b;
                    VertexType *elem;
                    elem = malloc(sizeof(VertexType));
                    scanf("%d", &b);
                    if (GetVex(*G.table[G.tableSize], b, elem) == OK)
                        printf("The Vex information is: Key: %d  number: %s  name: %s\n", elem->V, elem->number,
                               elem->name);
                    else printf("This information does not exist!\n");
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 5:
                if (IsCreate[G.tableSize] == 1) {
                    int q;
                    VertexType *m;
                    m = malloc(sizeof(VertexType));
                    printf("The Vex key: ");
                    scanf("%d", &q);
                    m->V = q;
                    printf("The Vex information you want to change to:(number/name) ");
                    scanf("%s %s", m->number, m->name);
                    if (PutVex(G.table[G.tableSize], q, *m) == OK)
                        printf("The information of the vertex was successfully modified!\n");
                    else {
                        printf("This information does not exist!\n");
                    }
                } else { printf("The Graph does not exist!\n"); }
                system("pause");
                break;
            case 6:
                if (IsCreate[G.tableSize] == 1) {
                    int m;
                    VexNode x;
                    printf("You want to get the first neighbor of that vertex's key: ");
                    scanf("%d", &m);
                    if (FirstAdjVex(*G.table[G.tableSize], m, &x) == OK) {
                        printf("The first neighbor information is: Key: %d number: %s name: %s\n", x.Elem.V,
                               x.Elem.number, x.Elem.name);
                    } else {
                        printf("This information does not exist!\n");
                    }
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 7:
                if (IsCreate[G.tableSize] == 1) {
                    VexNode *curNode, *adjNode;
                    VexNode *pNextAdjNode;
                    int k;
                    curNode = malloc(sizeof(VexNode));
                    adjNode = malloc(sizeof(VexNode));
                    pNextAdjNode = malloc(sizeof(VexNode));
                    printf("You want to get the vertex's key: ");
                    scanf("%d", &curNode->Elem.V);
                    printf("You want to get the next of that vertex's key: ");
                    scanf("%d", &adjNode->Elem.V);
                    k = NextAdjVex(*G.table[G.tableSize], *curNode, *adjNode, pNextAdjNode);
                    if (k == OK) {
                        printf("The next information is: Key: %d  number: %s  name: %s\n",
                               pNextAdjNode->Elem.V, pNextAdjNode->Elem.number, pNextAdjNode->Elem.name);
                    } else if (k == ERROR1) {
                        printf("The starting point does not exist!\n");
                    } else if (k == ERROR2) {
                        printf("The ending point does not exist!\n");
                    } else if (k == ERROR3) {
                        printf("No connection in two vertices!\n");
                    } else if (k == FALSE) {
                        printf("No subsequent adjacency!\n");
                    }
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 8:
                if (IsCreate[G.tableSize] == 1) {
                    VexNode *a;
                    a = malloc(sizeof(VexNode));
                    printf("Enter the insert vertex information:\n");
                    printf("The vertex Key:");
                    scanf("%d", &a->Elem.V);
                    printf("The vertex number:");
                    scanf("%s", a->Elem.number);
                    printf("The vertex name:");
                    scanf("%s", a->Elem.name);
                    if (InsertVex(G.table[G.tableSize], *a) == OK) {
                        printf("Insert successfully!\n");
                    } else {
                        printf("The vertex's key has exited!\n");
                    }
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 9:
                if (IsCreate[G.tableSize] == 1) {
                    VexNode *a;
                    a = malloc(sizeof(VexNode));
                    printf("The vertex's key you want to delete: ");
                    scanf("%d", &a->Elem.V);
                    if (DeleteVex(&G.table[G.tableSize], *a) == OK) {
                        printf("DeleteVex successfully!\n");
                    } else {
                        printf("The VexNode does not exist!\n");
                    }
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 10:
                if (IsCreate[G.tableSize] == 1) {
                    VexNode *a;
                    VexNode *b;
                    int h;
                    a = malloc(sizeof(VexNode));
                    b = malloc(sizeof(VexNode));
                    printf("The Arc relationship you want to add: \n");
                    printf("The from vertex's key: ");
                    scanf("%d", &a->Elem.V);
                    printf("The to vertex's key: ");
                    scanf("%d", &b->Elem.V);
                    h = InsertArc(G.table[G.tableSize], *a, *b);
                    if (h == OK) {
                        printf("InsertArc successfully!\n");
                    } else if (h == ERROR1) {
                        printf("The starting point does not exist!\n");
                    } else if (h == ERROR2) {
                        printf("The ending point does not exist!\n");
                    } else if (h == ERROR3) {
                        printf("Connection in two vertices has exited!\n");
                    }
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 11:
                if (IsCreate[G.tableSize] == 1) {
                    VexNode *a;
                    VexNode *b;
                    int g;
                    a = malloc(sizeof(VexNode));
                    b = malloc(sizeof(VexNode));
                    printf("The Arc relationship you want to delete: \n");
                    printf("The from vertex's key: ");
                    scanf("%d", &a->Elem.V);
                    printf("The to vertex's key: ");
                    scanf("%d", &b->Elem.V);
                    g = DeleteArc(G.table[G.tableSize], *a, *b);
                    if (g == OK) {
                        printf("DeleteArc successfully!\n");
                    } else if (g == ERROR1) {
                        printf("The starting point does not exist!\n");
                    } else if (g == ERROR2) {
                        printf("The ending point does not exist!\n");
                    } else if (g == ERROR3) {
                        printf("Connection in two vertices does not exited!\n");
                    }
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 12:
                if (IsCreate[G.tableSize] == 1) {
                    if (DFSTraverse(*G.table[G.tableSize]) == OK)
                        printf("BFSTraverse successfully!\n");
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 13:
                if (IsCreate[G.tableSize] == 1) {
                    if (BFSTraverse(*G.table[G.tableSize]) == OK)
                        printf("BFSTraverse successfully!\n");
                } else {
                    printf("The Graph does not exist!\n");
                }
                system("pause");
                break;
            case 14:
                printf("Do you want to create a Graph? (1/0)\n");
                int w;
                scanf("%d", &w);
                if (w == 0) {
                    printf("Operation cancellation!\n");
                    system("pause");
                    break;
                } else {
                    if (CreateTable(&G) == OK) {
                        printf("CreateTable successfully!\n");
                    }
                }
                system("pause");
                break;
            case 15:
                if (G.length == 0) {
                    printf("Please create a Graph first!\n");
                    system("pause");
                    break;
                }
                printf("Do you want to delete the Graph? (1/0)\n");
                int q;
                scanf("%d", &q);
                if (q == 1) {
                    if (IsCreate[G.tableSize] != 0) {
                        if (DeleteTable(&G, G.tableSize) == OK) {
                            printf("DeleteTable successfully!\n");
                        }
                        system("pause");
                        break;
                    } else {
                        printf("The Graph has not been created yet!\n");
                    }
                } else {
                    printf("Operation cancellation!\n");
                }
                system("pause");
                break;
            case 16:
                if (G.length == 0) {
                    printf("Please create a Graph first!\n");
                    system("pause");
                    break;
                }
                printf("Please enter the Graph number: \n");
                int n;
                scanf("%d", &n);
                if (n == G.tableSize + 1) {
                    printf("You already in this Graph!\n");
                } else if (ChooseTable(&G, n) == OK)
                    printf("change successful!\n");
                else {
                    printf("ERROR\n");
                }
                system("pause");
                break;
            case 17:
                if (G.length == 0) {
                    printf("Please create a Graph first!\n");
                    system("pause");
                    break;
                }
                if (IsCreate[G.tableSize] == 1) {
                    if (FileWrite(*G.table[G.tableSize]) == OK) {
                        printf("FileRead Successfully!\n");
                    }
                } else {
                    printf("The Graph does not init!\n");
                }
                system("pause");
                break;
            case 18:
                if (G.length == 0) {
                    printf("Please create a Binary tree first!\n");
                    system("pause");
                    break;
                }
                if (FileRead(&G.table[G.tableSize]) == OK) {
                    IsCreate[G.tableSize] = 1;
                    printf("FileRead Successfully!\n");
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