#include "history.h"
#include "stdio.h"
#include "stdlib.h"
//#include "tester.c"

List* init_history() {
  List *li =(List*)malloc(sizeof(List));
  li->root = NULL;
  return li; 
}

void add_history(List *list, char *str) {
  //  printf("\nCalling add_history");
  Item *tempItem = (Item*)malloc(sizeof(Item));
  Item *temp = list->root;
  int id = 0;
  tempItem->str = str;
  if(list->root == NULL) {
    //printf("\nRoot is null");
    tempItem->next = NULL;
    tempItem->id = id;
    list->root = tempItem;
    //list->root->next = NULL;
    // list->root = str;
  } else {
    id++;
    while(temp->next != NULL) {
      // printf("\nRoot is not null\n");
      if(temp->next == NULL) {
	break;
      }
      temp = temp->next;
      id++;
      // printf("\nId: %d", id);
    }
    //printf("Out of while");
    tempItem->next = NULL;
    tempItem->id = id;
    temp->next = tempItem;
    //tempItem->str = str;
  }
  // tempItem->str = str;
  //tempItem->id = id;
}

char *get_history(List *list, int id) {
  // printf("\nCalling get history");
  Item *temp = list->root;
  while(temp != NULL) {
    if(temp->id == id) { return temp->str; }
    else { temp = temp->next; }
   }
  return "n/a";
}

void print_history(List *list) {
  // printf("\nCalling print history");
  Item *temp = list->root;
  while(temp != NULL) {
    // printf("\nIn the loop ");
    printf("ID: %d, String: %s\n",temp->id,temp->str);
    temp = temp->next;
  }  
}

void free_history(List *list){
  Item *temp = list->root;
  while(temp != NULL){
    free(list->root);
    temp=temp->next;
    list->root = list->root->next;
  }
  free(list);
}
