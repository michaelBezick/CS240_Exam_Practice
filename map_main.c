#include <stdio.h>
#include <stdio.h>

#include "map.h"

void print_list(Node*);

int main(void) {
  
  Node* head = malloc(sizeof(Node));
  head->data = malloc(sizeof(int));
  *((int*) head->data) = 0;
  Node* cur = head;
  for (int i = 0; i < 10; i++) {
    Node* new_node = malloc(sizeof(Node));
    *((int*) new_node->data) = i;
    cur->next = new_node;
    cur = new_node;
  }

  print_list(head);

  return 0;
}

void print_list(Node* head) {
  while (head) {
    printf("%d\n", *((int*) head->data));
    head = head->next;
  }
}
