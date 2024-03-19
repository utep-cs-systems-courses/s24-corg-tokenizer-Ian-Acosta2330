#include "history.h"
#include "stdio.h"
#include "stdlib.h"

List* init_history() {
  List *li =(List*)malloc(sizeof(List));
  li->root = NULL;
  return li; 
}

void add_history(List *list, char *str) {
  Item *tempItem = (Item*)malloc(sizeof(Item));
  if(list->root == NULL) {
    list->root = str;
  }
  list->tempItem = str;
}

char *get_history(List *list, int id) {
  // return list->id;
}

void print_history(List *list) {
  // while(list!=NULL) {
    // printf("%s\n", list->str);
    //}
}

void free_history(List *list){
  free(list);
}

int main() {
  // s_List *l;
  //l = init_history();
}
