# Collation of the wrong Answer in Weekly Quiz

##  Week 2: Complexity & Arrays

### Question 12
An Abstract Data Type:
a. Defines what the data type can do (its behaviour).
b. Defines what the data type can do (its behaviour) and how it is implemented.
c. Can have multiple different underlying implementations.
d. Both (a) and (c)

My Answer : (a)
The correct answer is **(d)**.

_FeedBack_: An Abstract Data Type (such as a Dictionary) describes the **functionality** of the type (such insertion, deletion, modification, and lookup of an item) but **not its underlying implementation**. ***A Dictionary can be implemented using a range of concrete data structures***, including hash tables and trees.


## Week 3: Dynamic Memory Allocation, Linked Lists, and Binary Search Trees

### Question 1
Which of the following statements about dynamic memory allocation in C are true?[multiple selected]
a. The function malloc returns a pointer to a place in memory.
b. The function malloc allocates the specified number of bytes and initialises them to zero.
c. The argument to malloc specifies how much space to reserve in memory.
d. The function calloc initialises all bytes of the allocated memory block to zero.
e. Freeing all dynamically allocated memory with free is good practice but optional.

My Answer : (d)
The correct answer is **(a),(c),(d)**.

_FeedBack_: Statement (b) is false as malloc does not initialise allocated blocks of memory to zero. Statement (e) is false as all dynamically allocated memory must be freed once it is no longer needed. Not doing so impairs program performance and may lead to program failures when no further memory can be allocated.

### Question 3
Which of the following statements about linked lists are true?
a. A linked list is a sequence of nodes where each node n contains a pointer to the next node in the sequence.
b. Linked lists use less memory than arrays when used to store the same set of data items.
c. Inserting or deleting an item in a linked list (once the insertion point or item to be deleted is located) is achieved by rearranging links.
d. A linked list supports random access to its items, just like arrays.

My Answer : (a),(b),(c)
The correct answer is **(a),(c)**.
_FeedBack_: **Statement (b) is false as linked lists use more memory than arrays as they must store pointers linking each node to the next node in the list.** Statement (d) is false as linked lists support **sequential**, rather than random, access. This means that to access the kth item in the list, we must step through the list (following each pointer) until we reach the kth item. In contrast, arrays support random access. This means that we can access the kth item of an array A directly (for example, using A[k]). When deleting a node n from a linked list, it is important to note that we not only need a pointer to the node to be deleted, but also to its predecessor (the node immediately before it in the list). This predecessor must then be altered to point to the node just after n in the sequence.  
