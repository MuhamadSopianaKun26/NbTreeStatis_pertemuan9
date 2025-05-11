#include "ADT_nbt_statis.h"
#include "boolean.h"

/*************************/
/* S P E S I F I K A S I */
/*************************/

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    int currentChild, currentLevel;
    for (int i = 0 ; i < jml_maks ; i++) {
        X[i].info = '\0';
        X[i].ps_fs= nil;
        X[i].ps_nb= nil;
        X[i].ps_pr= nil;
    }

    printf ("Masukan isi root : ");
    scanf (" %c", &X[1].info);
    X[1].ps_fs = nil;
    X[1].ps_nb = nil;
    X[1].ps_pr = nil;

    for (i = 2 ; i<=Jml_Node ; i++) {
        infotype input;
        int parent;
        boolean ValidParent = false;

        printf ("Masukan isi dari node ke-%d : ", i);
        scanf(" %c", &input);

        while (!ValidParent) {
            printf ("Masukan parent dari node tersebut : ");
            scanf ("%d", &parent);

            if (X[parent].info != '\0' && parent >=1 && parent < i) {
                ValidParent = true;
                X[i].ps_pr = parent;

                if (X[parent].ps_fs == nil) {
                    X[parent].ps_fs = i;
                } else {
                    currentChild = X[parent].ps_fs;
                    while (X[currentChild].ps_nb != nil) {
                        currentChild = X[currentChild].ps_nb;
                    }
                    X[currentChild].ps_nb = i;
                }

                X[i].info = input;
                X[i].ps_fs = nil;
                X[i].ps_nb = nil;

                break;
            }
            if (!ValidParent) {
                printf("indeks parent tidak ditemukan!\n");
            }
        }
    }

};

boolean IsEmpty (Isi_Tree P) {
    return (P[1].info == '\0');
}

/***** Traversal *****/
void PreOrder (Isi_Tree P) {
    if (IsEmpty(P)) return;

    address stack[jml_maks];
    int top = -1, i;

    stack[++top] = 1;
    while (top >= 0) {
        address current = stack[top--];
        printf ("%c --> ", P[current].info);

        address child = P[current].ps_fs;
        address temp[jml_maks];
        int count = 0;

        while (child != nil) {
            temp[count++] = child;
            child = P[child].ps_nb;
        }

        for (i = count - 1;i>=0;i--){
            stack[++top] = temp[i];
        }
    }
}

void InOrder (Isi_Tree P) {
    if (IsEmpty(P)) return;

    address stack[jml_maks];
    int top = -1;
    address current = 1;

    while (current != nil || top >=0) {
        while (current != nil) {
            stack[++top] = current;
            current = P[current].ps_fs;
        }

        current = stack[top--];
        printf ("%c --> ", P[current].info);

        current = P[current].ps_nb;
    }
}

void PostOrder (Isi_Tree P) {
    if (IsEmpty(P)) return;

    address stack1[jml_maks];
    address stack2[jml_maks];
    int top1 = -1, top2 = -1;

    stack1[++top1] = 1;

    while (top1 >= 0 ) {
        address current = stack1[top1--];
        stack2[++top2] = current;

        address child = P[current].ps_fs;
        while (child != nil) {
            stack1[++top1] = child;
            child = P[child].ps_nb;
        }
    }

    while (top2 >= 0) {
        printf("%c --> ", P[stack2[top2--]].info);
    }

}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) {
        printf("Tree kosong!\n");
        return;
    }

    if (Maks_node <=0 || Maks_node >jml_maks) {
        Maks_node = jml_maks;
    }

    address queue[jml_maks];
    int front = 0, rear = 0;
    queue[rear++] = 1;

    while (front < Maks_node && front < rear) {
        address current = queue [front++];
        printf("%c --> ", X[current].info);

        address child = X[current].ps_fs;
        while (child != nil && rear < Maks_node) {
            if (rear < Maks_node) {
                queue[rear++] = child;
            }
            child = X[child].ps_nb;
        }
    }
    printf("\n");
}

void PrintTree (Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }

    struct StackNode {
        address node;
        int level;
    } stack[jml_maks];
    
    int top = -1;
    printf ("Ilustrasi Tree : \n");
    printf("======================\n");
    
    stack[++top] = (struct StackNode){1, 0}; 
    
    while (top >= 0) {
        struct StackNode current = stack[top--];
        address node = current.node;
        int level = current.level;
        
        for (int i = 0; i < level; i++) {
            printf(i == level-1 ? "|-- " : "    ");
        }
        
        printf("%c", P[node].info);
        
        if (P[node].ps_pr != nil) {
            printf(" (child of %c)", P[P[node].ps_pr].info);
        } else {
            printf(" (root)");
        }
        printf("\n");
        
        address child = P[node].ps_fs;
        address children[jml_maks];
        int childCount = 0;
        
        while (child != nil) {
            children[childCount++] = child;
            child = P[child].ps_nb;
        }
        
        for (int i = childCount-1; i >= 0; i--) {
            stack[++top] = (struct StackNode){children[i], level+1};
        }
    }


}

/***** Search *****/

boolean Search (Isi_Tree P, infotype X) {
    if (IsEmpty(P)) {
        printf("ttree belum diinisisasi!\n");
        return false;
    }
    int i;
    for (i=0 ; i<jml_maks ; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

/***** Fungsi Lain *****/

int nbElmt (Isi_Tree P) {
    if (IsEmpty(P)) {
        printf ("Tree belum diinisialisasi!\n");
        return -1;
    }
    int i, count = 0;
    for (i = 1; i < jml_maks; i++) {
        if (P[i].info != '\0') {
            count++;
        }
    }
    return count - 1;
}

int nbDaun (Isi_Tree P) {
    if (IsEmpty(P)) {
        printf ("Tree belum diinisialisasi!\n");
        return -1;
    }
    int i, count = 0;   
    for (i = 1; i <jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level (Isi_Tree P, infotype X) {
    if (IsEmpty(P)) {
        printf ("Tree belum diinisiasi!\n");
        return -1;
    }
    int i, current = nil, level = 0;
    for (i = 1; i<jml_maks ; i++) {
        if (P[i].info == X) {
            current = i;
            break;
        }
    }

    if (current == nil) {
        printf("node tidak ditemukan!\n");
        return -1;
    }

    while (P[current].ps_pr != nil) {
        level++;
        current = P[current].ps_pr;
    }
    return level;
}

int Depth (Isi_Tree P) {
    if (IsEmpty(P)) {
        printf ("Tree belum diinisialisasi!\n");
        return 0;
    }
    int i, currenDepth = 0, maxDepth=0;
    address current;
    for (i=1 ; i< jml_maks ; i++) {
        if (P[i].info != '\0') {
            currenDepth = 0;
            current = i;

            while (P[current].ps_pr != nil) {
                currenDepth++;
                current = P[current].ps_pr;
            }

            if (currenDepth > maxDepth) {
                maxDepth = currenDepth;
            }
        }
    }
    return maxDepth;

}

int Max (infotype Data1, infotype Data2) {
    return (Data1>Data2) ? Data1 : Data2;
}