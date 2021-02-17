#include <stdio.h>
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

char word_start(char *str)
{
  while (*str == ' ' | *str == '\t' | *str == '\n'){
    *str++;
  }
  return *str;
}

char *word_terminator(char *word)
{
  while (*word != ' ' | *word != '\t' | *word != '\n'){
    *word++;
  }
  return *word;
}

int count_words(char *str)
{
  int total = 0;
  while (*str == ' '){
    *str++;
  }
  return 0;
}
