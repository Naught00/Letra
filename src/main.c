#include<stdio.h>
#include<string.h>
#include<readline/readline.h>
#include "file.h"
#include "buffer.h"
#include "text.h"
#define MAX_FILE_NAME 100

int main(int argc, char* argv[]) {
    FILE *f = NULL;
    char mode[] = "r+";

    if (argc == 2) {
        f = fopen(argv[1], mode);
        load_buffer(f);
    } 

    int done = 0;

    while (!done) {
        char *input = readline("> ");
        
        /* Switch statement relies on 'dropoff' between cases
         * Not sure if genius or insane */

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

            case 'c' :
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
