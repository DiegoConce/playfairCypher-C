#include <string.h>
#include "driver.h"
#include "playfair_encode.h"
#include "playfair_decode.h"
#include "file_manager.h"
#include "matrix_utils.h"
#include "utils.h"
#include "validate.h"

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
    validateMsg(mex);
    if (codifica) {
        return encodeMsg(mat, prepareMsg(mex, mancante, special, alfa));
    } else {
        eliminaSpazi(mex);
        checkDecodeMsg(mex);
        return decodeMsg(mat, mex);
    }
}

