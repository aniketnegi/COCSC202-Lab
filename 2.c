// Write a program to insert one element in an array and delete an element from an array.
#include <stdio.h>
#include <stdlib.h>

int *arr_insert(int *arr, int arr_size, int val, int pos);
int *arr_delete(int *arr, int arr_size, int pos);
void print_arr(int *arr, int arr_size);

int main(void)
{
  int arr[4] = {1, 2, 3, 4};

  int *new_arr = arr_insert(arr, 4, 0, 0);
  print_arr(new_arr, 5);

  int *deleted_arr = arr_delete(new_arr, 5, 2);
  print_arr(deleted_arr, 4);

  free(new_arr);
  free(deleted_arr); // Free memory allocated for deleted_arr
  return 0;
}

int *arr_insert(int *arr, int arr_size, int val, int pos)
{
  int *new_arr = (int *)malloc((arr_size + 1) * sizeof(int));

  for (int i = 0, j = 0; i < arr_size + 1; i++, j++)
  {
    if (i == pos)
    {
      new_arr[i] = val;
      j--;
    }
    else
    {
      new_arr[i] = arr[j];
    }
  }

  return new_arr;
}

int *arr_delete(int *arr, int arr_size, int pos)
{
  int *new_arr = (int *)malloc((arr_size - 1) * sizeof(int));

  for (int i = 0, j = 0; i < arr_size - 1; i++, j++)
  {
    if (j == pos)
    {
      j++;
    }
    new_arr[i] = arr[j];
  }

  return new_arr;
}

void print_arr(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
