#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "tree_node.h"
#include <string.h>
#include <stdbool.h>

bool tree_contains(tree_node* root, char* s);//helper function for map_contains
void tree_get_keys(tree_node* root,int n, char* keys[n]);//helper for map_get_keys
typedef struct map_record{
  tree_node* root;
}map_record;

int main(){
  
  return 0;
}

map map_new(){
  map new_map;
  new_map->root = NULL;

  return new_map;
}

int map_size(map m){
  return (size(m->root));
}

tree_node* find_node(tree_node* root, char* key){
  if(root){
    //imagine it as root->key == key
    if(strcmp(root->key, key) == 0)
      return root;
    else if(strcmp(root->key, key) > 0)
      return find_node(root->left,key);
    else
      return find_node(root->right,key);
  }
  return NULL;
}

bool map_contains( map m, char* s){
  tree_node* root = m->root;
  return tree_contains(root, s);
}
/*
//--should use find_node which will return the node if we find that node and NULL if not
bool tree_contains(tree_node* root, char* s){
  if(root){
    if(strcmp(root->key,s) == true)
      return true;
    tree_contains(root->left,s);
    tree_contains(root->right,s);
  }

  return false;
}
*/
void map_get_keys(map m, char* keys[map_size(m)]){
  tree_node* root = m->root;
  int size = map_size(m);
  tree_get_keys(root,size,keys);
}
//helper function of map_get_keys
void tree_get_keys(tree_node* root,int n, char* keys[n]){
  //use char*** to keep track of the elements in keys(update them)
  if(root){
    char*** tracker = &keys;
    tree_get_keys(root->left,n,keys);
    **tracker = root->key;
    tracker++;
    tree_get_keys(root->right,n, keys);
  }
}
