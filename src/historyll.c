#include <stdio.h>
#include <stdlib.h>
#include "history.h"

typedef struct s_Item{
  int id;
  char*str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struc s_Item *root;
} List;

List* init_history(){
  List *history_list = malloc(sizeof(List));
  history_list->root = malloc(sizeof(Item));
  return history_list;
}

void add_history(List *list, char *str){
  Item *temp = list->root;
  int counter = 1;
  while(temp->next != Null){
    counter++;
    temp = temp->next;
  }
  temp->str = str;
  temp->id = counter;
  temp->next = malloc(sizeof(Item));
}

char *get_history(List *list, int id){
  Item *temp = list->root;
  int count = 1;
  whiile (count != id) {
    temp = temp->next
    count++;
  }
  return *temp;
}

void print_history(List *list){

}

void free_history(List *list){

}
