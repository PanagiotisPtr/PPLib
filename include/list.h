#ifndef LIST_H
#define LIST_H

#include "helpers.h"

/*
    Implements doubly linked list.
*/

typedef struct list_node{
    Item data;
    struct list_node* next;
    struct list_node* prev;
} list_node;

void list_node_free(list_node* n);

typedef struct list{
    list_node* head;
    list_node* tail;
    size_t size;
} list;

void list_init(list* l);
void list_add(list* l, Item value);
void list_delete(list* l, size_t index);
void list_free(list* l);
void list_pop_back(list* l);
void list_pop_front(list* l);
Item list_get(list* l, size_t index);
Item list_get_tail(list* l);
Item list_get_head(list* l);
list_node* list_get_node(list* l, size_t index);
list_node* list_node_get_next(list_node* n);
list_node* list_node_get_prev(list_node* n);
size_t list_size(list* l);

#endif