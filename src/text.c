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
