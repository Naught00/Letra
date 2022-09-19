#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>

extern char buffer[255][1000];
extern int total_lines;
void load_buffer(FILE *f);
void print_buffer(void);

#endif
