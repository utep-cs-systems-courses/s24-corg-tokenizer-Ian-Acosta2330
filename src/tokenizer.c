#include "tokenizer.h"
#include "stdio.h"
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
    if (t==NULL) {
      return count;
    }
    str=t;
  }
}
char *copy_str(char *inStr, short len) {
  char *newStr = (char *)malloc((len+1)*sizeof(char));
  if(newStr == NULL) {
    return NULL;
  }
  for(int i=0;i<len && inStr[i] != '\0';i++) {
    newStr[i] = inStr[i];
  }
  newStr[len]='\0';
  return newStr;
}

char **tokenize(char* str){
  char **tokensOfWord=(char**)malloc(100*sizeof(char*));
  if (tokensOfWord == NULL) { exit(1); }

  char *token;
  char *t;
  int i = 0;
  int lenStr;
  int token_count = count_tokens(str);
  while (i < token_count) {
    token = token_start(str);
    t = token_terminator(token);
    lenStr = 0;
    while (token[lenStr] !=' ') {
      lenStr++;
    }
    tokensOfWord[i] = (char *)malloc((lenStr+1)*sizeof(char));
    tokensOfWord[i] = copy_str(token, lenStr);
    str = t;
    i++;
  }
  tokensOfWord[token_count] = NULL;  
  return tokensOfWord;
}

void print_tokens(char **tokens) {
  for(int i = 0; tokens[i] != NULL; i++) {
     printf("%s", tokens[i]);\
     if(tokens[i+1] != NULL) { printf("\n");}
  }
}

void free_tokens(char **tokens) {
  for(int i = 0; tokens[i]!= NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

//little silly main to test out the methods
/*
int main() {
  char c = ' ';
  char *str = "this is h ell";
  printf("%d\n", space_char(c));// 1 = True | 0 = False
  printf("%d\n", non_space_char(c));//1 -> NOT a space, 0->IS a space
  printf("%p\n", token_start(str));// Returns pointer of first non_space char
  printf("%p\n", token_terminator(token_start(str)));//Returns pointer of space of token ' '
  printf("%d\n", count_tokens(str));// Counts the tokens! :D

  int length = 6;
  char *newStr = copy_str(str,length);
  printf("CopyTest method: %s\n", newStr);//Returns pointer to terminated copy of passed str
  char **tokensOfWord = tokenize(str);

  print_tokens(tokensOfWord);
  free_tokens(tokensOfWord);
  free(newStr);
  
  return 0;
}*/
