#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#include "helpers.h"

#define VECTOR_INIT_CAPACITY 4

typedef struct vector{
    Item *items;
    size_t capacity; 
    size_t size;
} vector;

void vector_init(vector* v);
void vector_resize(vector* v, size_t new_capacity);
void vector_add(vector* v, Item value);
void vector_set(vector* v, size_t index, Item value);
void optimize_space(vector* v);
void vector_pop_back(vector* v);
void vector_delete(vector* v, size_t index);
void vector_free(vector* v);
Item vector_get(vector* v, size_t index);
size_t vector_size(vector* v);

#endif