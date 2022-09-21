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
#include "buffer.h"

char buffer[MAX_CHAR_PER_LINE][1000];
int total_lines;

/* Takes file and loads into buffer 
 * Buffer is a global variable since 
 * every part of the program needs access */
void load_buffer(FILE *f)
{

    int ch;
    char c;

    for (ch = 1, total_lines = 1; c != EOF;) {
        printf("%c, %d, %d\n", c , ch, total_lines);
        c = buffer[ch][total_lines] = getc(f);

        if (c == '\n') {
            total_lines++;
            ch = 1;
        } else {
            ch++;
        }
    }
    
    /* EOF gets counted as one line 
     * This should fix that */
    total_lines--;
    printf("%d\n", total_lines);

    /* Rewind the file on disk for later
     * This ensures that the disk head is at
     * the start of the file for future reads
     * from the file */
    rewind(f);

}

void clear_buffer(void)
{
    memset(buffer, 0, sizeof(buffer[MAX_CHAR_PER_LINE][1000]) * MAX_CHAR_PER_LINE * 1000);
}

void clear_buffer_line(int line)
{
    memset(buffer[line], 0, sizeof(buffer[line]));

    int i;
    for (i = 1; i <= MAX_CHAR_PER_LINE; i++)
        memset(buffer, 0, sizeof(buffer[i][line]));

    buffer[1][line] = '\n';

}

