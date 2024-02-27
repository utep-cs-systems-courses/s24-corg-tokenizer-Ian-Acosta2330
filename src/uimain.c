#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char c[100];
  
  printf("$ ");
  fgets(c, sizeof(c), stdin);
  printf("%s", c);
}
