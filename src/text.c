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
#include "text.h"
#include "buffer.h"

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

void print_buffer(void)
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
            putchar(c);
        } else {
            i++;
            putchar(c);
        }
    }
}
