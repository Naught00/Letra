#ifndef BUFFER_H
#define BUFFER_H
#define MAX_CHAR_PER_LINE 255
#include <stdio.h>

extern char buffer[MAX_CHAR_PER_LINE][1000];
extern int total_lines;
void load_buffer(FILE *f);
void clear_buffer(void);
void clear_buffer_line(int line);

#endif
