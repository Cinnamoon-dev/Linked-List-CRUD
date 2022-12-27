#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char code_employee[50];
    char code_vehicle[50];
    char name[255];
    char address[255];
    char wage[50];
    char birth_date[50];
    char type[50];
    char description[255];
    char plate[50];
    char brand[50];
    char model[50];
} buffer;

typedef struct {
    char code[50];
    char name[255];
    char address[255];
    char wage[50];
    char birth_date[50];
    char type[50];
    vehicles vehicles;
} employee;

typedef struct {
    char code[50];
    char employee_code[50];
    char description[255];
    char plate[20];
    char brand[50];
    char model[50];
} vehicle;

typedef struct {
    vehicle *vehicle;
    int count;
} vehicles;

typedef struct {
    employee employee;
    struct element *next;
} element;

element* create_element() {
    element *new = (element*) malloc(sizeof(element));
    return new;
}

element* insert_element(element *list, int data) {
    element *new = create_element();
    new->num = data;

    if(list == NULL) {
        list = new;
        new->next = NULL;   
    } 
    else {
        new->next = list;
        list = new;
    }

    return list;
}

void read_element(element *list) {
    element *aux = list;

    while(aux != NULL) {
        printf("%d\n", aux->num);
        aux = aux->next;
    }
    printf("\n");
}

element* update_element(element *list, int data, int value) {
    element *aux = list;

    while(aux->num != value && aux->next != NULL) {
        aux = aux->next;
    }

    if(aux->next == NULL && aux->num != value) {
        printf("This number is not in the list!\n");
        return list;
    }

    aux->num = data;
    return list;
}

element* delete_element(element *list, int value) {
    if(list == NULL) {
        printf("You can't delete from an empty list\n");
        return list;
    }

    else if(list->num == value) { // if it is the first one
        element *aux;

        aux = list;
        list = list->next;
        free(aux);

        return list;
    }

    else {
        if(list->next != NULL) {
            element *aux_bfr = list;
            element *aux = list->next;
            element *aux_rmv = NULL;

            while(aux->next != NULL && aux->num != value) {
                aux_bfr = aux_bfr->next;
                aux = aux->next;
            }

            if(aux->next == NULL && aux->num != value) {
                printf("This number is not in the list!\n");
                return list;
            }            

            aux_rmv = aux;
            aux = aux->next;
            aux_bfr->next = aux;
            free(aux_rmv);

            return list;
        }
        else {
            printf("This number is not in the list!\n");
            return list;
        }
    }

    return list;
}

void input(char str[], int tam, char *msg)
{
    printf("%s", msg);
    fgets(str, tam, stdin);
    fflush(stdin);

    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
}

void lower_case(char *string)
{
    for(int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
}

void create_employee(element *list) {
    element *aux = create_element();
    
}

int main() {
    element *list = NULL;

    return 0;
}