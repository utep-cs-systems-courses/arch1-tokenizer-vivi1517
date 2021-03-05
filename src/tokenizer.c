#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == ' ' | c == '\t' | c == '\n') {
      return 1;
  }
  else return 0;
  
}

int non_space_char(char c)
{
  if (c != ' ' & c != '\t' & c != '\n') {
    return 1;
  }
  else return 0;
}

char *word_start(char *str)
{
  while (space_char(*str) > 0){
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while (non_space_char(*word) > 0){
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int total = 0;
  //copy of string
  char *p = str;
  
  while(p){
    p = word_start(p);
    //If the next char is the zero terminator then break
    if (*p++ == '\0') break;
    p = word_terminator(p);
    total++;
   
  }

  return total;
}

char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *copy = malloc(sizeof(char) * (len + 1));
  for (i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[i] = 0;
  return copy;
}

char **tokenize(char* str){
  //count words
  int total = count_words(str);
  char **tokens = malloc((total + 1) * sizeof(char*));

  for (int i = 0; i < total; i++){
    if (space_char(str[0])) {
	str = word_start(str);
    }
      int length = word_terminator(str) - word_start(str);
      tokens[i] = copy_str(str, length);
      str = word_start(word_terminator(str));
  }
  return tokens;
}

void print_tokens(char **tokens)
{
  while (tokens && (*tokens != NULL)){
    printf("%s\n", *tokens);
    tokens++;
  }
}

void free_tokens(char **tokens)
{
  char **p = tokens;
  char **iter = tokens;
  while (*p != NULL){
    p = iter;
    iter++;
    free(p);
  }
  free(iter);
  free(tokens);
}

int string_compare(char str[], char str2[]){
  while (*str != '\0' || *str2 != '\0'){
    if (*str == *str2){
      return 1;
    }
    else{
      return 0;
    }
  }
}
