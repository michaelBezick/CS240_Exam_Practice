#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  void* data;
  struct Node* next;
} Node;

void print_list(Node*);
void map(Node* head, void (*change) (void*)); 
void add_five(void* a);
void* fold(Node* head, void* acc, void* acc_fn(void*, void*));
void* additive_accumulate(void*, void*);

int main(void) {
  
  Node* head = malloc(sizeof(Node));
  head->data = malloc(sizeof(int));
  head->next = NULL;
  *((int*) head->data) = 0;
  Node* cur = head;

  for (int i = 1; i < 10; i++) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = malloc(sizeof(int));
    new_node->next = NULL;
    *((int*) (new_node->data)) = i;
    cur->next = new_node;
    cur = new_node;
  }

  print_list(head);

  printf("--------------------------------------------------\n");

  int* start_acc = malloc(sizeof(int));
  *start_acc = 0;
  int* end_acc = fold(head, start_acc, additive_accumulate);
  printf("%d\n", *end_acc);

  return 0;
}

void print_list(Node* head) {
  while (head) {
    printf("%d\n", *((int*) head->data));
    head = head->next;
  }
}

void add_five(void* a) {

  *((int*) a) += 5;
}

void map(Node* head, void (*change) (void*)) {

  Node* cur = head;
  
  while (cur) {
    change(cur->data);
    cur = cur->next;
  }
}

void* fold(Node* head, void* acc, void* acc_fn(void*, void*)) {
  Node* cur = head;
  if (!cur) {
    return acc; 
  }
  else {
    return fold(cur->next, acc_fn(cur->data, acc), acc_fn);
  }
}


void* additive_accumulate(void* val, void* acc) {
  *((int*) acc) += *((int*) val);
  return acc;
}
