#include<stdio.h>
#include "file.h"

void printallfile(FILE *f) {
    char filebuffer[255];
    while (fgets(filebuffer, 255, f)) {
        printf("%s", filebuffer);
    }
}

void printfilenum(FILE *f) {
    char file_buffer[255];
    int i;
    i = 1;

    while (fgets(file_buffer, 255, f)) {
        printf("%d\t%s", i, file_buffer);
        i++;
    }
}

