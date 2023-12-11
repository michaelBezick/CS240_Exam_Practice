#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  void* data;
  struct Node* next;
  struct Node* previous;
} Node;


void print_list_forward(Node* head) {
  while (head) {
    printf("%d\n", *((int*) head->data));
    head = head->next;
  }
}

void print_list_backward(Node* end) {
  while (end) {
    printf("%d\n", *((int*) end->data));
    end = end->previous;
  }
}

int is_palindrome(Node* head) {

  return 0;
}



int main(void) {
  
  Node* head = malloc(sizeof(Node));
  head->data = malloc(sizeof(int));
  head->next = NULL;
  head->previous = NULL;
  *((int*) head->data) = 0;
  Node* cur = head;
  Node* end;

  for (int i = 1; i < 10; i++) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = malloc(sizeof(int));
    new_node->next = NULL;
    new_node->previous = cur;
    *((int*) (new_node->data)) = i;
    cur->next = new_node;
    cur = new_node;
    end = cur;
  }

//  print_list_forward(head);
  print_list_backward(end);

  printf("--------------------------------------------------\n");

  return 0;

}
