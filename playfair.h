#ifndef DIEGOCONCETTI104936_NEWFAIR_H
#define DIEGOCONCETTI104936_NEWFAIR_H

#endif //DIEGOCONCETTI104936_NEWFAIR_H

int mod5(int a);

char getCharInMatrix(char mat[][5], int col, int row);

void seachInMatrix(char mat[][5], char c, int *col, int *row);

void encodePair(char mat[][5], char first, char second, char *out);

void decodePair(char mat[][5], char first, char second, char *out);

char *encodeMsg(char mat[][5], char *mex);

char *decodeMsg(char mat[][5], char *mex);
