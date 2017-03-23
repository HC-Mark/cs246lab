/* llist_node.c

   A singly-linked list implementation
*/

#include <stdlib.h>

#include "llist_node.h"

// create (i.e., malloc) a new node
llist_node* new_node(int data, llist_node* next)
{
  llist_node* n = malloc(sizeof(llist_node));
  n->data = data;
  n->next = next;
  return n;
}

// insert a new node after the given one
// Precondition: Supplied node is not NULL.
void insert_after(llist_node* n, int data)
{
  n->next = new_node(data, n->next);
}

// delete the node after the given one
// Precondition: Supplied node is not NULL.
void delete_after(llist_node* n)
{
  llist_node* delendum = n->next;
  n->next = n->next->next;
  free(delendum);
}

// return a pointer to the nth node in the list. If n is
// the length of the list, this returns NULL, but does not error.
// Precondition: the list has at least n nodes
llist_node* nth_node(llist_node* head, int n)
{
  for( ; n > 0; n--, head = head->next)
    ;
  return head;
}

// free an entire linked list. The list might be empty.
void free_llist(llist_node* head)
{
  llist_node* cur = head;
  while(cur)
  {
    head = cur;
    cur = cur->next;
    free(head);
  }
}
//reverse the linked list. The first element of original list will be last in the new linked list.
llist_node* reverse_llist(llist_node* head){
  
  llist_node* pre = NULL;
  if( head == NULL)
    return NULL;
  llist_node* cur = head;
  if( head->next == NULL)
    return head;
  llist_node* adv = head->next;

  while(adv->next != NULL){
    cur->next = pre;
    pre = cur;
    cur = adv;
    adv = adv -> next;
  }

  cur->next = pre;
  adv->next = cur;

  head = adv;
  return head;
  
}

// create a linked list that stores the same elements as the given array.
// Postcondition: returns the head element
llist_node* from_array(int n, int a[n])
{
  llist_node* result = NULL;
  for(int i = n-1; i >= 0; i--)
  {
    result = new_node(a[i], result);
  }
  return result;
}

// fill in the given array with the elements from the list.
// Returns the number of elements filled in.
// Postcondition: if n is returned, the first n elements of the array
// have been copied from the linked list
int to_array(llist_node* head, int n, int a[n])
{
  int i;
  for(i = 0; i < n && head; i++, head = head->next)
  {
    a[i] = head->data;
  }
  return i;
}

// gets the length of a list
int length(llist_node* head)
{
  int len = 0;
  for( ; head; head = head->next, len++)
    ;
  return len;
}
