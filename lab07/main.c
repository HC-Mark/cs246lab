#include "llist_node.h"
#include <stdlib.h>
#include <stdio.h>
#define TOTAL
int game (int children, int number);
llist_node* set_up (int children);
void play(llist_node* head, int number);

int main (){
  #ifdef TEST
  llist_node* test = set_up(7);
  //int test1 = length(test);
  for( int i =0; i < 7; i++){
  printf("the element in test is %d\n", test->data);
  test = test->next;
  }
  #endif

  #ifdef TOTAL
  int children, number;
  printf("Enter how many children you want: \n");
  scanf("%d",&children);

  printf("Enter what's the score you want: \n");
  scanf("%d", &number);

  int winner;
  winner = game(children, number);

  printf("the winner is children %d\n", winner);
  #endif

  return 0;
}

int game (int children, int number){
  llist_node* head = set_up(children);

  play(head,number);

  int winner = head->data;
  free_llist(head);
  return winner;
}

llist_node* set_up(int children){
  llist_node* head;

  for(int i = 0; i < children; i++){
    head = new_node(i, head);
  }
  llist_node* last = nth_node(head, (children -1));
  last->next = head;

  return head;
}

void play(llist_node* head, int number){
  llist_node* tracker = head;
  while(head->next != NULL){
    int counter = number;
    while(counter > 1){
      tracker = tracker -> next;
      counter --;
    }
    delete_after(tracker);
    tracker = tracker -> next;
  }
}

