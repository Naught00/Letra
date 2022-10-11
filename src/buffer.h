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

#ifndef BUFFER_H
#define BUFFER_H
#define MAX_CHAR_PER_LINE 255
#include <stdio.h>

extern char buffer[MAX_CHAR_PER_LINE][1000];
extern int total_lines;
void load_buffer(FILE *f);
void clear_buffer(void);
void clear_buffer_line(int line);
void jolt_buffer(char[255][100], int lines_to_append, int l);

#endif
