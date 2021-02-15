#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driver.h"
#include "utils.h"
#include "playfair.h"
#include "file_manager.h"

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