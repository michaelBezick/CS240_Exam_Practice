#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

void* fold(node*, void*, void* (*f) (void*));

int main(void) {

  return 0;
}

void* fold(node* n, void* acc, void* (*f) (void*)) {
  return NULL;
}

void* add(void* a, void* b) {
  int* val = malloc(sizeof(int));
  *val = (*((int*) a) + *((int*) b));
  return val;
}
