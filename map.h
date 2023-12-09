#ifndef MAP_H
#define MAP_H 

/* Included Libraries */

#include <stdio.h>
#include <stdlib.h>

/* Constant Definitions */


/* Error Codes */


/* Structs Definition */

struct Node {
  void* data;
  struct Node* next;
};

typedef struct Node Node;

/* Function Prototypes */
void add_five(int*);
Node* map(Node* head, void (*change) (void*));
void print_list(Node*);

/* Global Variables */

#pragma GCC poison access

#endif // MAP_H
