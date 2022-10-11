#include<stdio.h>
#include<readline/readline.h>
#include "append.h"
#include "buffer.h"
#include "file.h"

void append_bottom(void)
{
    char * in;
    int lines_to_append = 1;
    int i, ch;
    int done = 0;

    while (!done) {
        char *in = readline("");

        if (in[0] != '.') {
            for (ch = 1, i = 0;; i++) {
                if (in[i] == '\0') {
                    int lines = total_lines + lines_to_append;
#ifdef DEBUG
                    printf("lines %d\n", lines);
#endif
                    buffer[ch][(total_lines+lines_to_append)] = '\n';
                    break;
                } else if (in[i] != '\0')
                    buffer[ch][(total_lines+lines_to_append)] = in[i];
                    ch++;
            }
        }
        
        if (in[0] != '.') {
            lines_to_append++;
        } else {
            /* You are left with an extra line in lines_to_append
             * due to the above if statement evaluating to true
             * on the first input. lines_to_append is prefixed
             * with -- to subtract before being evaluated */
            total_lines = total_lines + --lines_to_append;
            done = 1;
        }
    }
    return;
}

void append_line(int l)
{
    char * in;
#ifdef DEBUG
    printf("%d\n", l);
#endif
    int lines_to_append = 1;
    int i, ch;
    int done = 0;
    /* A new buffer is made so I can figure how
     * many lines the user wants to append before
     * I jolt it.
     */
    char buffer_to_append[255][100];

    while (!done) {
        char *in = readline("");

        if (in[0] != '.') {
            for (ch = 1, i = l;; i++) {
                if (in[i] == '\0') {
                    int lines = l + lines_to_append;
#ifdef DEBUG
                    printf("lines %d\n", lines);
#endif
                    buffer_to_append[ch][(l + lines_to_append)] = '\n';
                    break;
                } else if (in[i] != '\0')
                    buffer_to_append[ch][(l + lines_to_append)] = in[i];
                    ch++;
            }
        }
        
        if (in[0] != '.') {
            lines_to_append++;
        } else {
            /* You are left with an extra line in lines_to_append
             * due to the above if statement evaluating to true
             * on the first input. lines_to_append is prefixed
             * with -- to subtract before being evaluated */
            total_lines = total_lines + --lines_to_append;
            done = 1;
        }
    }

    jolt_buffer(buffer_to_append, lines_to_append, l);
    return;
}
