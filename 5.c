// Write a program to merge two sorted arrays.
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE_1 10
#define ARR_SIZE_2 10

int *arr_merge(int *arr1, int arr_size_1, int *arr2, int arr_size_2);
void print_arr(int *arr, int arr_size);

int main(void) {
  int arr1[ARR_SIZE_1] = {-79, -42, -41, -18, -10, 15, 51, 72, 85, 92};
  int arr2[ARR_SIZE_2] = {-96, -82, -81, -79, -58, -25, -15, -8, 25, 87};

  printf("First array: ");
  print_arr(arr1, ARR_SIZE_1);
  printf("Second array: ");
  print_arr(arr2, ARR_SIZE_2);

  int *merged_arr = arr_merge(arr1, ARR_SIZE_1, arr2, ARR_SIZE_2);

  printf("Merged array: ");
  print_arr(merged_arr, ARR_SIZE_1 + ARR_SIZE_2);

  free(merged_arr);

  return 0;
}

int *arr_merge(int *arr1, int arr_size_1, int *arr2, int arr_size_2) {
  int *ret_arr = (int *)malloc((arr_size_1 + arr_size_2) * sizeof(int));

  int i = 0, j = 0, k = 0;
  while (i < arr_size_1 && j < arr_size_2) {
    if (arr1[i] <= arr2[j]) {
      ret_arr[k++] = arr1[i++];
    } else {
      ret_arr[k++] = arr2[j++];
    }
  }

  // Copy the remaining elements of arr1, if any
  while (i < arr_size_1) {
    ret_arr[k++] = arr1[i++];
  }

  // Copy the remaining elements of arr2, if any
  while (j < arr_size_2) {
    ret_arr[k++] = arr2[j++];
  }

  return ret_arr;
}

void print_arr(int *arr, int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
