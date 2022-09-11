#include<stdio.h>
#include<string.h>
#include<readline/readline.h>

int main(int argc, char* argv[]) {
    char mode = 'r';
    FILE *f;
    f = fopen(argv[1], &mode);
    
    char buffer[255];

    int i;
    i = 1;
    while (fgets(buffer, 255, f)) {
        printf("%d\t%s", i, buffer);
        i++;
    }

    fclose(f);
}
