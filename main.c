#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

vehicles* insert_vehicle(element *list, vehicles *veh_list) {
    element *aux = list;
    vehicles *new = create_vehicle();
    vehicle buff;
    char buff_code[50];

    input(buff_code, 50, "code of the employee you want to add a car:");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }

    if(aux == NULL) {
        printf("This code does not belongs to an employee!");
        return veh_list;
    }

    if(veh_list == NULL) {
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
        vehicles *aux_cmp = veh_list;
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

            aux_cmp = veh_list;
        } while(strlen(buff.code) == 0 || count != 0);

        strcpy(buff.employee_code, aux->employee.code);

        aux_cmp = veh_list;
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

            aux_cmp = veh_list;
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

    if(veh_list == NULL) {
        veh_list = new;
        new->next = NULL;
    }
    else {
        new->next = veh_list;
        veh_list = new;
    }

    return veh_list;
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

void read_vehicles(element *list, vehicles *veh_list) {
    element *aux = list;
    vehicles *aux_veh = veh_list;
    char buff_code[50];

    input(buff_code, 50, "code of the employee you want to list the vehicles:");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }

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
        if(strcmp(aux_veh->vehicle.employee_code, buff_code) == 0) {
            printf("employee's code: %s\ncode: %s\ndescription: %s\nplate: %s\nbrand: %s\nmodel: %s\n\n", aux_veh->vehicle.employee_code, aux_veh->vehicle.code, aux_veh->vehicle.description, aux_veh->vehicle.plate, aux_veh->vehicle.brand, aux_veh->vehicle.model);
            aux_veh = aux_veh->next;
        }
    }
}

void read_vehicles_by_code(element *list, vehicles *veh_list) {
    element *aux = list;
    vehicles *aux_veh = veh_list;
    char buff_code[50];

    input(buff_code, 50, "code of the employee you want to list the vehicles:");

    while(aux != NULL && strcmp(aux->employee.code, buff_code) != 0) {
        aux = aux->next;
    }

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
    printf("employee's code: %s\ncode: %s\ndescription: %s\nplate: %s\nbrand: %s\nmodel: %s\n\n", aux_veh->vehicle.employee_code, aux_veh->vehicle.code, aux_veh->vehicle.description, aux_veh->vehicle.plate, aux_veh->vehicle.brand, aux_veh->vehicle.model);
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

vehicles* update_vehicle(element *list, vehicles *veh_list) {
    element *aux = list;
    vehicles *aux_veh = veh_list;
    vehicle buff;
    char buff_code[50];

    input(buff_code, 50, "code of the employee that you want to change the vehicle: ");

    while(strcmp(aux->employee.code, buff_code) != 0 && aux->next != NULL) {
        aux = aux->next;
    }

    if(aux->next == NULL && strcmp(aux->employee.code, buff_code) != 0) {
        printf("The employee is not in the list!\n");
        return veh_list;
    }

    input(buff_code, 50, "code of the vehicle that you want to change: ");

    while(strcmp(aux_veh->vehicle.code, buff_code) != 0 && aux_veh->next != NULL) {
        aux_veh = aux_veh->next;
    }

    if(aux_veh->next == NULL && strcmp(aux_veh->vehicle.code, buff_code) != 0) {
        printf("The vehicle is not in the list!\n");
        return veh_list;
    }

        if(veh_list == NULL) {
        printf("\nUPDATE VEHICLE\n");
        do {
            input(buff.code, 50, "code(can not repeat or be empty):");
        } while(strlen(buff.code) == 0);
        strcpy(buff.employee_code, aux->employee.code);
        do{
            input(buff.description, 255, "description(can not be empty):");
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
        vehicles *aux_cmp = veh_list;
        int count;

        printf("\nUPDATE VEHICLE\n");
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

            aux_cmp = veh_list;
        } while(strlen(buff.code) == 0 || count != 0);

        strcpy(buff.employee_code, aux->employee.code);

        aux_cmp = veh_list;
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

            aux_cmp = veh_list;
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

    strcpy(aux_veh->vehicle.code, buff.code);
    strcpy(aux_veh->vehicle.employee_code, buff.employee_code);
    strcpy(aux_veh->vehicle.description, buff.description);
    strcpy(aux_veh->vehicle.brand, buff.brand);
    strcpy(aux_veh->vehicle.model, buff.model);
    strcpy(aux_veh->vehicle.plate, buff.plate);

    return veh_list;
}

vehicles* delete_vehicle(element *list, vehicles *veh_list) {
    element *aux = list;
    vehicles *aux_veh = veh_list;
    char buff_code[50];

    input(buff_code, 50, "code of the employee that you want to delete the vehicle: ");

    while(strcmp(aux->employee.code, buff_code) != 0 && aux->next != NULL) {
        aux = aux->next;
    }

    if(aux->next == NULL && strcmp(aux->employee.code, buff_code) != 0) {
        printf("The employee is not in the list!\n");
        return veh_list;
    }

    if(aux_veh == NULL) {
        printf("You can't delete from an empty list\n");
        return veh_list;
    }

    strcpy(buff_code, "");
    input(buff_code, 50, "code of the vehicle that you want to delete: ");

    if(strcmp(aux_veh->vehicle.code, buff_code) == 0) {
        vehicles *aux_veh2 = aux_veh;

        aux_veh = aux_veh->next;
        free(aux_veh2);

        return veh_list;
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
                return veh_list;
            }

            veh_rmv = veh;
            veh = veh->next;
            veh_bfr->next = veh;
            free(veh_rmv);

            return veh_list;
        }
        else {
            printf("The vehicle is not in the list!\n");
            return veh_list;
        }
    }

    return veh_list;
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

vehicles* insert_vehicle_data(vehicles *list, vehicle buff) {
    vehicles *new = create_vehicle();

    strcpy(new->vehicle.code, buff.code);
    strcpy(new->vehicle.description, buff.description);
    strcpy(new->vehicle.employee_code, buff.employee_code);
    strcpy(new->vehicle.brand, buff.brand);
    strcpy(new->vehicle.model, buff.model);
    strcpy(new->vehicle.plate, buff.plate);

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

vehicles* read_file_vehicles(vehicles *list) {
    FILE *f = fopen("vehicles.bin", "ab+");
    vehicle *data = malloc(sizeof(vehicle));

    fseek(f, 0, SEEK_SET);
    while(1) {
        fread(data, sizeof(vehicle), 1, f);

        if(feof(f)) {
            break;
        }

        list = insert_vehicle_data(list, *data);
    }

    fclose(f);
    return list;
}

void write_file_vehicle(vehicles *list) {
    FILE *f = fopen("vehicles.bin", "ab");
    vehicles *aux = list;
    vehicle *data;

    if(f == NULL) {
        printf("No memory availabe\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    while(aux != NULL) {
        data = &aux->vehicle;
        fwrite(data, sizeof(vehicle), 1, f);

        aux = aux->next;
    }

    fclose(f);
}

int main() {
    element *emp_list = NULL;
    vehicles *veh_list = NULL;
    int menu = -1;

    do {
        char aux[5];
        printf("1 - Employee\n");
        printf("2 - Vehicle\n");
        printf("3 - Save\n");
        printf("4 - Load\n");
        printf("5 - Quit\n");

        input(aux, 5, ">> ");
        menu = atoi(aux);

        switch(menu) {
            case 1:
                printf("\n1 - Insert employee\n");
                printf("2 - Update employee\n");
                printf("3 - Read all employees\n");
                printf("4 - Read one employee by code\n");
                printf("5 - Delete employee\n");
                printf("6 - Go back\n");

                input(aux, 5, ">> ");
                printf("\n");
                menu = atoi(aux);

                switch(menu) {
                    case 1:
                        emp_list = insert_employee(emp_list);
                        break;
                    case 2:
                        emp_list = update_employee(emp_list);
                        printf("\n");
                        break;
                    case 3:
                        read_employee(emp_list);
                        break;
                    case 4:
                        read_employee_by_code(emp_list);
                        break;
                    case 5:
                        emp_list = delete_employee(emp_list);
                        printf("\n");
                        break;
                    case 6:
                        break;
                    default:
                        printf("This is not a valid input!\n\n");
                        break;
                }
                break;
            case 2:
                printf("1 - Insert vehicle\n");
                printf("2 - Update vehicle\n");
                printf("3 - Read all vehicles from one employee\n");
                printf("4 - Read one vehicle by code\n");
                printf("5 - Delete vehicle\n");
                printf("6 - Go back\n");

                input(aux, 5, ">> ");
                menu = atoi(aux);

                switch(menu) {
                    case 1:
                        veh_list = insert_vehicle(emp_list, veh_list);
                        printf("\n");
                        break;
                    case 2:
                        veh_list = update_vehicle(emp_list, veh_list);
                        printf("\n");
                        break;
                    case 3:
                        read_vehicles(emp_list, veh_list);
                        break;
                    case 4:
                        read_vehicles_by_code(emp_list, veh_list);
                        break;
                    case 5:
                        veh_list = delete_vehicle(emp_list, veh_list);
                        break;
                    case 6:
                        break;
                    default:
                        printf("This is not a valid input!\n\n");
                        break;
                }
                break;
            case 3:
                write_file_employee(emp_list);
                write_file_vehicle(veh_list);
                break;
            case 4:
                emp_list = read_file_employee(emp_list);
                veh_list = read_file_vehicles(veh_list);
                break;
            case 5:
                menu = 0;
                break;
            default:
                printf("This is not a valid input!\n\n");
                break;
        }
    } while(menu != 0);

    return 0;
}