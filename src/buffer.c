#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "buffer.h"

char buffer[255][1000];
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
    total_lines = total_lines - 1;
    printf("%d\n", total_lines);

}

void print_buffer()
{
    int i, x;
    char c;
    printf("%d\n", total_lines);

    for (i = 1, x = 1; x < total_lines;) {
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
