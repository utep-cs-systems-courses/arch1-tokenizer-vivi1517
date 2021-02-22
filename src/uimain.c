#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char word[100];
  printf("$ Enter your word \n");
  fgets(word, 100, stdin);
  printf("%s\n", word);

  printf("Number of words: %d\n", count_words(word));
  return 0;
}
