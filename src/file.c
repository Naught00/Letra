#include<stdio.h>
#include "file.h"
#include "buffer.h"

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

void print_buffer_with_numbers(void)
{
    int i, x;
    char c;

    if (total_lines == 0) {
        printf("?\n");
        return;
    }

    printf("1\t");
    for (i = 1, x = 1; x <= total_lines;) {
        c = buffer[i][x];
        if (c == '\n') {
            x++;
            i = 1;
            putchar(c);
            if (x <= total_lines)
                printf("%d\t", x);
        } else {
            i++;
            putchar(c);
        }
    }
}
