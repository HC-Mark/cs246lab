/* tree_node.h

   Prototypes of functions for working with binary tree nodes.
*/

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

typedef struct tree_node {
  // these are the data in each node
  char* key;
  int value;
  
  struct tree_node* left;
  struct tree_node* right;
} tree_node;

// create (i.e., malloc) a new node
tree_node* new_node(char* key, int value, tree_node* left, tree_node* right);

// free all nodes in a binary tree. Does not free any strings.
void free_tree(tree_node* root);

// returns the number of nodes in the tree
int size(tree_node* root);

// prints out all (string, int) pairs in the tree, doing an inorder traversal
void inorder(tree_node* root);

// gets the height of the tree. That is, this returns the maximum number
// of nodes to get from the root to a leaf. An empty tree has height 0,
// whereas a tree with one node as a height of 1.
int height(tree_node* root);

#endif
