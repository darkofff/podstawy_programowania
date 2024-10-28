/* 
    jakby "make" nie działało na linuxie to spróbować mingw32-make albo mingw32-make.exe
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

int userInputMenu();
int userInputDimensions();

int main(){

    int loop = 1;

    while(loop){
        int opcja = 0;
        int Ar, Ac, Br, Bc; // liczba wierszy macierzy A, liczba kolumn macierzy A, liczba wierszy macierzy B, liczba kolumn macierzy B,

        printf("--- KALKULATOR MACIERZY ---\n");
        printf("1. Dodawanie macierzy\n");
        printf("2. Odejmowanie macierzy\n");
        printf("3. Mnozenie macierzy\n");
        printf("4. Zakoncz program\n");
        printf("--- --- ---\n");
        printf("Wybierz operacje: ");
        
        opcja = userInputMenu();
        if(opcja==4) break;

        printf("\nPodaj liczbe wierszy macierzy A: ");
        Ar = userInputDimensions();
        printf("\nPodaj liczbe kolumn macierzy A: ");
        Ac = userInputDimensions();
        printf("\nPodaj liczbe wierszy macierzy B: ");
        Br = userInputDimensions();
        printf("\nPodaj liczbe kolumn macierzy B: ");
        Bc = userInputDimensions();

        printf("--- WPROWADZ MACIERZ A ---\n");
        struct Matrix A = readMatrix(Ar, Ac);
        printf("--- WPROWADZ MACIERZ B ---\n");
        struct Matrix B = readMatrix(Br, Bc);


        printf("--- MACIERZ A ---\n");
        printMatrix(A);
        printf("--- MACIERZ B ---\n");
        printMatrix(B);

        struct Matrix C; 

        switch(opcja){
            case 1:
                C = sum(A,B);
                break;
            case 2:
                C = difference(A,B);
                break;
            case 3:
                C = product(A,B);
                break;
            case 4:
                printf("\nEXIT\n");
                loop = 0;
                break;
            default:
                printf("Wybierz poprawna opcje!!!");
        }

        printf("--- MACIERZ C ---\n");
        printMatrix(C);

        deleteMatrix(&A);
        deleteMatrix(&B);
        deleteMatrix(&C);

    }
    
    return 0;
}

int userInputMenu(){
    int x = 0;
    bool loop = true;
    bool isFirstLoop = true;

    while (loop){
        
        if(!isFirstLoop){
            printf("\nNieprawidlowe dane wejsciowe. Sprobuj ponownie.\n");
        }

        int valid = scanf("%d", &x);

        if(valid == 1 && x>= 1 && x<=4){
            loop = false;
        }
        
        if(!valid){
            // Czyści buffer jeśli został wprowadzony typ nie zgadzający się z typem podanym w scanf
            while (getchar() != '\n');
        }

        isFirstLoop = false;
    }

    return x;
}
int userInputDimensions(){
    int x = 0;
    bool loop = true;
    bool isFirstLoop = true;

    while (loop){
        if(!isFirstLoop){
            printf("\nNieprawidlowe dane wejsciowe. Sprobuj ponownie.\n");
        }

        int valid = scanf("%d", &x);

        if(valid == 1){
            loop = false;
        }else{
            // Czyści buffer jeśli został wprowadzony typ nie zgadzający się z typem podanym w scanf
            while (getchar() != '\n');
        }
        isFirstLoop = false;
    }
    return x;
}