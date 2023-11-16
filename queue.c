#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} node;

typedef struct Queue {
  node* front;
  node* end;
} Queue;

int dequeue(Queue*);
void enqueue(Queue*, int val);

int main(void) {

  Queue* q = malloc(sizeof(Queue));
  q->front = NULL;
  q->end = NULL;

  for (int i = 0; i < 10; i++) {
    enqueue(q, i);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", dequeue(q));
  }

  return 0;
}

void enqueue(Queue* q, int val) {
  node* new_node = malloc(sizeof(node));
  new_node->val = val;
  new_node->next = NULL;
  if (q->end == NULL) {
    q->end = new_node;
    q->front = new_node;
    return;
  }
  q->end->next = new_node;
  q->end = new_node;
  return;
}

int dequeue(Queue* q) {
  int val = q->front->val;
  node* temp = q->front;
  q->front = temp->next;

  free(temp);
  temp = NULL;

  return val;
}
