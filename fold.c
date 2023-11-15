#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

int main(void) {

  return 0;
}

void* fold(node* n, void* acc, void* (*f) (void*)) {
  return NULL;
}
