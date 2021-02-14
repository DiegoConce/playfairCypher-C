#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "driver.h"
#include "utils.h"
#include "playfair.h"

char mat[5][5];

void setUpData(int argc, char **argv, _Bool codifica) {
    char *out = readFiles(argv[2]);
    char delim[] = "\r\n";
    char *alfa = strtok(out, delim);
    char *mancante = strtok(NULL, delim);
    char *special = strtok(NULL, delim);
    char *chiave = strtok(NULL, delim);
    validateKeyfile(alfa, mancante, special, chiave);
    generaMat(mat, chiave, alfa);


    for (int i = 4; i < argc; i++) {
        char *result = elaborateData(readFiles(argv[i]), mancante, special, alfa, codifica);
        saveFile(result, argv[3], argv[i], codifica);
    }

}

char *elaborateData(char *mex, char *mancante, char *special, char *alfa, _Bool codifica) {

    if (codifica) {
        return encodeMsg(mat, prepareMsg(mex, mancante, special, alfa));
    } else {
        eliminaSpazi(mex);
        checkDecodeMsg(mex);
        return decodeMsg(mat, mex);
    }

}


char *createPfPath(char *dirname, char *fname) {
    char *newPath = basename(fname);
    int i = strlen(newPath);
    int j = strlen(strchr(newPath, '.'));
    newPath[i - j] = '\0';
    strcat(newPath, ".pf");
    strcat(dirname, "/");
    strcat(dirname, newPath);
    return dirname;
}

char *createDecPath(char *dirname, char *fname) {
    char *newPath = basename(fname);
    int x = strlen(strchr(newPath, '.'));
    newPath[x + 1] = '\0';
    strcat(newPath, ".dec");
    strcat(dirname, "/");
    strcat(dirname, newPath);
    return dirname;
}

void saveFile(char *mex, char *dirname, char *fname, _Bool codifica) {
    int j = strlen(dirname);
    char *dirpath;

    if (codifica) {
        dirpath = createPfPath(dirname, fname);
    } else {
        dirpath = createDecPath(dirname, fname);
    }

    FILE *fout;
    fout = fopen(dirpath, "w");
    if (fout == NULL) {
        printf("File non salvato correttamente");
        exit(-1);
    }
    fputs(mex, fout);
    fclose(fout);
    dirpath[j] = '\0';
}

char *readFiles(char *fname) {
    long numbytes;
    FILE *fin;
    fin = fopen(fname, "r");
    if (fin == NULL) {
        printf("Impossibile aprire il file: %s", fname);
        exit(-1);
    }

    fseek(fin, 0L, SEEK_END);
    numbytes = ftell(fin);
    fseek(fin, 0L, SEEK_SET);
    char *buffer = calloc(numbytes + 1, sizeof(char));
    if (buffer == NULL) {
        printf("Errore nella lettura del file: %s", fname);
        exit(-1);
    }
    fread(buffer, sizeof(char), numbytes, fin);
    fclose(fin);

    buffer[numbytes] = '\0';

    return buffer;
}


void validateKeyfile(char *alfa, char *mancante, char *special, char *chiave) {

    eliminaRipetizioni(alfa);

    if (chiave == NULL) {
        printf("Keyfile non valido");
        exit(-1);
    }
    if (!(strlen(alfa) == 25 && strlen(mancante) == 1 && strlen(special) == 1)) {
        printf("Keyfile non valido");
        exit(-1);
    }
}