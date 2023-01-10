#ifndef VEHICLES_H
#define VEHICLES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

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

vehicles* create_vehicle();

vehicles* insert_vehicle(element *list, vehicles *veh_list);

void read_vehicles(element *list, vehicles *veh_list);

void read_vehicles_by_code(element *list, vehicles *veh_list);

vehicles* update_vehicle(element *list, vehicles *veh_list);

vehicles* delete_vehicle(element *list, vehicles *veh_list);

vehicles* insert_vehicle_data(vehicles *list, vehicle buff);

vehicles* read_file_vehicles(vehicles *list);

void write_file_vehicle(vehicles *list);

#endif VEHICLES_H