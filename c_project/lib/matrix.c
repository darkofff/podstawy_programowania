#include <stdio.h>
#include <stdlib.h>

struct Matrix{  
    int r;
    int c;
    double **data;
};
struct Matrix createMatrix(int r, int c);
void deleteMatrix(struct Matrix *m);
struct Matrix readMatrix(int r, int c);
void printMatrix(struct Matrix m);
struct Matrix sum(struct Matrix m1, struct Matrix m2);
struct Matrix difference(struct Matrix m1, struct Matrix m2);
struct Matrix product(struct Matrix m1, struct Matrix m2); 

struct Matrix createMatrix(int r, int c){

    struct Matrix matrix;
    matrix.r = r;
    matrix.c = c;
    matrix.data = (double**)malloc(r * sizeof(double*));
    if(matrix.data == NULL) exit(0);

    for(int i=0; i<r; i++){
        matrix.data[i]=(double*)malloc(c * sizeof(double));
        if(matrix.data[i] == NULL) exit(0);
    }

    return matrix;
}
   
void deleteMatrix(struct Matrix *m){
    int rows = m->r;

    if(m->data!=NULL){
        for(int i = 0; i< rows; i++){
            free(m->data[i]);
        }
    }

    free(m->data);

    // Ponoć dobra praktyka. Chodzi o to, że nawet jak wkaźnik jest użyty to żeby nic nie zdziałał.
    m->data = NULL;
}

struct Matrix readMatrix(int r, int c){
    printf("\n");
    struct Matrix matrix = createMatrix(r,c);

    for(int i = 0; i<r; i++){
            printf("--- Wiersz %d ---\n",i+1);
        for(int j = 0; j<c; j++){
            printf("    Podaj %d element: ", j+1);
            scanf("%lf", &matrix.data[i][j]);
            printf("\n");
        }
    }

    return matrix;
}

void printMatrix(struct Matrix m){
    double cols = m.c;
    double rows = m.r;

    if(m.data != NULL){
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                printf("%8.2f", m.data[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("Nie udalo sie wyswietlic macierzy.");
    }
    printf("\n");
}

struct Matrix sum(struct Matrix m1, struct Matrix m2){
        
    int c1 = m1.c;
    int r1 = m1.r;
    int c2 = m2.c;
    int r2 = m2.r;

   // 1.Zadeklarować nową macierz 
    struct Matrix matrix = createMatrix(r1, c1);

    // 2. sprawdzić czy mają takie same wymiary, tzn. r1==r2 i c1==c2
    if(c1!=c2 || r1!=r2){
        printf("Nie mozna dodac macierzy. Powod: rozne wymiary.\n");
        matrix.data = NULL;
        return matrix;
    }

    // 3. Jeśli tak do dodać odpowiadający wyrazy
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            matrix.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    } 
    
    return matrix;
}

struct Matrix difference(struct Matrix m1, struct Matrix m2){
    int c1 = m1.c;
    int r1 = m1.r;
    int c2 = m2.c;
    int r2 = m2.r;

    // 1.Zadeklarować nową macierz 
    struct Matrix matrix = createMatrix(r1, c1);

    // 2. sprawdzić czy mają takie same wymiary, tzn. r1==r2 i c1==c2
    if(c1!=c2 || r1!=r2){
        printf("Nie mozna odjac macierzy. Powod: rozne wymiary.\n");
        matrix.data = NULL;
        return matrix;
    }

    // 3. Jeśli tak do dodać odpowiadający wyrazy
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            matrix.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    } 
    
    return matrix;
}
struct Matrix product(struct Matrix m1, struct Matrix m2){
    int r1 = m1.r;
    int c1 = m1.c;
    int r2 = m2.r;
    int c2 = m2.c;

    // 1.Zadeklarować nową macierz 
    struct Matrix matrix = createMatrix(r1, c2);

    // 2. sprawdzić czy liczba kolumn pierwszej macierzy jest równa liczbie wierszy drugiej macierzy
    if(c1 != r2){
        printf("Nie mozna pomnozyc macierzy. Powod: liczba kolumn pierwszej macierzy nie zgadza sie z liczba wierszy drugiej macierzy.\n");
        matrix.data = NULL;
        return matrix;
    }

    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
        int temp_sum = 0;
            for (int k = 0; k < r2; k++) {
                temp_sum += m1.data[i][k] * m2.data[k][j];
            }
        
        matrix.data[i][j] = temp_sum;
        }
    }
    return matrix;
}





