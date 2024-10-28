#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mn x np

int main(){
  printf("\n");
  srand(time(0));

  printf("--- KALKULATOR MACIERZY A x B ---\n");

  int n, m, l;
  printf("Podaj liczbe wierszy macierzy A: ");
  scanf("%d", &n);
  printf("Podaj liczbe kolumn macierzy A i wierszy B: ");
  scanf("%d", &m);
  printf("Podaj liczbe kolumn macierzy B: ");
  scanf("%d", &l);
  

  int **A = (int **)malloc(n * sizeof(int *));
  if (A == NULL) return 1;
  for (int i = 0; i < n; i++) A[i] = (int *)malloc(m * sizeof(int));
  
  int **B = (int **)malloc(m * sizeof(int *));
  if (B == NULL) return 1;
  for (int i = 0; i < m; i++) B[i] = (int *)malloc(l * sizeof(int));
  
  int **sum_matrix = (int **)malloc(n * sizeof(int *));
  if (sum_matrix == NULL) return 1;
  for (int i = 0; i < n; i++) sum_matrix[i] = (int *)malloc(l * sizeof(int));

  printf("\n--- Macierz A ---\n");
  // Generuj losowe liczby dla macierzy A
  for (int i = 0 ; i < n; i++){
    for (int j = 0 ; j < m; j++){
      A[i][j] = (rand() % (201)) + (-100);
      printf("%6d ", A[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("--- Macierz B ---\n");
  // Generuj losowe liczby dla macierzy B
  for (int i = 0 ; i < m; i++){
    for (int j = 0 ; j < l; j++){
      B[i][j] = (rand() % (201)) + (-100);
      printf("%6d ", B[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < l; j++){
      int temp_sum = 0;
      for (int k = 0; k < m; k++)
      {
        temp_sum += A[i][k] * B[k][j];
      }
      // printf("%d ", temp_sum);
      sum_matrix[i][j] = temp_sum;
    }
  }

  printf("\n--- ILOCZYN MACIERZY A x B ---\n");
  for (int i = 0; i < n; i++){
    for (int j = 0; j < l; j++){
      printf("%7d ", sum_matrix[i][j]);
    }
    printf("\n");
  }

  FILE *file_write;
  if(file_write==NULL) return 1;

  file_write = fopen("dane.dat", "w");
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < l; j++){
      int temp = sum_matrix[i][j];
      if(j+1==l){
        fprintf(file_write, "%7d\n",temp);
      }else{
        fprintf(file_write, "%7d",temp);
      }
    }
  }

  fclose(file_write);

  free(A);
  free(B);
  free(sum_matrix);

  printf("\n\n");
  return 0;
}
