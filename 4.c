// Write a program to sort an array.
#include <stdio.h>

#define ARR_SIZE 10

void arr_sort(int *arr, int arr_size);
void print_arr(int *arr, int arr_size);

int main(void) {
  int numbers[ARR_SIZE] = {10, 4, 44, 2, 0, 12, -1, -10, 4, 1};

  printf("Original Array: ");
  print_arr(numbers, ARR_SIZE);

  arr_sort(numbers, ARR_SIZE);

  printf("Sorted Array: ");
  print_arr(numbers, ARR_SIZE);

  return 0;
}

void arr_sort(int *arr, int arr_size) {
  // standard insertion sort
  // faster for smaller arrays
  int i, key, j;
  for (i = 1; i < arr_size; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void print_arr(int *arr, int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
