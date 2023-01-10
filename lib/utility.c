#include <stdio.h>

void input(char str[], int tam, char *msg) {
    printf("%s", msg);
    fgets(str, tam, stdin);
    fflush(stdin);

    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
}