#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int should_swap(void* first, void* second);
void bubble_sort(void* arr, size_t n_elems, size_t elem_size, int swap_fn(void*, void*));
void swap(void* first, void* second, size_t elem_size);
void swap2(void* first, void* second, size_t elem_size);
void print_array(int* arr, size_t n_elems);

int main(void) {

  int arr[8] = {32, 45, 2, 34, 12, 56, 32, 54};
  print_array(arr, 8);
  printf("--------------------------------------------------\n");
  bubble_sort(arr, 8, sizeof(int), should_swap);
  print_array(arr, 8);

  return 0;
}

void print_array(int* arr, size_t n_elems) {
  for (int i = 0; i < n_elems; i++) {
    printf("%d\n", *(arr + i));
  }
}

void bubble_sort(void* arr, size_t n_elems, size_t elem_size, int swap_fn(void*, void*)) {
  int end = n_elems;
  while (1) {
    int swapped = 0;
    for (int i = 0; i < end - 1; i++) {
      if (swap_fn((char*) arr + i * elem_size, (char*) arr + (i + 1) * elem_size)) {
        swap2((char*) arr + i * elem_size, (char*) arr + (i + 1) * elem_size, elem_size);
        swapped = 1;
      }
    }
    end--;
    if (swapped == 0) {
      return;
    }
  }
}

int should_swap(void* first, void* second) {
  if (*((int*) first) > *((int*) second)) {
    return 1;
  }
  else {
    return 0;
  }
}

void swap(void* first, void* second, size_t elem_size) {
  for (int i = 0; i < elem_size; i++) {
    char temp = *((char*) first + i);
    *((char*) first + i) = *((char*) second + i);
    *((char*) second + i) = temp;
  }
}

void swap2(void* first, void* second, size_t elem_size) {
  char temp[elem_size];
  memcpy(temp, first, elem_size);
  memcpy(first, second, elem_size);
  memcpy(second, temp, elem_size);
}
