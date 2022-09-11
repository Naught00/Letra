#include<stdio.h>
#include<string.h>
#include<readline/readline.h>
#include "print.h"

int main(int argc, char* argv[]) {

    char mode = 'r';
    FILE *f;
    f = fopen(argv[1], &mode);
    
    char buffer[255];

    while (1) {
        char *input = readline(":");

        switch (*input) {

            case 'p' :
                printall(buffer, f);
                break;

            default :
                break;

            case 'q' :
                return 0;
        }

    }

    fclose(f);

}
