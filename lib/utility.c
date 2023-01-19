#include <stdio.h>
#include <string.h>
#include <ctype.h>

void input(char str[], int tam, char *msg) {
    printf("%s", msg);
    fgets(str, tam, stdin);
    fflush(stdin);

    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
}

void lower_case(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

void upper_case(char *str) {
    for (int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
    
}