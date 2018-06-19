#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "heap.h"

// Data Structures

typedef struct item{
    float key;   // the key for deciding position in heap
    void* data;  /* (void *) 类型的指针是有指向的指针，但它的指向的数据的类型
                  时不确定，所以先弄成void * 类型，后期一般要强制转换的 */
} HeapItem;

struct heap{
  HeapItem *items;   // 底层数组
  int cur_size;   // the number of items currently in the heap
  int max_size;   // the maximum number of items allowed in the heap
}

//HELPER FUNCTION

// swap two heap items (the items at index i and index j)
// assume h NOT NULL

void swap(Heap *h, int i, int j){
  HeapItem t = h->items[i];
  h->items[i] = h->items[j];
  h->items[j] = t;
}

// find the index of the smallest child among the children of an item
// if the item has no chirld return 0
// assume h != NULL
int min_child(Heap *h, int i){
  int child = 2 * i + 1;     //left child
  // no children
  if(child >= h->cur_size) return 0;
  // only child or first child is smallest child
  else if(child + 1 >= h->cur_size || h->items[child].key < h->items[child+1].key){
    return child;
  }
  // second child exists and is smallest child
  else{
    return child+1;
  }
}

// move an item up the heap structure to re-establish heap order
// assumes h != NULL
void sift_up(Heap *h, int i){
  int parent = (i-1) / 2;
  while(h->items[i].key < h->items[parent].key){
    swap(h, parent, i);
    i = parent;
    parent = (i-1)/2
  }
}

// move an item down the heap structure to re-establish heap order
// assumes h != NULL
void sift_down(Heap *h, int index){
  int child = min_child(h, index);
  while(child && h->items[index].key < h->items[child].key){
    swap(h, child, index);
    index = child;
    child = min_child(h, index);
  }
}

// MODULE FUNCTIONS

// returns a pointer to a new, empty heap with a capacity for maximum_size items
Heap *new_heap(int max_size){
  Heap *h = malloc(sizeof(* h));
  assert(h);

  h->items = malloc(max_size * sizeof(* h->items));
  assert(h->items);

  h->cur_size = 0;
  h->max_size = max_size;

  return h;
}

// remove and return the item with the smallst key in h
void *heap_remove_min(Heap *h){
  assert(h != NULL);
  assert(h->cur_size != 0);

  void * min = h->items[0].data;

  h->items[0] = h->items[h->cur_size-1];
  h->cur_size -= 1;
  sift_down(h, 0);

  return min;
}


// return, but not remove, the item with the smallest key in h
void *heap_peak_min(Heap *h){
  assert(h != NULL);
  assert(h->cur_size != 0);

  return h->items[0].data;
}

// return the key of the item with the smallest key in h
float heap_peak_key(Heap *h){
  assert(h != NULL);
  assert(h->cur_size != 0);

  return h->items[0].key;
}

// de-allocate a;; memory used by h
void free_heap(Heap *h){
  assert(h);

  free(h->items);
  free(h);
}


// NEW FUNCTIONS
// not found in workshop solutions

// return the number of items currently in heap h
int heap_size(Heap *h){
  assert(h != NULL);

  return h->cur_size;
}

// return the maxium number of items in heap h
int heap_size(Heap *h){
  assert(h != NULL);

  return h->max_size);
}
