#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char word[2];
  char str[100];
  List *list = init_history();

  while (1){
    printf("--------MENU--------\n");
    printf("a. Tokenizer\n");
    printf("b. Print History\n");
    printf("q. Quit\n");
    // fpurge(stdin);
    fgets(word, 100, stdin);
    printf("You entered: %s\n", word);
    if (string_compare(word, "a") == 1){
      printf("Enter String: \n");
      printf(">");
      fgets(str, 100, stdin);
      printf("\n");
      char **tokens = tokenize(str);
      add_history(list, str);
      print_tokens(tokens);
      printf("\n");
      free_tokens(tokens);
    }
    else if (string_compare(word, "b") == 1){
      char hist[3];
      printf("--------HISTORY--------\n");
      printf("Enter id or type 'a' for all history\n");
      printf(">");
      fgets(hist, 3, stdin);
      printf("You entered: %s\n", hist);
      if (string_compare(hist, "a") == 1){
	print_history(list);
	printf("\n");
      }
      else{
	char ID = hist[1];
	int id_num = ID - '0';
	char *p = get_history(list, id_num);
	printf("%d. %s\n", id_num, p);
      }
     
    }
    else if (string_compare(word, "q") == 1){
      printf("Ending session\n");
      goto done;
    }
  }
 done:
  free_history(list);
  return 0;
}
