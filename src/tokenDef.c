#include "tokenizer.h"
#include <stdio.h>
#include "stdlib.h"

int space_char(char c) {
  if (c=='\t' || c==' '){  return 1; }
  return 0;
}

int non_space_char(char c) {
  if (space_char(c) == 0) {
    return 1;
  } else {
    return 0;
  }
}

char *token_start(char *str) {
  char *s;
  int x = 0; //0 if no Space, 1 if Space
  for (s=str; *s; s++) {
    if(non_space_char(*s)==0){
      //printf("%c\n", *s); Outputs individual characters of string
      //printf("%d\n",*s); Outputs ascii of char
      //return &*s;
      x = 1;
    }
  }
  if(x==1) {
    for(s=str;*s;s++) {
      if(non_space_char(*s)==1) {
	return &*s;
      }
    }
  }else {
    return 0;
  }
 
}
char *token_terminator(char *token) {
  
}

int count_tokens(char *str) {
  
}
char *copy_str(char *inStr, short len);

char **tokenize(char* str);

void print_tokens(char **tokens);

void free_tokens(char **tokens);

int main() {
  char c = ' ';
  char *str = "He llo";
  printf("%d\n", space_char(c));// 1 = True | 0 = False
  printf("%d\n", non_space_char(c));//1 -> NOT a space, 0->IS a space
  printf("%p\n", token_start(str));// Returns pointer of space
  // printf("%p\n", token_terminator());
  printf("%d\n", count_tokens(str));
}
