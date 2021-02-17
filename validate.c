#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#include "validate.h"

void validateKeyfile(char *alfa, char *mancante, char *special, char *chiave) {
    removeDoubles(alfa);
    checkAlpha(alfa);
    check_and_convert_singleChar(mancante);
    check_and_convert_singleChar(special);
    check_key(chiave);
}

void validateMsg(char *str) {
    if (strlen(str) == 0) {
        printf("Il messaggio da cifrare/decifrare deve avere almeno 1 carattere!\n");
        exit(-1);
    }
    upperCase(str);
}

void checkAlpha(char *str) {
    int i = strlen(str);
    if (i != 25) {
        printf("L'alfabete deve essere di 25 caratteri diversi, ne hai inseriti: %d", i);
        exit(-1);
    }
    checkAlphaChars(str);
    upperCase(str);
}

void check_and_convert_singleChar(char *str) {
    if (strlen(str) != 1) {
        printf("%s deve essere soltanto 1 carattere!", str);
        exit(-1);
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
            printf("Carattere non valido (%c) nell'alfabeto alla posizione %d!\n", str[i], i);
            exit(-1);
        }
    }
}

int char_index(char c) {
    return toupper(c) - 'A';
}

void check_key(char *str) {
    if (str == NULL) {
        printf("Almeno un carattere richiesto per la chiave!\n"
               "Keyfile non valido\n");
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
