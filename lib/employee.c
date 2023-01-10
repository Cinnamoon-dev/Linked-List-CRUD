#include "employee.h"

element* create_element() {
    element *new = (element*) malloc(sizeof(element));
    return new;
}

element* insert_employee(element *list) {
    element *new = create_element();
    employee buff;

    if(list == NULL) {
        printf("\nCREATE EMPLOYEE\n");
        do { input(buff.code, 50, "code(can not repeat or be empty): "); } while(strlen(buff.code) == 0);
        do { input(buff.name, 255, "name(can not be empty): "); } while(strlen(buff.name) == 0);
        do { input(buff.address, 255, "address(can not be empty): "); } while(strlen(buff.address) == 0);
        input(buff.wage, 50, "wage: ");
        do { input(buff.birth_date, 50, "birth date(can not be empty): "); } while(strlen(buff.birth_date) == 0);
    }
    else {
        element *aux = list;
        int count;

        printf("\nCREATE EMPLOYEE\n");
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

    printf("\nREAD EMPLOYEE\n");
    if(aux == NULL) {
        printf("No employees created, empty list!\n\n");
        return;
    }
    while(aux != NULL) {
        printf("code: %s\nname: %s\naddress: %s\nwage: %s\nbirth date: %s\n\n", aux->employee.code, aux->employee.name, aux->employee.address, aux->employee.wage, aux->employee.birth_date);
        aux = aux->next;
    }
}

void read_employee_by_code(element *list) {
    element *aux = list;
    char buff_code[50];
    
    input(buff_code, 50, "code of the employee you want to print: ");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }

    if(aux == NULL) {
        printf("This code does not belongs to an employee!");
        return;
    }

    printf("\nREAD EMPLOYEE BY CODE\n");
    printf("\ncode: %s\nname: %s\naddress: %s\nwage: %s\nbirth date: %s\n\n", aux->employee.code, aux->employee.name, aux->employee.address, aux->employee.wage, aux->employee.birth_date);
}

element* update_employee(element *list) {
    element *aux = list;
    char buff_code[50];
    int count;
    employee buff;

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

element* insert_employee_data(element *list, employee buff) {
    element *new = create_element();

    strcpy(new->employee.code, buff.code);
    strcpy(new->employee.address, buff.address);
    strcpy(new->employee.name, buff.name);
    strcpy(new->employee.birth_date, buff.birth_date);
    strcpy(new->employee.wage, buff.wage);

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

void write_file_employee(element *list) {
    FILE *f = fopen("employee.bin", "ab");
    element *aux = list;
    employee *data;

    if(f == NULL) {
        printf("No memory availabe\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    while(aux != NULL) {
        data = &aux->employee;
        fwrite(data, sizeof(employee), 1, f);

        aux = aux->next;
    }

    fclose(f);
}

element* read_file_employee(element *list) {
    FILE *f = fopen("employee.bin", "ab+");
    employee *data = malloc(sizeof(employee));

    fseek(f, 0, SEEK_SET);
    while(1) {
        fread(data, sizeof(employee), 1, f);

        if(feof(f)) {
            break;
        }

        list = insert_employee_data(list, *data);
    }

    fclose(f);
    free(data);
    return list;
}