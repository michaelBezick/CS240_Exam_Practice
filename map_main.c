#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  void* data;
  struct Node* next;
} Node;

void print_list(Node*);
void map(Node* head, void (*change) (void*)); 
void add_five(void* a);

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

  map(head, add_five);

  print_list(head);

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
