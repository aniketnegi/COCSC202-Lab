// Write a program to implement a linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

typedef struct list_t {
  struct node_t *head, *tail;
  int size;
} list_t;

// Initialise a linked list
list_t *list_init(void);

// Push an element to LL
void list_push(list_t *list, int data);

// Pop an element from LL
int list_pop(list_t *list);

// Print LL
void list_print(list_t *list);

// Free LL
void list_free(list_t *list);

// Error Checkers
static void check_malloc_failure(void *p);

int main(void) {
  list_t *list = list_init();

  list_push(list, 10);
  list_push(list, 20);
  list_push(list, 30);
  list_push(list, 40);

  list_print(list);

  printf("\nPopping last element\n");
  int one = list_pop(list);
  printf("Last: %d\n", one);
  list_print(list);

  printf("\nPopping last element\n");
  one = list_pop(list);
  printf("Last: %d\n", one);
  list_print(list);

  printf("\nPopping last element\n");
  one = list_pop(list);
  printf("Last: %d\n", one);
  list_print(list);

  printf("\nPopping last element\n");
  one = list_pop(list);
  printf("Last: %d\n", one);
  list_print(list);

  list_free(list);

  return 0;
}

static void check_malloc_failure(void *p) {
  if (p == NULL) {
    fprintf(stderr, "ERROR: Malloc Failure!\n");

    exit(EXIT_FAILURE);
  }
}

list_t *list_init(void) {
  list_t *new_list = (list_t *)malloc(sizeof(list_t));

  check_malloc_failure(new_list);

  new_list->head = NULL;
  new_list->tail = NULL;
  new_list->size = 0;

  return new_list;
}

void list_push(list_t *list, int data) {
  node_t *new = (node_t *)malloc(sizeof(node_t));

  check_malloc_failure(new);

  new->data = data;
  new->next = NULL;

  if (list->size == 0) {
    list->head = new;
  } else {
    list->tail->next = new;
  }
  list->tail = new;
  list->size++;
}

int list_pop(list_t *list) {
  if (list->size == 0) {
    fprintf(stderr, "ERROR: Can't pop empty list\n");
    list_free(list);
    exit(EXIT_FAILURE);
  } else if (list->size == 1) {
    int data = list->tail->data;

    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size--;

    return data;
  } else {
    int data = list->tail->data;

    node_t *curr = list->head;

    while (curr->next->next) {
      curr = curr->next;
    }

    curr->next = NULL;
    free(list->tail);
    list->tail = curr;
    list->size--;

    return data;
  }
}

void list_print(list_t *list) {
  if (list->size == 0) {
    printf("Printing Empty LIST!\n");
    return;
  }
  node_t *curr = list->head;

  printf("LIST DATA:\n");

  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
  }

  printf("\n");
}

void list_free(list_t *list) {
  node_t *prev, *curr = list->head;

  while (curr) {
    prev = curr;
    curr = curr->next;

    free(prev);
  }
  free(prev);

  free(list);
}
