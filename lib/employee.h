#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

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

void input(char str[], int tam, char *msg);

element* create_element();

element* insert_employee(element *list);

void read_employee(element *list);

void read_employee_by_code(element *list);

element* update_employee(element *list);

element* delete_employee(element *list);

element* insert_employee_data(element *list, employee buff);

void write_file_employee(element *list);

element* read_file_employee(element *list);

#endif EMPLOYEE_H