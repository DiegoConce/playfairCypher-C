#ifndef DIEGOCONCETTI104936_DRIVER_H
#define DIEGOCONCETTI104936_DRIVER_H

#endif //DIEGOCONCETTI104936_DRIVER_H


void setUpData(int argc, char **argv, _Bool codifica);

char *elaborateData(char *mex, char *mancante, char *special, char *alfa, _Bool codifica);

char *createPfPath(char *dirname, char *fname);

char *createDecPath(char *dirname, char *fname);

void saveFile(char *mex, char *dirname, char *fname, _Bool codifica);

char *readFiles(char *fname);

void validateKeyfile(char *alfa, char *mancante, char *special, char *chiave);