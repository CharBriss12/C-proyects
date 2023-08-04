#include <stdio.h>
#include <malloc.h>
#include <math.h>

void input_matrix(int n, int m, int matrix[n][m]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void output_matrix(int n, int m, int matrix[n][m]){
    for (int i = 0; i < n; ++i) {
        printf("|");
        for (int j = 0; j < m; ++j) {
            printf("%d", matrix[i][j]);

            if (j-(m-1) < 0){
                printf(" ");
            }
        }

        printf("|");
        printf("\n");
    }
}

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_matrix(int matrix[2][2]){
    swap(&matrix[0][0], &matrix[0][1]);
    swap(&matrix[1][0], &matrix[1][1]);
}


void decimal_binary(int decimal){
    int binary[8] = {0};
    int i = 0;

    while (decimal != 0) {
        decimal % 2;
        binary[i] = decimal % 2;
        decimal /= 2;

        i++;
    }

    for (int j = 7; j >= 0; --j) {
        printf("%d", binary[j]);
    }
}

void decimal_binary_1(int decimal) {
    int size = 8;
    int* binary = (int*)malloc(size * sizeof(int));

    for (int i = size-1; i >= 0; i--) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }

    for (int i = 0; i < size; i++) {
        printf("%d", binary[i]);
    }
    free(binary);
}

void matrix_multiplication(int n, double matrix_1[][n], double matrix_2[][n], double matrix_3[][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                matrix_3[i][j] = matrix_3[i][j] + matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
}

#define ROWS 3
#define COLUMNS 3

int main(){
    /*
    int matrix_1[ROWS][COLUMNS] = {{4, 3},
                                   {2, 1}};


    int matrix_1[ROWS][COLUMNS] = {{3, 2, 1},
                                   {3, 4, 1},
                                   {4, 5, 1}};
    */
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix_1[n][m];

    input_matrix(n, m, matrix_1);

    output_matrix(n, m, matrix_1);

    /*
    int matrix_1[ROWS][COLUMNS] = {{1, 2, 0},
                                   {3, 4, 0},
                                   {4, 5, 0}};
    int matrix_2[ROWS][COLUMNS] = {{1, 2, 6},
                                   {3, 4, 7},
                                   {0, 0, 0}};

    double angle = 45;
    double matrix_2[ROWS][COLUMNS] = {{cos(angle), -1.0 * sin(angle)},
                                      {sin(angle), cos(angle)}};
    double matrix_3[ROWS][COLUMNS] = {0};

    matrix_multiplication(ROWS, matrix_1, matrix_2, matrix_3);

    output_matrix(ROWS, COLUMNS, matrix_3);
     */

    return 0;
}