#include "list.h"

/* ФУНКЦИИ */
struct node *remove_door(struct node *elem, struct node *root) {
  struct node *ptr = root;
  if (ptr != elem) {
    for (; root != elem; root++) {
    } // позиция ptr = позиции elem
    (ptr - 1)->tail = ptr->tail;
  } else {
    ptr = ptr->tail;
  }
  ptr = elem;
  printf("ВЫНОСИМ ДВЕРЬ: %p\n\n", elem);
  free(elem);
  return root;
}

struct node *find_door(int door_id, struct node *root) {
  while (root) {
    if (root->doors.id == door_id)
      return root;
    root++;
  }
  return root;
}

struct node *init(const struct door *doors) {
  struct node *root = (struct node *)malloc(sizeof(struct node));
  root->doors = *doors;
  root->tail = NULL;
  return root;
}

struct node *add_door(struct node *elem, const struct door *doors) {
  struct node *root = (struct node *)malloc(
      sizeof(struct node)); //выделяем память для нового узла
  root->doors = *doors;
  root->tail = NULL; // Задаем конечный элемент NULL из предыдущего
  elem->tail = root;
  return root;
}

void destroy(struct node *root) {
  while (root->tail != NULL) {
    free(root);
    root++;
  }
  free(root);
}

void initialize_doors(struct door *doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}

void output(struct node *nodes, struct node *elem) {
  int i = 0;
  while (nodes->tail != NULL) {
    if (i == 0 && (nodes != elem || elem == NULL))
      printf("[%p] INIT NODE[%d]: %d, %d => %p\n", nodes, i, nodes->doors.id,
             nodes->doors.status, nodes->tail);
    else if (nodes != elem || elem == NULL)
      printf("[%p] NODE[%d]: %d, %d => %p\n", nodes, i, nodes->doors.id,
             nodes->doors.status, nodes->tail);
    i++;
    nodes++;
  }
  if (nodes != elem || elem == NULL)
    printf("[%p] NODE[%d]: %d, %d => %p\n", nodes, i, nodes->doors.id,
           nodes->doors.status, nodes->tail);
}
