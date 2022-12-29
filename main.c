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
    vehicle vehicle;
    struct vehicles *next;
} vehicles;

typedef struct {
    char code[50];
    char name[255];
    char address[255];
    char wage[50];
    char birth_date[50];
    vehicles *vehicles;
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

element* create_element() {
    element *new = (element*) malloc(sizeof(element));
    return new;
}

vehicles* create_vehicle() {
    vehicles *new = (vehicles*) malloc(sizeof(vehicles));
    return new;
}

element* insert_vehicle(element *list) {
    element *aux = list;
    vehicles *new = create_vehicle();
    buffer_veh buff;
    char buff_code[50];

    input(buff_code, 50, "code of the employee you want to add a car:");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }

    if(aux == NULL) {
        printf("This code does not belongs to an employee!");
        return list;
    }

    if(aux->employee.vehicles == NULL) {
        printf("\nCREATE VEHICLE\n");
        do {
            input(buff.code, 50, "code(can not repeat or be empty):");
        } while(strlen(buff.code) == 0);
        strcpy(buff.employee_code, aux->employee.code);
        do{
            input(buff.description, 255, "description(can not repeat or be empty):");
        } while(strlen(buff.description) == 0);
        do{
            input(buff.brand, 50, "brand(can not be empty):");
        } while(strlen(buff.brand) == 0);
        do{
            input(buff.model, 50, "model(can not be empty):");
        } while(strlen(buff.model) == 0);
        do{
            input(buff.plate, 50, "plate(can not be empty):");
        } while(strlen(buff.plate) == 0);
    }
    else {
        vehicles *aux_cmp = aux->employee.vehicles;
        int count;

        printf("\nCREATE VEHICLE\n");
        do {
            count = 0;
            input(buff.code, 50, "code(can not repeat or be empty):");
            
            while(aux_cmp != NULL) {
                if(strcmp(aux_cmp->vehicle.code, buff.code) == 0) {
                    count++;
                    break;
                }
                aux_cmp = aux_cmp->next;
            }

            aux_cmp = aux->employee.vehicles;
        } while(strlen(buff.code) == 0 || count != 0);

        strcpy(buff.employee_code, aux->employee.code);

        aux_cmp = aux->employee.vehicles;
        do{
            count = 0;
            input(buff.description, 255, "description(can not repeat or be empty):");

            while(aux_cmp != NULL) {
                if(strcmp(aux_cmp->vehicle.description, buff.description) == 0) {
                    count++;
                    break;
                }
                aux_cmp = aux_cmp->next;
            }

            aux_cmp = aux->employee.vehicles;
        } while(strlen(buff.description) == 0 || count != 0);
        do{
            input(buff.brand, 50, "brand(can not be empty):");
        } while(strlen(buff.brand) == 0);
        do{
            input(buff.model, 50, "model(can not be empty):");
        } while(strlen(buff.model) == 0);
        do{
            input(buff.plate, 50, "plate(can not be empty):");
        } while(strlen(buff.plate) == 0);
    }

    strcpy(new->vehicle.code, buff.code);
    strcpy(new->vehicle.employee_code, buff.employee_code);
    strcpy(new->vehicle.description, buff.description);
    strcpy(new->vehicle.brand, buff.brand);
    strcpy(new->vehicle.model, buff.model);
    strcpy(new->vehicle.plate, buff.plate);

    if(aux->employee.vehicles == NULL) {
        aux->employee.vehicles = new;
        new->next = NULL;
    }
    else {
        new->next = aux->employee.vehicles;
        aux->employee.vehicles = new;
    }

    return list;
}

element* insert_employee(element *list) {
    element *new = create_element();
    buffer_emp buff;

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
    new->employee.vehicles = NULL;

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
        printf("No employees created, empty list!\n");
        return;
    }
    while(aux != NULL) {
        printf("code: %s\nname: %s\naddress: %s\nwage: %s\nbirth date: %s\n\n", aux->employee.code, aux->employee.name, aux->employee.address, aux->employee.wage, aux->employee.birth_date);
        aux = aux->next;
    }
}

void read_vehicles(element *list) {
    element *aux = list;
    vehicles *aux_veh;
    char buff_code[50];

    input(buff_code, 50, "code of the employee you want to list the vehicles:");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }
    aux_veh = aux->employee.vehicles;

    if(aux == NULL) {
        printf("This code does not belongs to an employee!\n");
        return;
    }
    else if(aux_veh == NULL) {
        printf("This employee does not have any vehicles!\n");
        return;
    }

    printf("\nREAD VEHICLE\n");
    while(aux_veh != NULL) {
        printf("code: %s\nemployee's code: %s\ndescription: %s\nplate: %s\nbrand: %s\nmodel: %s\n\n", aux_veh->vehicle.code, aux_veh->vehicle.employee_code, aux_veh->vehicle.description, aux_veh->vehicle.plate, aux_veh->vehicle.brand, aux_veh->vehicle.model);
        aux_veh = aux_veh->next;
    }
}

void read_vehicles_by_code(element *list) {
    element *aux = list;
    vehicles *aux_veh;
    char buff_code[50];

    input(buff_code, 50, "code of the employee you want to list the vehicles:");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }
    aux_veh = aux->employee.vehicles;

    if(aux == NULL) {
        printf("This code does not belongs to an employee or they do not have vehicles!");
        return;
    }
    else if(aux_veh == NULL) {
        printf("\nREAD VEHICLE BY CODE\n");
        printf("This employee does not have any vehicles!\n");
        return;
    }

    strcpy(buff_code, "");
    input(buff_code, 50, "code of the vehicle you want to list:");

    while(aux_veh != NULL && strcmp(aux_veh->vehicle.code, buff_code) != 0) {
        aux_veh = aux_veh->next;
    }

    printf("\nREAD VEHICLE BY CODE\n");
    printf("code: %s\nemployee's code: %s\ndescription: %s\nplate: %s\nbrand: %s\nmodel: %s\n\n", aux_veh->vehicle.code, aux_veh->vehicle.employee_code, aux_veh->vehicle.description, aux_veh->vehicle.plate, aux_veh->vehicle.brand, aux_veh->vehicle.model);
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

element* update_vehicle(element *list) {
    element *aux = list;
    vehicles *aux_veh;
    buffer_veh buff;
    char buff_code[50];

    input(buff_code, 50, "code of the employee that you want to change the vehicle: ");

    while(strcmp(aux->employee.code, buff_code) != 0 && aux->next != NULL) {
        aux = aux->next;
    }

    if(aux->next == NULL && strcmp(aux->employee.code, buff_code) != 0) {
        printf("The employee is not in the list!\n");
        return list;
    }

    strcpy(buff_code, "");
    input(buff_code, 50, "code of the vehicle that you want to change: ");

    aux_veh = aux->employee.vehicles;
    while(strcmp(aux_veh->vehicle.code, buff_code) != 0 && aux_veh->next != NULL) {
        aux_veh = aux_veh->next;
    }

    if(aux_veh->next == NULL && strcmp(aux_veh->vehicle.code, buff_code) != 0) {
        printf("The vehicle is not in the list!\n");
        return list;
    }

        if(aux->employee.vehicles == NULL) {
        printf("\nUPDATE VEHICLE\n");
        do {
            input(buff.code, 50, "code:");
        } while(strlen(buff.code) == 0);
        strcpy(buff.employee_code, aux->employee.code);
        do{
            input(buff.description, 255, "description:");
        } while(strlen(buff.description) == 0);
        do{
            input(buff.brand, 50, "brand:");
        } while(strlen(buff.brand) == 0);
        do{
            input(buff.model, 50, "model:");
        } while(strlen(buff.model) == 0);
        do{
            input(buff.plate, 50, "plate:");
        } while(strlen(buff.plate) == 0);
    }
    else {
        vehicles *aux_cmp = aux->employee.vehicles;
        int count;

        printf("\nUPDATE VEHICLE\n");
        do {
            count = 0;
            input(buff.code, 50, "code:");
            
            while(aux_cmp != NULL) {
                if(strcmp(aux_cmp->vehicle.code, buff.code) == 0) {
                    count++;
                    break;
                }
                aux_cmp = aux_cmp->next;
            }

            aux_cmp = aux->employee.vehicles;
        } while(strlen(buff.code) == 0 || count != 0);

        strcpy(buff.employee_code, aux->employee.code);

        aux_cmp = aux->employee.vehicles;
        do{
            count = 0;
            input(buff.description, 255, "description:");

            while(aux_cmp != NULL) {
                if(strcmp(aux_cmp->vehicle.description, buff.description) == 0) {
                    count++;
                    break;
                }
                aux_cmp = aux_cmp->next;
            }

            aux_cmp = aux->employee.vehicles;
        } while(strlen(buff.description) == 0 || count != 0);
        do{
            input(buff.brand, 50, "brand:");
        } while(strlen(buff.brand) == 0);
        do{
            input(buff.model, 50, "model:");
        } while(strlen(buff.model) == 0);
        do{
            input(buff.plate, 50, "plate:");
        } while(strlen(buff.plate) == 0);
    }

    strcpy(aux_veh->vehicle.code, buff.code);
    strcpy(aux_veh->vehicle.employee_code, buff.employee_code);
    strcpy(aux_veh->vehicle.description, buff.description);
    strcpy(aux_veh->vehicle.brand, buff.brand);
    strcpy(aux_veh->vehicle.model, buff.model);
    strcpy(aux_veh->vehicle.plate, buff.plate);

    return list;
}

element* delete_vehicle(element *list) {
    element *aux = list;
    vehicles *aux_veh;
    char buff_code[50];

    input(buff_code, 50, "code of the employee that you want to delete the vehicle: ");

    while(strcmp(aux->employee.code, buff_code) != 0 && aux->next != NULL) {
        aux = aux->next;
    }

    if(aux->next == NULL && strcmp(aux->employee.code, buff_code) != 0) {
        printf("The employee is not in the list!\n");
        return list;
    }

    aux_veh = aux->employee.vehicles;
    if(aux_veh == NULL) {
        printf("You can't delete from an empty list\n");
        return list;
    }

    strcpy(buff_code, "");
    input(buff_code, 50, "code of the vehicle that you want to delete: ");

    if(strcmp(aux_veh->vehicle.code, buff_code) == 0) {
        vehicles *aux_veh2 = aux_veh;

        aux_veh = aux_veh->next;
        free(aux_veh2);

        return list;
    }
    else {
        if(aux_veh->next != NULL) {
            vehicles *veh_bfr = aux_veh;
            vehicles *veh = aux_veh->next;
            vehicles *veh_rmv = NULL;

            while(veh->next != NULL && strcmp(veh->vehicle.code, buff_code) != 0) {
                veh_bfr = veh_bfr->next;
                veh = veh->next;
            }

            if(veh->next == NULL && strcmp(veh->vehicle.code, buff_code) != 0) {
                printf("The vehicle is not in the list!\n");
                return list;
            }

            veh_rmv = veh;
            veh = veh->next;
            veh_bfr->next = veh;
            free(veh_rmv);

            return list;
        }
        else {
            printf("The vehicle is not in the list!\n");
            return list;
        }
    }

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
    read_employee(list);

    list = insert_vehicle(list);
    list = insert_vehicle(list);
    list = insert_vehicle(list);
    read_vehicles(list);
    
    return 0;
}