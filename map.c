#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void* data;
  struct node* next;
} node;

void print_list(node*);
void* multiply(void* a);
node* map(node*, void* (*f) (void*));

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
  printf("--------------------------------------------------\n");
  print_list(map(head, multiply));

  return 0;
}

node* map(node* n, void* (*f) (void*)) {
  if (n == NULL) {
    return NULL;
  }
  else {
    node* new_node = malloc(sizeof(node));
    new_node->data = f(n->data);
    new_node->next = map(n->next, f);
    return new_node;
  }
}

void* multiply(void* a) {
  int* val = malloc(sizeof(int));
  *val = *((int*) a) * 100;
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
