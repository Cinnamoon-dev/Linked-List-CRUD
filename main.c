#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char code[50];
    char name[255];
    char address[255];
    char wage[50];
    char birth_date[50];
} buffer_emp;

typedef struct {
    char code[50];
    char employee_code[50];
    char description[255];
    char plate[50];
    char brand[50];
    char model[50];
} buffer_veh;

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
    char code[50];
    char name[255];
    char address[255];
    char wage[50];
    char birth_date[50];
    vehicles vehicles;
} employee;

typedef struct {
    employee employee;
    struct element *next;
} element;

void input(char str[], int tam, char *msg) {
    printf("%s", msg);
    fgets(str, tam, stdin);
    fflush(stdin);

    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
}

void lower_case(char *string) {
    for(int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
}

element* create_element() {
    element *new = (element*) malloc(sizeof(element));
    return new;
}

element* insert_employee(element *list) {
    element *new = create_element();
    buffer_emp buff;

    if(list == NULL) {
        do { input(buff.code, 50, "code(can not repeat or be empty): "); } while(strlen(buff.code) == 0);
        do { input(buff.name, 255, "name(can not be empty): "); } while(strlen(buff.name) == 0);
        do { input(buff.address, 255, "address(can not be empty): "); } while(strlen(buff.address) == 0);
        input(buff.wage, 50, "wage: ");
        do { input(buff.birth_date, 50, "birth date(can not be empty): "); } while(strlen(buff.birth_date) == 0);
    }
    else {
        element *aux = list;
        int count;

        do{
            count = 0;
            input(buff.code, 50, "code(can not repeat or be empty): ");

            while(aux != NULL) {
                if(strcmp(aux->employee.code, buff.code) == 0) {
                    count++;
                    break;
                }
                aux = aux->next;
            }

            aux = list;
        } while(strlen(buff.code) == 0 || count != 0);

        do{ input(buff.name, 255, "name(can not be empty): "); } while(strlen(buff.name) == 0);
        do { input(buff.address, 255, "address(can not be empty): "); } while(strlen(buff.address) == 0);
        input(buff.wage, 50, "wage: ");
        do { input(buff.birth_date, 50, "birth date(can not be empty): "); } while(strlen(buff.birth_date) == 0);
    }


    strcpy(new->employee.code, buff.code);
    strcpy(new->employee.name, buff.name);
    strcpy(new->employee.address, buff.address);
    strcpy(new->employee.wage, buff.wage);
    strcpy(new->employee.birth_date, buff.birth_date);

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

void read_employee(element *list) {
    element *aux = list;

    printf("\nLISTAGEM\n");
    while(aux != NULL) {
        printf("code: %s\nname: %s\naddress: %s\nwage: %s\nbirth date: %s\n\n", aux->employee.code, aux->employee.name, aux->employee.address, aux->employee.wage, aux->employee.birth_date);
        aux = aux->next;
    }
}

element* update_employee(element *list) {
    element *aux = list;
    char buff_code[50];
    int count;
    buffer_emp buff;

    input(buff_code, 50, "code of the employee that you want to change: ");

    while(strcmp(aux->employee.code, buff_code) != 0 && aux->next != NULL) {
        aux = aux->next;
    }

    if(aux->next == NULL && strcmp(aux->employee.code, buff_code) != 0) {
        printf("The employee is not in the list!\n");
        return list;
    }

    do{
        count = 0;
        input(buff.code, 50, "code(can not repeat or be empty): ");

        while(aux != NULL) {
            if(strcmp(aux->employee.code, buff.code) == 0) {
                count++;
                break;
            }
            aux = aux->next;
        }

        aux = list;
    } while(strlen(buff.code) == 0 || count != 0);

    do{ input(buff.name, 255, "name(can not be empty): "); } while(strlen(buff.name) == 0);
    do { input(buff.address, 255, "address(can not be empty): "); } while(strlen(buff.address) == 0);
    input(buff.wage, 50, "wage: ");
    do { input(buff.birth_date, 50, "birth date(can not be empty): "); } while(strlen(buff.birth_date) == 0);

    strcpy(aux->employee.code, buff.code);
    strcpy(aux->employee.name, buff.name);
    strcpy(aux->employee.address, buff.address);
    strcpy(aux->employee.wage, buff.wage);
    strcpy(aux->employee.birth_date, buff.birth_date);

    return list;
}

element* delete_employee(element *list) {
    if(list == NULL) {
        printf("You can't delete from an empty list\n");
        return list;
    }

    char buff_code[50];
    input(buff_code, 50, "code of the employee that you want to delete: ");

    if(strcmp(list->employee.code, buff_code) == 0) {
        element *aux = list;

        list = list->next;
        free(aux);

        return list;
    }
    else {
        if(list->next != NULL) {
            element *aux_bfr = list;
            element *aux = list->next;
            element *aux_rmv = NULL;

            while(aux->next != NULL && strcmp(aux->employee.code, buff_code) != 0) {
                aux_bfr = aux_bfr->next;
                aux = aux->next;
            }

            if(aux->next == NULL && strcmp(aux->employee.code, buff_code) != 0) {
                printf("The employee is not in the list!\n");
                return list;
            }

            aux_rmv = aux;
            aux = aux->next;
            aux_bfr->next = aux;
            free(aux_rmv);

            return list;
        }
        else {
            printf("The employee is not in the list!\n");
            return list;
        }
    }

    return list;
}

int main() {
    element *list = NULL;

    list = insert_employee(list);
    list = insert_employee(list);
    list = insert_employee(list);
    read_employee(list);

    list = update_employee(list);
    read_employee(list);

    list = delete_employee(list);
    read_employee(list);
    return 0;
}