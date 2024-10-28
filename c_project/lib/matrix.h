#ifndef MATRIX_H // ifndef => if not defined. To ma zapobiec dodawaniu tego pliku kilkukrotnie
#define MATRIX_H

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


#endif 