#include <string.h>
#include "rules_encode.h"
#include "matrix_utils.h"

void encodeRules(char mat[][5], int *col, int *row, char *out) {
    if (col[0] == col[1]) {
        sameColEncode(mat, col, row, out);
    } else if (row[0] == row[1]) {
        sameRowEncode(mat, col, row, out);
    } else {
        differentRowCol(mat, col, row, out);
    }
}

void sameColEncode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, col[0], mod5(row[0] + 1));
    char b = getCharInMatrix(mat, col[1], mod5(row[1] + 1));
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}

void sameRowEncode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, mod5(col[0] + 1), row[0]);
    char b = getCharInMatrix(mat, mod5(col[1] + 1), row[1]);
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}


