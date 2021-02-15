#include <string.h>
#include <stdlib.h>
#include "rules_decode.h"
#include "matrix_utils.h"

void decodePair(char mat[][5], char first, char second, char *out) {
    int col[2] = {0, 0};
    int row[2] = {0, 0};

    seachInMatrix(mat, first, &col[0], &row[0]);
    seachInMatrix(mat, second, &col[1], &row[1]);
    decodeRules(mat, col, row, out);

}

char *decodeMsg(char mat[][5], char *mex) {
    int n = strlen(mex);
    char *out = calloc(n + n / 2, sizeof(char));
    for (int i = 0; i < n; i += 2) {
        decodePair(mat, mex[i], mex[i + 1], out);
    }
    return out;
}