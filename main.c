#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    struct element *next;
} element;

element* create_element() {
    element *new = (element*) malloc(sizeof(element));
    return new;
}

element* insert_element(element *list, int data) {
    element *new = create_element();
    new->num = data;

    const int list_is_empty = (list == NULL);
    if(list_is_empty) {
        list = new;
        new->next = NULL;  

        return list; 
    } 

    new->next = list;
    list = new;

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

    const int end_of_list = (aux->next == NULL);
    const int element_not_reached = (aux->num != value);
    if(end_of_list && element_not_reached) {
        printf("This number is not in the list!\n");
        return list;
    }

    aux->num = data;
    return list;
}

element* delete_element(element *list, int value) {
    const int list_is_empty = (list == NULL);
    if(list_is_empty) {
        printf("You can't delete from an empty list\n");
        return list;
    }

    const int delete_first_element = (list->num == value);
    if(delete_first_element) {
        element *aux;

        aux = list;
        list = list->next;
        free(aux);

        return list;
    }

    const int one_element_list = (list->next == NULL);
    if(one_element_list && !delete_first_element){
        printf("This number is not in the list!\n");
        return list;
    }

    element *aux_bfr = list;
    element *aux = list->next;
    element *aux_rmv = NULL;

    int in_the_end_of_list = (aux->next == NULL);
    int element_not_reached = (aux->num != value);
    while(!in_the_end_of_list && element_not_reached) {
        aux_bfr = aux_bfr->next;
        aux = aux->next;

        in_the_end_of_list = (aux->next == NULL);
        element_not_reached = (aux->num != value);
    }

    if(in_the_end_of_list && element_not_reached) {
        printf("This number is not in the list!\n");
        return list;
    }            

    aux_rmv = aux;
    aux_bfr->next = aux->next;
    free(aux_rmv);

    return list;
}

void write_file(element *list) {
    FILE *f = fopen("data.bin", "ab");
    element *aux = list;
    int *data;

    const int file_did_not_open = (f == NULL);
    if(file_did_not_open) {
        printf("No memory availabe!\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    while(aux != NULL) {
        data = &aux->num;
        fwrite(data, sizeof(int), 1, f);

        aux = aux->next;
    }

    fclose(f);
}

element* read_file(element *list) {
    FILE *f = fopen("data.bin", "rb");
    int *data = malloc(sizeof(int));

    const int file_did_not_open = (f == NULL);
    if(file_did_not_open) {
        printf("No employees saved!\n");
        return;
    }

    fseek(f, 0, SEEK_SET);
    while(1) {
        fread(data, sizeof(int), 1, f);

        if(feof(f)) { 
            break;
        }

        list = insert_element(list, *data);
    }

    fclose(f);
    free(data);
    return list;
}

int main() {
    element *list = NULL;

    list = insert_element(list, 1);
    list = insert_element(list, 2);
    list = insert_element(list, 3);
    list = insert_element(list, 4);
    list = insert_element(list, 5);

    read_element(list);
    list = update_element(list, 7, 3);
    list = delete_element(list, 1);
    list = delete_element(list, 5);

    read_element(list);

    return 0;
}