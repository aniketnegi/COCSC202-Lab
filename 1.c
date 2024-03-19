// Write a program to find the mean and the median of the numbers stored in an
// array.
#include <stdio.h>

#define MAX_ARR_SIZE 10

double find_mean(int *arr, int arr_size);
void sort(int *arr, int arr_size);
double find_median(int *arr, int arr_size);
void print_arr(int *arr, int arr_size);

int main(void) {
  int numbers[MAX_ARR_SIZE] = {10, 4, 44, 2, 0, 12, -1, -10, 4, 1};

  printf("The array is: ");
  print_arr(numbers, MAX_ARR_SIZE);

  double mean = find_mean(numbers, MAX_ARR_SIZE);
  double median = find_median(numbers, MAX_ARR_SIZE);

  printf("Mean of all the elements of the array is: %.2f\n", mean);
  printf("Median of the array is: %.2f\n", median);

  printf("Exiting program!\n");

  return 0;
}

double find_mean(int *arr, int arr_size) {
  int sum = 0;
  for (int i = 0; i < arr_size; i++) {
    sum += arr[i];
  }

  double mean = (double)sum / arr_size;

  return mean;
}

void sort(int *arr, int arr_size) {
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

double find_median(int *arr, int arr_size) {
  sort(arr, arr_size);
  double median;

  if (arr_size % 2 != 0) {
    median = (double)arr[(int)(arr_size / 2)];
  } else {
    median = (arr[(int)(arr_size / 2) - 1] + arr[(int)(arr_size / 2)]) / 2;
  }

  return median;
}

void print_arr(int *arr, int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
