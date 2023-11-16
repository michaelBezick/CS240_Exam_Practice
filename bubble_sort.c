#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap_elems(void* arr1, void* arr2, size_t num_bytes);
bool less_than_int(void* val1, void* val2);
void bubble_sort(void* arr, size_t elem_size, size_t num_elems, bool (*cmp_fn) (void*, void*));
void print_array(int arr[], int size);

int main(void) {

  int arr[] = {1, 2, 3, 4, 5};
  print_array(arr, 5);

  bubble_sort(arr, sizeof(int), sizeof(arr) / sizeof(int), less_than_int);
  printf("--------------------------------------------------\n");

  print_array(arr, 5);

  return 0;
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

void bubble_sort(void* arr, size_t elem_size, size_t num_elems, bool (*cmp_fn) (void*, void*)) {

  while (1) {
    bool swapped = false;
    for (size_t i = 1; i < num_elems; i++) {
      void* cur_elem = (char*) arr + (i * elem_size);
      void* prev_elem = (char*) arr + ((i - 1) * elem_size);
      if (cmp_fn(cur_elem, prev_elem)) {
        swap_elems(cur_elem, prev_elem, elem_size);
        swapped = true;
      }
    }
    if (swapped == false) {
      return;
    }
  }
}

void swap_elems(void* arr1, void* arr2, size_t num_bytes) {
  for (size_t i = 0; i < num_bytes; i++) {
    char temp = *((char*) arr1 + i);
    *((char*) arr1 + i) = *((char*) arr2 + i);
    *((char*) arr2 + i) = temp;
  }
  return;
}

bool less_than_int(void* val1, void* val2) {
  return (*((int*) val1) > *((int*) val2));
}
