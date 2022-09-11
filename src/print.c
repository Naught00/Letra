#include<stdio.h>
#include "print.h"

void printall(char buffer[], FILE *f) {
    int i;
    i = 1;
    while (fgets(buffer, 255, f)) {
        printf("%d\t%s", i, buffer);
        i++;
    }
}
