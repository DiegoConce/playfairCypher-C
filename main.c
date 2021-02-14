#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "driver.h"


void printInfo() {
    printf("playfair (encode|decode) keyfile <outputdir> file1 ... filen\n");

}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Devi inserire almeno 4 argomenti, ne hai inseriti: %d\n", argc - 1);
        printInfo();
        return -1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        setUpData(argc, argv, true);
        printf("Tutt ok \n");
        return 0;
    }

    if (strcmp(argv[1], "decode") == 0) {
        setUpData(argc, argv, false);
        return 0;
    }

    printf("Comando sconosciuto\n");
    printInfo();
}
