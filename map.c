#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void* data;
  struct node* next;
} Node;


void add_five(int* a) {
  *a += 5;
}

Node* map(Node* head, void (*change) (void*)) {

  return NULL;
}
