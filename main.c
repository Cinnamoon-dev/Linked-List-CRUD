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

void write_file(element *list) {
    FILE *f = fopen("data.bin", "ab");
    element *aux = list;
    int *data;

    if(f == NULL) {
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

    list = read_file(list);
    read_element(list);
    write_file(list);

    return 0;
}