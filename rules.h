
#ifndef DIEGOCONCETTI104936_RULES_H
#define DIEGOCONCETTI104936_RULES_H

#endif //DIEGOCONCETTI104936_RULES_H

void encodeRules(char mat[][5], int *col, int *row, char *out);

void decodeRules(char mat[][5], int *col, int *row, char *out);

void sameColEncode(char mat[][5], int *col, int *row, char *out);

void sameRowEncode(char mat[][5], int *col, int *row, char *out);

void sameColDecode(char mat[][5], int *col, int *row, char *out);

void sameRowDecode(char mat[][5], int *col, int *row, char *out);

void differentRowCol(char mat[][5], int *col, int *row, char *out);