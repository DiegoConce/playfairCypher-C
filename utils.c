#include <string.h>
#include <stdlib.h>
#include "utils.h"

char *prepareMsg(char *mex, char *mancante, char *speciale, char *alfa) {
    eliminaSpazi(mex);
    checkMancante(alfa, mex, mancante);
    return checkSpeciale(mex, speciale);
}

void eliminaRipetizioni(char *string) {
    int n = strlen(string);
    int k;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; string[j] != '\0'; j++) {
            if (string[j] == string[i]) {
                for (k = j; string[k] != '\0'; k++) {
                    string[k] = string[k + 1];
                }
            }
        }
    }
}

void eliminaSpazi(char *string) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') {
            string[count++] = string[i];
        }
    }
    string[count] = '\0';
}



void checkMancante(char *alfa, char *mex, char *mancante) {
    int n = strlen(mex);
    for (int i = 0; i < n; i++) {
        if (strchr(alfa, mex[i]) == NULL) {
            mex[i] = *mancante;
        }
    }
}

int contaDoppie(char *string) {
    int n = strlen(string);
    int count = 0;
    for (int i = 1; i < n; i += 2) {
        if (string[i] == string[i - 1]) {
            count++;
        }
    }
    return count;
}

char *checkSpeciale(char *mex, char *speciale) {
    int n = strlen(mex);
    int resultLen = n + contaDoppie(mex) + 2;
    char *out = calloc(resultLen, sizeof(char));

    if (contaDoppie(mex) == 0 && (n % 2) != 0) {
        strcpy(out, mex);
        strncat(out, speciale, 1);
        return out;
    }

    for (int i = 1; i < n + 1; i += 2) {
        if (mex[i] == mex[i - 1]) {
            strncat(out, &mex[i - 1], 1);
            strncat(out, speciale, 1);
            strncat(out, &mex[i], 1);
        } else {
            strncat(out, &mex[i - 1], 1);
            strncat(out, &mex[i], 1);
        }
    }

    if (strlen(out) % 2 != 0) {
        strcat(out, speciale);
    }
    return out;
}



