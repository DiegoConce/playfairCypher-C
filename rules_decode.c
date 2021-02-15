#include <string.h>
#include "rules_decode.h"
#include "matrix_utils.h"
#include "playfair_decode.h"

void decodeRules(char mat[][5], int *col, int *row, char *out) {
    if (col[0] == col[1]) {
        sameColDecode(mat, col, row, out);
    } else if (row[0] == row[1]) {
        sameRowDecode(mat, col, row, out);
    } else {
        differentRowCol(mat, col, row, out);
    }
}

void sameColDecode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, col[0], mod5(row[0] - 1));
    char b = getCharInMatrix(mat, col[1], mod5(row[1] - 1));
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}

void sameRowDecode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, mod5(col[0] - 1), row[0]);
    char b = getCharInMatrix(mat, mod5(col[1] - 1), row[1]);
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}



