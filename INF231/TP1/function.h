/*
  NOM: LEFAKONG TSOMELOU Vignol Dilane
  MATRICULE: 22T2966
*/
#ifndef __FUNCTION_H__
#define __FUNCTION_H__

//defination of list
typedef struct cellule *list;

struct cellule{
  int value;
  list next;
};


///date de naissance: 17 janvier 2005
typedef  struct d_cellule *d_list;

struct d_cellule{
    d_list previous;
    int value;
    d_list next;
};

//defination of operaions


list init();
void insert(list *l, int value);
void display(list l);

//1: Creating a linked list
list create_list_of_two_integer();
list create_list_of_n_integer(int n);
list create_list_integer();

//2: Search a element in the linked list
void search_element(list l, int value);
void search_last_occurence(list l, int value);

//3: delete in the linked list
void delete_first_element(list *l);
void delete_first_occurence(list *l, int value);
void delete_all_occurence(list *l, int value);

//4: double linked list
d_list create_d_list();
void display_d_list_order_typing(d_list l);
void display_d_list_inverse_order_typing(d_list l);
#endif
