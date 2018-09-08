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

### Question 5
The items stored in a linked list are located in a contiguous block of memory.  
a. true  
b. false  

My Answer : (a)  
The correct answer is **(b)**.  

_FeedBack_: Nodes in linked lists are not stored in contiguous blocks of memory. This is the reason why each node contains a pointer to the next node in the list. These pointers provide links across the different memory locations used to store list items. Arrays, in contrast, are stored in a contiguous block of memory. This is why arrays support random access to their elements, while linked lists do not.

### Question 9
Which of the following trees are _perfectly_ complete binary search trees?  
![screenshot15](https://github.com/Whihat/Data-Structure-and-Algorithms/blob/master/screenshot/screenshot15.jpg)  

My Answer: (c)  
The correct answer is **(a),(c)**.  

_FeedBack_: In a **perfectly** complete binary search tree, all non-leaf nodes have two children. A perfect binary search tree of height h has 2^(h+1) - 1 nodes.

### Question 10
the height of the tree is:  
![screenshot16](https://github.com/Whihat/Data-Structure-and-Algorithms/blob/master/screenshot/screenshot16.jpg)  
a. 2  
b. 3  
c. 8  
d. 4  

My Answer: (d)  
The correct answer is **(b)**.  

_FeedBack_: the height of a binary search tree is ***the number of edges*** between the root node and the deepest leaf node.

## Week 4: Week 4: Deletion in BSTs & Balanced Trees

### Question 9
![screenshot17](https://github.com/Whihat/Data-Structure-and-Algorithms/blob/master/screenshot/screenshot17.jpg)

My Answer: (a) [Do again!]  
The correct answer is **(d)**.  

_FeedBack_: When we insert 19 into the given AVL tree, it becomes the left child of node 20. We trace a path from 19, up toward the root node, until we reach the first unbalanced node. In this case, it is node 22 (the difference in heights between its left and right subtrees is 2). Let node 22 be denoted by 'z'. We then trace a path between z down toward the newly inserted node 19, marking the first two nodes we meet as nodes 'y' and 'x', respectively. Look at the shape that nodes z, y, and x make. In this case, they form a Left-Right tree. We must first perform a left rotation on the link between y and x.  Nodes z, y, and x now form a Left-Left tree (with z at the root, x as its left child, and y as the left child of x).  The final step is to perform a right rotation on the link between z (node 22) and x (node 20). The result is tree (d).

### Question 11
Which of the following AVL trees is formed when we insert keys 9, 24, 13, 27, 30, 17, 19, and 22 (in that order) into an initially empty AVL tree?  
![screenshot18](https://github.com/Whihat/Data-Structure-and-Algorithms/blob/master/screenshot/screenshot18.jpg)  
[Do it again!]  
The correct answer is **(a)**.  

### Question 13
Which of the following statements are true? [Note: you may select multiple answers]  
a. AVL, 2-3-4 Trees, and B-Trees are all self-balancing data structures.  
b. 2-3-4 Trees are a generalisation of B-Trees.  
c. Search, insertion, and deletion in an AVL tree of n items are O(logkn) operations.  
d. Search, insertion, and deletion in a B-tree of n items are O(nlogkn) operations.  
e. A Splay Tree is a binary search tree that moves recently accessed nodes to the root (these nodes are "splayed" to the root) for quicker subsequent access.  

My Answer: (a),(b),(c),(d)  
The correct answer is **(a),(c),(e)**.  

_FeedBack_: Statement (b) is false as 2-3-4 Trees are in fact B-Trees of order 4. Statement (d) is false as search, insertion and deletion in a B-Tree are O(logkn) operations.
