/* tree_noe.c

   Implements functions working with binary tree nodes.
*/

#include <stdlib.h>
#include <stdio.h>

#include "tree_node.h"

// create (i.e., malloc) a new node
tree_node* new_node(char* key, int value, tree_node* left, tree_node* right)
{
  tree_node* new = malloc(sizeof(tree_node));
  new->key = key;
  new->value = value;
  new->left = left;
  new->right = right;
  return new;
}

// free all nodes in a binary tree. Does not free any strings.
void free_tree(tree_node* root)
{
  if(root)
  {  
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// returns the number of nodes in the tree
int size(tree_node* root)
{
  if(root)
  {
    return 1 + size(root->left) + size(root->right);
  }
  else
  {
    return 0;
  }
}

// prints out all (string, int) pairs in the tree, doing an inorder traversal
void inorder(tree_node* root)
{
  if(root)
  {
    inorder(root->left);
    printf("(%s,%d)\n", root->key, root->value);
    inorder(root->right);
  }
}

// helper function
int max(int a, int b)
{
  return a > b ? a : b;
}

// gets the height of the tree. That is, this returns the maximum number
// of nodes to get from the root to a leaf. An empty tree has height 0,
// whereas a tree with one node as a height of 1.
int height(tree_node* root)
{
  if(root)
  {
    return 1 + max(height(root->left), height(root->right));
  }
  else
  {
    return 0;
  }
}
