
#ifndef DIEGOCONCETTI104936_MATRIX_UTILS_H
#define DIEGOCONCETTI104936_MATRIX_UTILS_H

#endif //DIEGOCONCETTI104936_MATRIX_UTILS_H

void generaMat(char matrice[][5], char *chiave, char *alfa);

char getCharInMatrix(char mat[][5], int col, int row);

void seachInMatrix(char mat[][5], char c, int *col, int *row);

int mod5(int a);

void differentRowCol(char mat[][5], int *col, int *row, char *out);