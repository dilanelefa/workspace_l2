#include <stdio.h>
#include <stdlib.h>

#include "function.h"

/*
    helpers programm
*/

list init(){
    list liste = NULL;
    return liste;
}

//insert the integer in the list
void insert(list *l, int value){
    list element = (list)malloc(sizeof(struct cellule));
    element->next = NULL;
    element->value = value;

    if(*l == NULL){
        *l = element;
    }
    else{
        list iterator = *l;
        while(iterator->next != NULL)
            iterator = iterator->next;
        iterator->next  = element;
    }
}

//print the list in parameter on the screen
void display(list l){
    if(l != NULL){
        printf("[");
        while(l != NULL){
            printf("%d, ", l->value);
            l = l->next;
        }
        printf("\b\b]\n");
    }
    else{
        printf("[]\n");
    }
}

/*
  1. Create list function
*/

//create a list of two integer
list create_list_of_two_integer(){
    int a;
    list t = init();
    list element1 = malloc(sizeof(struct cellule));
    printf("Enter the first element: ");
    scanf("%d", &a);
    insert(&t, a);
    printf("Enter the second element: ");
    scanf("%d", &a);
    insert(&t,a);
    return t;
}


//create a list of n integer
list create_list_of_n_integer(int n){
    list t = init();
    int a;
    for(int i=0; i < n; i++){
        printf("Enter the new integer element: ");
        scanf("%d", &a);
        insert(&t, a);
    }
    return t;
}

//create a list of integer and insert him the integer while user don't write -1
list create_list_integer(){
    printf("[ Enter -1 if you want to stop the list ]\n"  );
    list t = init();
    int a;
    do{
        printf("Enter the new integer element: ");
        scanf("%d", &a);
        if(a != -1)
        insert(&t, a);
    }while(a != -1);
    return t;
}

//search any element in the list
void search_element(list l, int value){
    list iterator = l;
    while(iterator != NULL && iterator->value != value)
        iterator = iterator->next;

    if(iterator == NULL){
        printf("Element [%d] not found.\n", value);
    }
    else{
        printf("Element [%d] found.\n", value);
    }
}

//search the last occurence of any element in the list
void search_last_occurence(list l, int value){
    list iterator = l;
    int pos = -1;
    int i = 1;
    while(iterator != NULL){
        if(iterator->value == value)
            pos = i;
        iterator = iterator->next;
        i++;
    }

    if( pos == -1){
        printf("Element [%d] not found.\n", value);
    }
    else{
        printf("Element [%d] found and the last occurence is at the position [%d].\n", value, pos);
    }

}

/*
  DELETE FUNCTION
*/
void delete_first_element(list *l){
    if(*l != NULL){
        list element = *l;
        *l = (*l)->next;
        element->next = NULL;
        free(element);
    }
}

void delete_first_occurence(list *l, int value){
    if(*l != NULL){
        list element = *l;
        if((*l)->value == value){
            *l = (*l)->next;
            element->next = NULL;
            free(element);
        }
        else{
            list iterator = (*l)->next;
            list prec = (*l);
            while(iterator != NULL && iterator->value != value){
                prec = iterator;
                iterator = iterator->next;
            }
            if(iterator != NULL){
                element = iterator;
                prec->next = iterator->next;
                element->next = NULL;
                free(element);
            }
        }
    }
}

void delete_all_occurence(list *l, int value){
    if(*l != NULL){
        list iterator = *l;
        list prec = *l;
        while(iterator != NULL){
            if(iterator->value == value){
                if(iterator != *l){
                    list element = iterator;
                    prec->next = iterator->next;
                    element->next = NULL;
                    iterator = prec->next;
                    free(element);
                }
                else{
                    list element = *l;
                    *l = (*l)->next;
                    element->next = NULL;
                    free(element);
                    iterator = *l;
                    prec = *l;
                }
            }else{
                prec = iterator;
                iterator = iterator->next;
            }
        }
    }
}


/*
    double linked list
*/
d_list create_d_list(){
    printf("[ Enter -1 if you want to stop the list ]\n"  );
    d_list l = NULL;
    d_list last = l;
    int a;
    do{
    printf("Enter the value: ");
    scanf("%d", &a);
    if(a != -1){
        d_list t = (d_list)malloc(sizeof(struct d_cellule));
        t->next = NULL;
        t->previous = NULL;
        t->value = a;
        if(l == NULL){
            l = t;
            last = l;
        }else{
            last->next = t;
            t->previous = last;
            last = t;
        }
    }
  }while(a != -1);

  return l;
}

void display_d_list_order_typing(d_list l){
    if(l == NULL){
        printf("[]\n");
    }
    else{
        d_list iterator = l;
            printf("[");
        while(iterator != NULL){
            printf("%d, ", iterator->value);
            iterator = iterator->next;
        }
        printf("\b\b]\n");
    }

}


void display_d_list_inverse_order_typing(d_list l){
    if(l == NULL){
        printf("[]\n");
    }else{
        d_list iterator = l;
        while(iterator->next != NULL)
            iterator = iterator->next;

        printf("[");
        while(iterator != NULL){
            printf("%d, ", iterator->value);
            iterator = iterator->previous;
        }
        printf("\b\b]\n");
    }
}
