#include "ADT_nbt_statis.h"
#include "menu.h"
#include <stdlib.h>

int main() {
    system("cls");
    Isi_Tree X;
    int maks_node_X = 8;
    
    printf("Membuat tree dengan %d node:\n", maks_node_X);
    Create_tree(X, maks_node_X);
    
    lobby (X, maks_node_X);
    
    return 0;
}