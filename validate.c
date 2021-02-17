#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#import "validate.h"

void validateKeyfile(char *alfa, char *mancante, char *special, char *chiave) {
    eliminaRipetizioni(alfa);
    checkAlpha(alfa);
    check_and_convert_singleChar(mancante);
    check_and_convert_singleChar(special);
    checkKey(chiave);
}

void validateMsg(char *str) {
    if (strlen(str) == 0) {
        printf("At least 1 char for message is required!\n"
               "Unable to read the message to encode/decode\n");
        exit(-1);
    }
    upperCase(str);
}

void checkAlpha(char *str) {
    int i = strlen(str);
    if (i != 25) {
        printf("Illegal number of elements in the alphabet! Expected 25 are %d", i);
        exit(-1);
    }
    checkAlphaChars(str);
    upperCase(str);
}

void check_and_convert_singleChar(char *str) {
    if (strlen(str) != 1) {
        printf("%s must be a single char!", str);
        exit(-1);
        //return -1
    }
    upperCase(str);
}

void upperCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
}


void checkAlphaChars(char *str) {
    for (int i = 0; i < 25; i++) {
        if ((char_index(str[i]) < 0) || (char_index(str[i]) > 25)) {
            printf("Illegal char (%c) in the alphabet at position %d!\n", str[i], i);
            exit(-1);
        }
    }
}

int char_index(char c) {
    return toupper(c) - 'A';
}

void checkKey(char *str) {
    if (str == NULL) {
        printf("At least 1 char for key is required!\n"
               "keyfile not valid\n");
        exit(-1);
    }
    upperCase(str);
}

void checkDecodeMsg(char *str) {
    if (strlen(str) % 2 != 0) {
        printf("Messaggio impossibile da decifrare\n");
        exit(-1);
    }
}
