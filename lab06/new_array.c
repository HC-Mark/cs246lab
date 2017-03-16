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
  int* mem = arr->mem;//arr->size = *arr.size
  //if the current array is full, we will create a new one with 2* size
  if(arr->num_elements == arr->size){
    int* new_arr = malloc(arr->size * 2);

    for(int i =0; i < arr->size; i++){
      new_arr[i] = mem[i];
    }

    arr->size *= 2;
    free(arr->mem);
    mem = new_arr;
    arr->mem = new_arr;
  }
  //if the current array can still hold the new_elt
  //here we have num_elements help us keep track of the total number of elements
  //therefore we don't actually need to test which we should put
  /*
  for (int i=0; i < arr->size; i++ ){
    if(*mem == 0){
      *mem = new_elt;
      break;
    }
    if (*p != 0){
      *(p+1) = new_elt;
      break;
    }
    else{
      p--;
    }
  }
  */
  mem[arr->num_elements++] = new_elt;
  arr->num_elements += 1;
}

// access an element in the array. Returns -1 if the index is out of range.
int get(array* arr, int index);
int get(array* arr, int index){
  return *(arr->mem + index);
}

// change an element in the array. Returns the old element if the index is
// in range, or -1 otherwise
int set(array* arr, int index, int new_val);

// remove an element from the array, shifting rightward elements to the left
void remove_elements(array* arr, int index);

// returns the number of elements in an array
int num_elements(array* arr);

// release the memory used for this array (but not the array structure itself)
void free_array(array* arr);

// (a bit harder)
// adds an element at the given (non-negative) index, enlarging the array
// and shifting elements to the right to make it fit
void add_element_at(array* arr, int index, int new_elt);

int main() {
  array a = new_array();
  // *(a.mem + 3) = 3;
  #ifdef TEST
  for(int i = 0; i < 10; i++){
    add_element(&a,5);
   }
  #endif
  for(int i = 0; i< a.size; i++){
    printf("number in array a: %d\n", get(&a,i));
  }
  return 0;
}
