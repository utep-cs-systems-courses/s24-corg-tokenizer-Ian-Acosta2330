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
  Item *temp = list->root;
  int id = 0;
  tempItem->id = id;
  tempItem->str = str;
  if(list->root == NULL) {
    printf("root is null\n");
    list->root = tempItem;
    tempItem->next = NULL;
    // list->root = str;
  } else {
    while(temp->next != NULL) {
      printf("Have yet to reach the end\n");
      temp = temp->next;
      id++;
    }
    temp->next = tempItem;
    tempItem->next = NULL;
  }
}

char *get_history(List *list, int id) {
  // return list->id;
  
}

void print_history(List *list) {
  printf("Calling print history\n");
  while(!(list->root == NULL)) {
    printf("\nIn the loop ");
    printf("%s\n", list->root->str);
    list->root = list->root->next;
  }
  
}

void free_history(List *list){
  free(list);
}

int main() {
  //  Item *i1 = (Item*)malloc(sizeof(Item));
  //  Item *i2 = (Item*)malloc(sizeof(Item));
  List *l;
  char *c = "abc"; 
  l = init_history();
  add_history(l,c);
  char *c1 = "dbe";
  add_history(l, c1);
  print_history(l);
}
