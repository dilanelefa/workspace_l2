#include <stdio.h>
#include <stdlib.h>

#include "function.h"


int main(){
  // int n;
  // list t = create_list_integer();
  // system("clear");
  // printf("\nEnter the element that you search: ");
  // scanf("%d", &n);
  // search_element(t, n
  int choice,n;
  list l;
  d_list dl;
  do{

    system("clear || cls");

    printf("+-----------------------------------------------------------------+\n");
    printf("|                    LINKED LIST PROGRAM                          |\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("Select one option\n");
    printf("\n[ CREATING A LINKED LIST ]\n");
    printf("---------------------------------------------\n\n");
    printf("\t1. Create a list of two integer;\n");
    printf("\t2. Create a list of n integer;\n");
    printf("\t3. Create a list (stop with -1);\n");
    printf("\n[ SEARCH AN ELEMENT IN THE LINKED LIST ]\n");
    printf("----------------------------------------------\n\n");
    printf("\t4. Search the integer\n");
    printf("\t5. Search the last occurence of an element\n");
    printf("\n[ DELETE IN THE LINKED LIST ]\n");
    printf("----------------------------------------------\n\n");
    printf("\t6. Delete the first element of a list\n");
    printf("\t7. Delete first occurence of an element\n");
    printf("\t8. Delete all occurence of an element\n");
    printf("\n[ DOUBLE  LINKED LIST ]\n");
    printf("----------------------------------------------\n\n");
    printf("\t9. Create the double linked list\n");
    printf("\t10. Display double list in the order of typing\n");
    printf("\t11. Display double list in the inverse order of typing\n");
    printf("\n[ 0. EXIT ]\n");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice != 0)
      system("clear || cls");
    switch (choice) {
      case 1:
        l = create_list_of_two_integer();
        display(l);
        break;

      case 2:
        printf("Enter n: ");
        scanf("%d", &n);
        l = create_list_of_n_integer(n);
        display(l);
        break;

      case 3:
        l = create_list_integer();
        display(l);
        break;

      case 4:
        printf("Enter the element that you want search: ");
        scanf("%d", &n);
        search_element(l, n);
        break;

      case 5:
        printf("Enter the element that you want search: ");
        scanf("%d", &n);
        search_last_occurence(l, n);
        break;

        case 6:
          printf("Before: ");
          display(l);
          delete_first_element(&l);
          printf("After : ");
          display(l);
          break;

        case 7:
          printf("Enter the element that you want to delete: ");
          scanf("%d", &n);
          printf("\nBefore: ");
          display(l);
          delete_first_occurence(&l, n);
          printf("After : ");
          display(l);
          break;

        case 8:
          printf("Enter the element that you want to delete: ");
          scanf("%d", &n);
          printf("\nBefore: ");
          display(l);
          delete_all_occurence(&l, n);
          printf("After : ");
          display(l);
          break;

        case 9:
          dl = create_d_list();
          break;
          
        case 10:
          printf("Display the list in order of typing\n");
          display_d_list_order_typing(dl);
          break;

        case 11:
          printf("Displat the list in inverse order of typing\n");
          display_d_list_inverse_order_typing(dl);
          break;

      default:
        choice = 0;
        printf("Good bye.....\n");
    }
    if(choice != 0){
      getchar();
      printf("\n[PRESS ANY KEY TO BACK TO MENU] ");
      getchar();
    }
  }while( choice != 0);

  return 0;
}
