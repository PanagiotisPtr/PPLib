#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_init(vector* v){
    v->capacity = VECTOR_INIT_CAPACITY;
    v->size = 0;
    v->items = malloc(sizeof(Item*)*v->capacity);
    if(v->items==NULL){
        #ifdef VERBOSE
        printf("Memory allocation error! [vector_init]\n");
        #endif
    }
}

size_t vector_size(vector* v){
    return v->size;
}

void vector_resize(vector* v, size_t new_capacity){
    #ifdef DEBUG_ON
    printf("Resizing vector from %u to %u\n", v->capacity, new_capacity);
    #endif

    v->items = realloc(v->items, sizeof(Item) * new_capacity);
    if(v->items==NULL){
        #ifdef VERBOSE
        printf("Memory allocation error! [vector_resize]\n");
        #endif
    }
    v->capacity = new_capacity;
}

void vector_add(vector* v, Item value){
    if(v->size == v->capacity)vector_resize(v, v->capacity * 2);
    v->items[v->size++] = value;
}

void vector_set(vector* v, size_t index, Item value){
    if(index >= v->size){
        #ifdef VERBOSE
        printf("Index out of range! [vector_set]\n");
        #endif
    }
    else v->items[index] = value;
}

Item vector_get(vector *v, size_t index){
    if(index >= v->size){
        #ifdef VERBOSE
        printf("Index out of range! [vector_get]\n");
        #endif

        return NULL;
    }
    return v->items[index];
}

void optimize_space(vector* v){
    if(v->size > 0 && v->size == v->capacity / 4){
        vector_resize(v, v->capacity / 2);

        #ifdef DEBUG_ON
        printf("Performed Optimizations. Capacity is now: %u\n", v->capacity);
        #endif

    }
}

void vector_pop_back(vector* v){
    v->size--;
    optimize_space(v);
}

void vector_delete(vector* v, size_t index){
    int i;
    if(index>=v->size)return;
    v->items[index] = 0;
    for(i = index; i < v->size - 1; i++)
        swap_items(&v->items[i], &v->items[i+1]);
    v->size--;
    optimize_space(v);
}

void vector_free(vector* v){
    int i;
    for(i=0; i < v->size; i++)
        free(v->items[i]);
    free(v->items);
}