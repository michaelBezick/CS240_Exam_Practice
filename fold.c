#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void* data;
  struct node* next;
} node;

void* fold(node*, void*, void* (*f) (void*));
void print_list(node* head);

int main(void) {
  node* head = malloc(sizeof(node));
  int* data = malloc(sizeof(int));
  *data = 0;
  head->data = data;
  head->next = NULL;

  node* cur = head;

  for (int i = 1; i < 10; i++) {
    node* new_node = malloc(sizeof(node));
    int* data = malloc(sizeof(int));
    *data = i;
    new_node->data = data;
    new_node->next = NULL;
    cur->next = new_node;
    cur = cur->next;
  }

  print_list(head);

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

void print_list(node* head) {
  if (head == NULL) {
    return;
  }
  else {
    printf("%d\n", *((int*) head->data));
    return print_list(head->next);
  }
}
