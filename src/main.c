#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include "file.h"
#include "buffer.h"
#include "text.h"
#define MAX_FILE_NAME 100

int main(int argc, char* argv[]) {
    FILE *f = NULL;
    char mode[] = "r+";
    char command_buffer[10];

    if (argc == 2) {
        f = fopen(argv[1], mode);
        load_buffer(f);
    } 

    int done = 0;

    while (!done) {
        char *input = readline("> ");
        
        /* Note: This switch statement relies on 'dropoff' between cases */
        switch (input[0]) {
            case 'p' : 
                {
                    if (input[1] == '\0') {
                        print_buffer();
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
                                        printf("lines %d\n", lines);
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
                     * between calls.                       */
                    memset(shell_buffer, 0, sizeof shell_buffer);
                    break;
                    }
                }
                    
            case 'w' :
                {
                    if (input[1] == '\0') {
                        write_buffer_to_file(f);
                        printf("saved\n");
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
