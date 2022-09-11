#include<stdio.h>
#include<string.h>
#include<readline/readline.h>
#include "print.h"

int main(int argc, char* argv[]) {

    char mode = 'r';
    FILE *f;
    f = fopen(argv[1], &mode);
    
    char buffer[255];

    int done = 0;
    while (!done) {
        char *input = readline(":");

        switch (*input) {

            case 'p' :
                printall(buffer, f);
                break;

            default :
                break;

            case 'q' :
                done = 1;
        }

    }

    fclose(f);

}
