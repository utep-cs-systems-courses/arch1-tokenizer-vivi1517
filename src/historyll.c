#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


List* init_history(){
  List *history_list = malloc(sizeof(List));
  history_list->root = malloc(sizeof(Item));
  return history_list;
}

void add_history(List *list, char *str){
  Item *temp = list->root;
  if (list->root == NULL){
    temp->id = 1;
    temp->str = str;
    list->root = temp;
  }
  else{
    int counter = 1;
    while (temp->next != NULL){
      counter++;
      temp = temp->next;
    }
    short len = get_length(str);
    temp->str = (copy_str(str, len + 1));
    temp->id = counter;
    temp->next = malloc(sizeof(Item));
  }
}

int get_length(char *str){
  char *beg = str;
  char *end = str;
  while (end){
    if (*end++ == '\0') break;
    end++;
  }
  return end - beg;
}

char *get_history(List *list, int id){
  Item *temp = list->root;
  char *p = temp->str;
  int count = 1;
  while (count != id) {
    temp = temp->next;
    p = temp->str;
    count++;
  }
  return p;
}

void print_history(List *list){
  Item *temp = list->root;
  while (temp->next != NULL){
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  Item *temp =list->root;
  Item *iter = list->root;
  while(list != NULL){
    temp = list->root;
    iter = temp->next;
    free(temp);
  }
  free(list);
}
