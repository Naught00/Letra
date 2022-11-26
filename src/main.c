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

#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include "append.h"
#include "buffer.h"
#include "text.h"
#include "file.h"
#define MAX_FILE_NAME 100

int main(int argc, char* argv[]) {
    FILE *f = NULL;
    char mode[] = "r+";
#ifdef DEBUG
    printf("DEBUG MODE\n");
#endif
    char command_buffer[10];

    if (argc == 2) {
        f = fopen(argv[1], mode);
        load_buffer(f);
    } 

    char *input;
    int done = 0;

    while (!done) {
        input = readline("> ");
        
        /* Clear input before each command. */

#ifdef DEBUG
        int fg;
        for (fg = 0; fg < (1 + strlen(input)); fg++)
            printf("%d\n", input[fg]);
#endif
        
        /* Note: This switch statement relies on 'dropoff' between cases */
        switch (input[0]) {
            case 'p' :
                {
                    if (input[1] == '\0') {
                        print_buffer();
                        break;
                    } else if (input[1] == 'h') {
                        print_buffer_highlight();
                        break;
                    }
                }

            case 'n' :
                {
                    if (input[1] == '\0') {
                        print_buffer_with_numbers();
                        break;
                    }
                }
                
            case 'e' :
                {
                    if (input[0] == 'e' && input[1] == ' ') {
                        char file_name[MAX_FILE_NAME];
                        int len = strlen(input);
                        int ans = len - 2;

                        int i = 0;
                        for (i = 0; i <= ans; i++) {
                            file_name[i] = input[i+2];
                            if (i == (ans)) {
                                file_name[i] = '\0';
                            }
                        }
                        clear_buffer();
			*file_name = *trim(file_name);

			#ifdef DEBUG
			printf("name: %s\n", file_name);
			for (i = 0; i < strlen(file_name); i++) {
				printf("%c\n", file_name[i]);
			}
			#endif

                        f = fopen(file_name, mode);
                        load_buffer(f);
                        break;
                    } 
                }

            case 'm' :
                {
                    if (input[1] == '4') {
                        fseek(f, 80, SEEK_SET);

                        char *newline = readline("");

                        int i;
                        for (i = 0; i < strlen(newline); i++)
                                putc(newline[i], f);
                    
                        rewind(f);
                        break;
                    }
                }
            case 'a' :
                {
                    if (input[1] == 'b') {
                        append_bottom();
                        break;
                    }
                        if (input[0] == 'a' && isdigit(input[1])) {
                            int l;
                            l = atoi(&input[1]);
                            append_line(l);
                            break;
                    }

                }


            case 'c' :
                {
                    if (isdigit(input[1]) && input[0] == 'c') {

                        int d, c;
                        for (d = 1, c = 0; input[d] != '\0'; d++, c++) {
                            command_buffer[c] = input[d];
                        }
                        
                        char *changed_line = readline("");

                        
                        int line = atoi(command_buffer);
                        int ch, i;
                        for (ch = 1, i = 0;; ch++, i++) {
                            if (changed_line[i] == '\0') {
                                // buffer[ch][line] = changed_line[i];
                                buffer[ch][line] = '\n';
                                break;
                            }
                            buffer[ch][line] = changed_line[i];
                        }

                        if (line > total_lines)
                            total_lines++;

                        break;
                    }
                }

                case '!' :
                {
                    if (input[0] == '!') {
                        int d, c;
                        char shell_buffer[100]; 

                        for (d = 1, c = 0; input[d] != '\0'; d++, c++) {
                            shell_buffer[c] = input[d];
                        }

                        system(shell_buffer);
                        /* Clears shell buffer after each command.
                         * This ensures there is no 'leakage' 
                         * between calls.                       
                         */
                        int i;
                        for (i = 0; i < strlen(shell_buffer); i++)
                            shell_buffer[i] = 0;
                        break;
                    }
                }
                    
            case 'w' :
                {
                    if (input[1] == '\0') {
                        write_buffer_to_file(f);
                        printf("File written to disk\n");
                        break;
                    }
                    if (input[1] == 'q' && input[0] == 'w') {
                        write_buffer_to_file(f);
                        done = 1;
                        break;
                    }
                }

            case 'd' :
                {
                    if (isdigit(input[1]) && input[0] == 'd') {
                        clear_buffer_line(input[1]);
                        break;
                    }
                }

            default :
                {
                    printf("?\n");
                    break;
                }
            case 'q' :
                {
                    done = 1;
                    break;
                }
        }
    }
    if (f != NULL)
        fclose(f);
}
