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
  while(*str) {
    if(space_char(*str)) {
      str++;
    }
    else {
      // printf("%c\n", *str);
      return str;
    }
  }
  return 0;
      //printf("%c\n", *s); Outputs individual characters of string
      //printf("%d\n",*s); Outputs ascii of char
      //return &*s;
}
char *token_terminator(char *token) {
  while(*token) {
    if(non_space_char(*token)){
      //printf("%c\n", *token);
      token++;
    } else {
      return token;
    }
  }
  return NULL;
}

int count_tokens(char *str) {
  char *s;
  char *t;
  
  int count = 0;
  
  while(*str) {
    s = token_start(str);
    //printf("%c\n", *s);
    t = token_terminator(s);
    //printf("%d\n", space_char(*t));
    if( !(s==0) ) {
      count++;
    }
    // printf("%d\n",count);
    if(t==NULL) {
      return count;
    }
    str=t;
  }
}
char *copy_str(char *inStr, short len);

char **tokenize(char* str);

void print_tokens(char **tokens);

void free_tokens(char **tokens);

int main() {
  char c = ' ';
  char *str = "He llo asb";
  printf("%d\n", space_char(c));// 1 = True | 0 = False
  printf("%d\n", non_space_char(c));//1 -> NOT a space, 0->IS a space
  printf("%p\n", token_start(str));// Returns pointer of space
  printf("%p\n", token_terminator(token_start(str)));
  printf("%d\n", count_tokens(str));
  
}
