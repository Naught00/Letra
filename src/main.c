#include<stdio.h>
#include<string.h>
#include<readline/readline.h>
#include "file.h"
#include "buffer.h"
#define MAX_FILE_NAME 100


int main(int argc, char* argv[]) {
    FILE *f;
    char mode[] = "r+";

    if (argc == 2) {
        f = fopen(argv[1], mode);
        load_buffer(f);
        print_buffer();
    } 

    int done = 0;

    while (!done) {
        char *input = readline("> ");

        switch (*input) {
            case 'p' : {
                           print_buffer();
                break;
            }

            case 'n' : {
                           print_buffer_with_numbers();
                break;
            }
                
            case 'e' : {
                char file_name[MAX_FILE_NAME];
                int len = strlen(input);
                int ans = len - 2;

                int i = 0;
                if (input[0] == 'e' && input[1] == ' ') {
                    for (i = 0; i <= ans; i++) {
                        file_name[i] = input[i+2];
                        if (i == (ans)) {
                            file_name[i] = '\0';
                        }
                    }
                } else 
                    printf("?\n");

                f = fopen(file_name, mode);

                
                break;
            }

            case 'c' : {
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

            default : {
                printf("?\n");
                break;
            }

            case 'q' : {
                done = 1;
                break;
            }
            case 't' : {
                break;
            }
        }
    }
    fclose(f);
}
