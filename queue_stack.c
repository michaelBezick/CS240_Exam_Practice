#include <inttypes.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  void* val;
  struct node* next;
} Node;

typedef struct stack {
  size_t elem_size;
  Node* top;
} Stack;

typedef struct queue {
  size_t elem_size;
  Node* front;
  Node* end;
} Queue;

void stack_push(Stack* s, void* data);
int stack_pop_int(Stack* s);
void print_stack(Stack* s);
int dequeue(Queue* q);
void enqueue(Queue* q, void* data);
void print_queue(Queue* q);

int main(void) {

  Stack* s = malloc(sizeof(Stack));
  s->top = NULL;
  s->elem_size = sizeof(int);

  Queue* q = malloc(sizeof(Queue));
  q->elem_size = sizeof(int);
  q->end = NULL;
  q->front = NULL;

  for (int i = 0; i < 10; i++) {
    int* data = malloc(sizeof(int));
    *data = i;
    enqueue(q, data);
  }

  print_queue(q);

  return 0;
}

void stack_push(Stack* s, void* data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->val = malloc(s->elem_size);
  memcpy(new_node->val, data, s->elem_size);
  new_node->next = s->top;
  s->top = new_node;
}

int stack_pop_int(Stack* s) {
  void* data = s->top->val;
  int int_data = *((int*) data);

  Node* next = s->top->next;
  free(s->top->val);
  free(s->top);
  s->top = next;

  return int_data;
}

void print_stack(Stack* s) {
  while (s->top) {
    printf("%d\n", stack_pop_int(s));
  }
}

void print_queue(Queue* q) {
  while (q->front) {
    printf("%d\n", dequeue(q));
  }
}

void enqueue(Queue* q, void* data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->val = malloc(q->elem_size);
  memcpy(new_node->val, data, q->elem_size);
  new_node->next = NULL;

  if (q->front == NULL) {
    q->front = new_node;
    q->end = new_node;
  }
  else {
    q->end->next = new_node;
    q->end = new_node;
  }
}

int dequeue(Queue* q) {
  int val = *((int*) q->front->val);
  Node* temp = q->front;
  q->front = q->front->next;
  free(temp->val);
  free(temp);

  if (q->front == NULL) {
    q->end = NULL;
  }

  return val;
}
