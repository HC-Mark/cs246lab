#include <stdlib.h>
#include <stdio.h>

#define INITIAL_SIZE 10
#define TEST
typedef struct array {
  int* mem;  	      // the memory
  int size;  	      // the size of the memory region
  int num_elements;   // the actual number of elements (<= size)
} array;

// create a new, empty array, with an initial size of 10 but no elements
array new_array();
array new_array(){
  array a;
  a.mem = malloc(sizeof(int) * INITIAL_SIZE);
  a.size = INITIAL_SIZE;
  a.num_elements = 0;

  return a;
}

// add a new element to the end of the array
void add_element(array* arr, int new_elt);
void add_element(array* arr, int new_elt){
  int* mem = arr->mem;
  int size = arr->size;
  int num_elements = arr -> num_elements;

  if(num_elements == size){
    int* new_mem = malloc(sizeof(int) * size *2);//here, it is not just simply make size *2
    //since malloc need the bits of each type to save specific space for array

    for(int i =0; i < size; i++){
      new_mem[i] = mem[i];
    }

    size *= 2;
    arr->size = size;
    free(arr->mem);
    arr->mem = new_mem;
    mem = new_mem;
  }

  mem[num_elements] = new_elt;
  arr-> num_elements++;
}

// access an element in the array. Returns -1 if the index is out of range.
int get(array* arr, int index);
int get(array* arr, int index){
  return *(arr->mem + index);
}

// change an element in the array. Returns the old element if the index is
// in range, or -1 otherwise
int set(array* arr, int index, int new_val);
int set(array* arr, int index, int new_val){
  int size = arr-> size;
  if ( index > size)
    return -1;

  int old;
  int* mem = arr -> mem;
  old = *(mem + index);
  *(mem + index) = new_val;

  return old;
  
}

// remove an element from the array, shifting rightward elements to the left
void remove_elements(array* arr, int index){
  int size = arr-> size;
  int* mem = arr -> mem;
  for(int i = index;i < size; i++){
    if(i == size - 1){
      *(mem+i) = 0;
    }
    else{
    *(mem + i) = *(mem + i +1);
    }
  }
  
}

// returns the number of elements in an array
int num_elements(array* arr){

  return arr->num_elements;

}

// release the memory used for this array (but not the array structure itself)
void free_array(array* arr){
  free(arr->mem);

}

// (a bit harder)
// adds an element at the given (non-negative) index, enlarging the array
// and shifting elements to the right to make it fit
void add_element_at(array* arr, int index, int new_elt){
  if(index <0)
    return;
  int size = arr->size;
  int num_elements = arr->num_elements;
  int* mem = arr->mem;

  if(num_elements == size){
    int* new_mem = malloc(sizeof(int) * size * 2);

    for(int i = 0; i < size; i++){
      new_mem [i] = mem[i];
    }

    size *= 2;
    arr->size = size;
    free(arr->mem);
    mem = new_mem;
    arr->mem = new_mem;
  }

  for(int i = size ; i > index; i--){
    *(mem + i) = *(mem + i -1);
  }

  *(mem + index) = new_elt;
}

int main() {
  array a = new_array();
  // *(a.mem + 3) = 3;
  #ifdef TEST
  for(int i = 0; i < 30; i++){
    add_element(&a,2 * i);
   }
  //though remove method works, the following loop can not remove all contents in array a
  /*
  for(int i = 0; i< a.size; i++){
    remove_elements(&a,i);
  }
  */
  add_element_at(&a,5,1029);
  for(int i = 0; i < a.size; i++){
  printf("number in array a: %d\n", get(&a,i));
  }
  printf("there are %d elements in array.\n", num_elements(&a));
  //free_array(&a);
  #endif
  return 0;
}
