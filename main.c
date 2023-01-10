#include "employee.h"
#include "vehicles.h"

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