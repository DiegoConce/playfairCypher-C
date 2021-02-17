#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdio.h>
#include "file_manager.h"

char *createPfPath(char *dirname, char *fname) {
    char *name = calloc(strlen(dirname) + strlen(basename(fname)) + 4, sizeof(char));
    strcpy(name, dirname);
    strcat(name, "/");
    strcat(name, basename(fname));
    removeExtension(name);
    strcat(name, ".pf");
    return name;
}

char *createDecPath(char *dirname, char *fname) {
    char *name = calloc(strlen(dirname) + strlen(basename(fname)) + 4, sizeof(char));
    strcpy(name, dirname);
    strcat(name, "/");
    strcat(name, basename(fname));
    removeExtension(name);
    strcat(name, ".dec");
    return name;
}

void removeExtension(char *name) {
    char *end = name + strlen(name);
    while (end > name && *end != '.' && *end!= '\\' && *end != '/') {
        --end;
    }
    if ((end > name && *end == '.') && (*(end - 1) != '\\' && *(end - 1) != '/')) {
        *end = '\0';
    }
}

void saveFile(char *mex, char *dirname, char *fname, _Bool codifica) {
    char *dirpath;
    if (codifica) {
        dirpath = createPfPath(dirname, fname);
    } else {
        dirpath = createDecPath(dirname, fname);
    }

    FILE *fout;
    fout = fopen(dirpath, "w");
    if (fout == NULL) {
        printf("File non salvato correttamente\n");
        exit(-1);
    }
    fputs(mex, fout);
    fclose(fout);
}


char *readFiles(char *fname) {
    long numbytes;
    FILE *fin;
    fin = fopen(fname, "r");
    if (fin == NULL) {
        printf("Impossibile aprire il file: %s\n", fname);
        exit(-1);
    }

    fseek(fin, 0L, SEEK_END);
    numbytes = ftell(fin);
    fseek(fin, 0L, SEEK_SET);
    char *buffer = calloc(numbytes + 1, sizeof(char));
    if (buffer == NULL) {
        printf("Errore nella lettura del file: %s\n", fname);
        exit(-1);
    }
    fread(buffer, sizeof(char), numbytes, fin);
    fclose(fin);

    buffer[numbytes] = '\0';

    return buffer;
}
