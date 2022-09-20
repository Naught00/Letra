#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void write_buffer_to_file(FILE *f)
{
    int ch;
    char c;
    int lines;

    for (ch = 1, lines = 1; lines <= total_lines;) {
        printf("%c, %d, %d\n", c , ch, total_lines);
        c = buffer[ch][total_lines];
        putc(c, f);

        if (c == '\n') {
            lines++;
            ch = 1;
        } else {
            ch++;
        }
    }
    fclose(f);
}
