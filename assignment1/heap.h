typedef struct heap Heap;

// returns a pointer to a new, empty heap with a capacity for max_size items
Heap *new_heap(int max_size);

// inserts data into h with priotiry key
void heap_insert(Heap *h, float key, void *data);

// remove and return the item with the smallest key in h
void *heap_remove_min(Heap *h);

// return, but not remove, the item with the smallest key in h
void *heap_peek_min(Heap *h);

// return the key of the item with the smallest key in h
float heap_peek_key(Heap *h);

// de-allocate all memory used by h
void free_heap(Heap *h);

// NEW FUNCTIONS
// not found in workshop solutions

// return the number of items currently in heap h
int heap_size(Heap *h);

// return the maximum number of items heap h can store
int heap_max_size(Heap *h);
