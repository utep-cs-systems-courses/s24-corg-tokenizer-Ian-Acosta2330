#include <stdio.h>

int main(){
  char c[100];
  printf("$ ");
  scanf("%[^\n]s", c);
  printf("%s\n", c);
}
