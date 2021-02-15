#ifndef DIEGOCONCETTI104936_FILEPATH_UTILS_H
#define DIEGOCONCETTI104936_FILEPATH_UTILS_H

#endif //DIEGOCONCETTI104936_FILEPATH_UTILS_H

char *createPfPath(char *dirname, char *fname);

char *createDecPath(char *dirname, char *fname);

void removeExtension(char *name);

void saveFile(char *mex, char *dirname, char *fname, _Bool codifica);

char *readFiles(char *fname);