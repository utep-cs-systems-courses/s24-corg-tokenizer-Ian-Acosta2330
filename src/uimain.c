#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char c[100];
  char *str;
  char **tokens=(char**)malloc(100*sizeof(char*));
  List *l = init_history();
  printf("Input strings (Enter empty string if done):\n");
  do{
    printf("$ ");
    fgets(c, sizeof(c), stdin);
    str = c;
    if(c[0] == '\n') {break;}
    //printf("%s", str);
    tokens = tokenize(str);
    //print_tokens(tokens);
    for(int i = 0 ; i < count_tokens(str); i++) {
      add_history(l,tokens[i]);
    }
  }while(c[0]!='\n');

  // Zero-indexed
  printf("Get history? Enter ID | (Enter empty string if done):\n");
  printf("Print Everything? Press \'h\'\n");

  char his[100];
  int id;
  while(his[0] !='\n'){
    printf("> ");
    fgets(his,sizeof(his), stdin);
    if(his[0]=='\n') { break; }
    switch(his[0]){
    case'H':
    case 'h':
      print_history(l);
      break;
    default:
      id = atoi(his);
      printf("The selected ID: %d is -> %s\n", id, get_history(l,id));
      break;
    }
  }
  
  free_tokens(tokens);
  
  return 0;
  
}
