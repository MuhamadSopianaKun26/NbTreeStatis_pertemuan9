#include "menu.h"

void lobby (Isi_Tree P, int maks_node) {
    clearScreen();
    int opsi;
    boolean endProgram = false;
    
    while (endProgram == false) {
        clearScreen();
        puts("=======================================");
        puts("=   PROGRAM NON BINARY TREE ARRAY     =");
        puts("=======================================");
        printf("\n");
        PrintTree(P);
        printf("\n=======================================\n");
        puts("1. Traversal PreOrder");
        puts("2. Traversal InOrder");
        puts("3. Traversal PostOrder");
        puts("4. Traversal LevelOrder");
        puts("5. Print Tree");
        puts("6. SearchNode Tree");
        puts("7. Jumlah Daunn/leaf");
        puts("8. Mencari level node tree");
        puts("9. Kedalaman tree");
        puts("10. Membandingkan 2 node Tree");
        puts("0. Exit");

        printf("\nPilih Menu : ");
        scanf("%d", &opsi);

        switch(opsi) {
            case 1 :
                clearScreen();
                printf ("Urutan tree berdasarkan Traversal PreOrder {pr, fs, nb} :\n");
                PreOrder(P);
                getchar();
                break;
            case 2 :
                clearScreen();
                printf ("Urutan tree berdasarkan Traversal InOrder {fs, pr, other child} :\n");
                InOrder(P);
                getchar();
                break;
            case 3 :
                clearScreen();
                printf ("Urutan tree berdasarkan Traversal PostOrder {fs, nb, pr} :\n");
                PostOrder(P);
                getchar();
                break;
            case 4 :
                clearScreen();
                printf ("Urutan tree berdasarkan Traversal PreOrder {level by level} :\n");
                Level_order(P,maks_node);
                getchar();
                break;
            case 5 :
                clearScreen();
                printf ("Isi Tree : \n");
                printAllTree(P);
                getchar();
                break;
            case 6 :
                clearScreen();
                infotype info;
                boolean hasil;
                printf("Masukan info dari node yang dicari : ");
                scanf(" %c", &info);
                hasil = Search(P, info);
                printf("\n");

                if (hasil == false) {
                    printf("Node yang dicari tidak ditemukan!\n");
                } else {
                    printf("Node yang dicari ditemukan : \n");
                    int i;
                    for (i=1;i<=jml_maks;i++) {
                        if (P[i].info == info) {
                            printf ("--> Indeks ke-%d : \n", i);
                            puts("--------------------------------");
                            printf("info\t\t: %c\n", P[i].info);
                            printf("first son\t: %d\n", P[i].ps_fs);
                            printf("next brother\t: %d\n", P[i].ps_nb);
                            printf("parent\t\t: %d\n", P[i].ps_pr);
                            puts("--------------------------------");
                            printf("\n");
                        }
                    }                
                }
                getchar();
                break;
            case 7 :
                clearScreen();
                int i, jumlah = nbDaun(P);
                printf("Jumlah daun dari Tree : %d\n", jumlah);
                printf("--> ");
                for (i=1;i<=jml_maks;i++) {
                    if(P[i].info != '\0' && P[i].ps_fs == nil) {
                        printf("%c ", P[i].info);
                    }
                }

                getchar();
                break;
            case 8 :
                clearScreen();
                infotype input;
                printf("Masukan info node yang dicari :");
                scanf(" %c", &input);
                printf("\n");
                if (Search(P, input) == false) {
                    printf("Node yang dicari tidak ditemukna!\n");
                } else {
                    printf("Node %c ada di level : %d\n", input, Level(P, input));
                }
                getchar();
                break;
            case 9 :
                clearScreen();
                printf("Kedalaman (depth) dari tree yaitu : %d", Depth(P));
                getchar();
                break;
            case 10 :
                clearScreen();
                boolean valid = false;
                infotype data1,data2;
                while (valid == false) {
                    printf("Masukan node ke-1 yang dicari : ");
                    scanf (" %c", &data1);
                    if (Search(P,data1) == false) {
                        printf("\nnode tidak ditemukan!\n...\n");
                    } else {
                        valid = true;
                    }
                }
                valid = false;
                while (valid == false) {
                    printf("Masukan node ke-2 yang dicari : ");
                    scanf (" %c", &data2);
                    if (Search(P,data2) == false) {
                        printf("\nnode tidak ditemukan!\n...\n");
                    } else {
                        valid = true;
                    }
                }
                printf("\nNilai yang lebih besar : %c", Max(data1,data2));
                getchar();
                break;
            case 0 :
                endProgram = true;
                break;
        }
        getchar();
    }
    printf("\n--Program sudah berakhir!--");
};

void printAllTree (Isi_Tree P) {
    clearScreen();

    printf("Seluruh Node pada Non Binary Tree;\n");
    int i;
    for (i=1;i<jml_maks;i++) {
        if (P[i].info != '\0') {
            printf ("--> Indeks ke-%d : \n", i);
            puts("--------------------------------");
            printf("info array ke %d\t\t: %c\n", i, P[i].info);
            printf("first son array ke %d\t: %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d\t: %d\n", i, P[i].ps_nb);
            printf("parent array ke %d\t: %d\n", i, P[i].ps_pr);
            puts("--------------------------------");
            printf("\n");
        }
    }
}

void clearScreen () {
    system("cls");
}