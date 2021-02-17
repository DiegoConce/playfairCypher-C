#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "matrix_utils.h"

void generaMat(char matrice[][5], char *chiave, char *alfa) {
    eliminaSpazi(chiave);
    eliminaRipetizioni(chiave);
    char *newAlpha = calloc(26 + strlen(chiave), sizeof(char));
    strcpy(newAlpha, chiave);
    eliminaRipetizioni(strcat(newAlpha, alfa));
    int z = 0;
    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 5; j++) {
            matrice[k][j] = newAlpha[z];
            z++;
        }
    }

    free(newAlpha);
    newAlpha = NULL;
}

char getCharInMatrix(char mat[][5], int col, int row) {
    return mat[row][col];
}

void seachInMatrix(char mat[][5], char c, int *col, int *row) {
    for (*col = 0; *col < 5; (*col)++) {
        for (*row = 0; *row < 5; (*row)++) {
            if (getCharInMatrix(mat, *col, *row) == c) {
                return;
            }
        }
    }
}

int mod5(int a) {
    if (a < 0)
        return 4;
    else
        return (a % 5);
}

void differentRowCol(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, col[1], row[0]);
    char b = getCharInMatrix(mat, col[0], row[1]);
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}
