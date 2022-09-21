/* 
 * Copyright 2022 Mark Naughton 
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the European Union Public Licence v1.2 as published by the
 * European Commission.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the European Union Public Licence for more
 * details.
 *
 * You should have received a copy of the European Union Public Licence along
 * with this program. If not, see <https://opensource.org/licenses/EUPL-1.2>.
 */

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
    int i, x;
    char c;
    printf("%d\n", total_lines);
    if (total_lines == 0)
        printf("?\n");

    for (i = 1, x = 1; x <= total_lines;) {
        c = buffer[i][x];
        if (c == '\n') {
            x++;
            i = 1;
            putc(c, f);
        } else {
            i++;
            putc(c, f);
        }
    }
    rewind(f);
}
