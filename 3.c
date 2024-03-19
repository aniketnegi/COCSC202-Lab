// Write a program to search for a number in an array.
#include <stdio.h>

#define MAX_ARR_SIZE 256

int search(int *arr, int arr_size, int val);

int main(void) {
  int numbers[MAX_ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7};

  int val;
  printf("Enter the value to search for: ");
  scanf("%d", &val);

  int ret = search(numbers, 7, val);

  if (ret == -1) {
    printf("%d not found in array.\n", val);
  } else {
    printf("%d found at position %d in array.\n", val, ret);
  }

  return 0;
}

int search(int *arr, int arr_size, int val) {
  int ret = -1;

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] == val) {
      ret = i;
      break;
    }
  }

  return ret;
}
