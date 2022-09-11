#include<stdio.h>
#include<string.h>
#include<readline/readline.h>

int main(int argc, char* argv[]) {
//    char *input;
//    input = readline("input filename: ");
//    printf("%s\n", input);

    char mode = 'r';
    FILE *f;
    f = fopen(argv[1], &mode);
    
    char buffer[255];
    while (fgets(buffer, 255, f)) {
        printf("%s", buffer);
    }

    fclose(f);
}
