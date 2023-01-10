#include "vehicles.h"

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