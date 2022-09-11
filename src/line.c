#include<stdio.h>
#include "line.h"

void printall(FILE **f) {
    char buffer[255];
    while (fgets(buffer, 255, *f)) {
        printf("%s", buffer);
    }
}

void printallnum(FILE **f) {
    char buffer[255];
    int i;
    i = 1;

    while (fgets(buffer, 255, *f)) {
        printf("%d\t%s", i, buffer);
        i++;
    }
}
