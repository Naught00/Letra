#include<stdio.h>
#include<string.h>
#include<readline/readline.h>
#include "line.h"

int main(int argc, char* argv[]) {
    FILE *f;
    char mode = 'r';
    char file_name[100];

    char buffer[255];

    int e = 0;
    
    int done = 0;
    while (!done) {
        char *input = readline("");

        switch (*input) {
            case 'p' : {
                if (e) {
                    f = fopen(file_name, &mode);
                    printall(&f);
                    fclose(f);
                } else {
                    f = fopen(argv[1], &mode);
                    printall(&f);
                    fclose(f);
                }
            }
                break;

            case 'n' :
                if (e) {
                    f = fopen(file_name, &mode);
                    printallnum(&f);
                    fclose(f);
                } else {
                    f = fopen(argv[1], &mode);
                    printallnum(&f);
                    fclose(f);
                }
                break;

            case 'e' : {
                int len = strlen(input);
                int ans = len - 2;

                int i = 0;
                e = 1;
                if (input[0] == 'e' && input[1] == ' ') {
                    for (i = 0; i <= ans; i++) {
                        file_name[i] = input[i+2];
                        if (i == (ans)) {
                            file_name[i] = '\0';
                        }
                    }
                }

                
                break;
            }

            default : {
                printf("?\n");
                break;
            }

            case 'q' : {
                done = 1;
                break;
            }
        }
    }
}
