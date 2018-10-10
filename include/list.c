#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void list_node_free(list_node* n){
    free(n->data);
    n->prev = NULL;
    n->next = NULL;
    free(n);
}

void list_init(list* l){
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void list_add(list* l, Item value){
    if(l->head==NULL){ /*if head is NULL then tail is also NULL*/
        l->head = malloc(sizeof(list_node));
        l->head->data = value;
        l->head->next = NULL;
        l->head->prev = NULL;
        l->tail = l->head;

        #ifdef DEBUG_ON
        printf("Head in null...\n");
        #endif

    }else{
        list_node* n = malloc(sizeof(list_node));
        n->data = value;
        n->prev = l->tail;
        n->next = NULL;
        l->tail->next = n;
        l->tail = n;

        #ifdef DEBUG_ON
        printf("Moved tail\n");
        #endif

    }
    l->size++;
}

void clear_head_tail(list* l){ /* "Private" function should only be used in implementation file. Assumes size is 1 and sets head/tail to NULL*/
    #ifdef DEBUG_ON
    printf("Clearing head and tail: ");
    #endif

    if(l->size == 1){
        #ifdef DEBUG_ON
        printf("Good call\n");
        #endif

        list_node_free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    }
}

int valid_index(list* l, size_t index){ /* "Private" function. Returns true (1) if index is in range or false (0) if index is out of range */
    if(index < 0 || index >= l->size){
        #ifdef VERBOSE
        printf("Index out of range! [list_get]\n");
        #endif

        return 0;
    }
    return 1;
}


list_node* list_get_node(list* l, size_t index){
    list_node* n = l->head;
    if(!valid_index(l, index))return NULL;
    while(index--)n = n->next;
    return n;
}

list_node* list_node_get_next(list_node* n){
    return n->next;
}

list_node* list_node_get_prev(list_node* n){
    return n->prev;
}


void list_free(list* l){
    if(l->size==0)return;
    if(l->size==1)clear_head_tail(l);
    else{
        list_pop_back(l);
        list_free(l);
    }
}

void list_pop_back(list* l){
    list_node* n;

    #ifdef DEBUG_ON
    printf("Deleting tail\n");
    #endif

    if(l->size==0)return;
    if(l->size==1){
        clear_head_tail(l);
        return;
    }
    n = l->tail->prev;
    n->next = NULL;
    list_node_free(l->tail);
    l->tail = n;
    l->size--;
}

void list_pop_front(list* l){
    list_node* n;

    #ifdef DEBUG_ON
    printf("Deleting head\n");
    #endif

    if(l->size==0)return;
    if(l->size==1){
        clear_head_tail(l);
        return;
    }
    n = l->head->next;
    n->prev = NULL;
    list_node_free(l->head);
    l->head = n;
    l->size--;
}

void list_delete(list* l, size_t index){
    /* node, prev, next */
    list_node* n;
    list_node* pr;
    list_node* ne;
    if(!valid_index(l, index))return;
    if(index==0){
        list_pop_front(l);
        return;
    }
    if(index==l->size-1){
        list_pop_back(l);
        return;
    }
    /*n->next and n->prev is surely not NULL since we are neither at the tail nor at the head of the list*/
    n = l->head;
    while(index--)n = n->next;
    pr = n->prev;
    ne = n->next;
    ne->prev = pr;
    pr->next = ne;
    list_node_free(n);
    l->size--;
}

Item list_get(list* l, size_t index){
    list_node* n = l->head;
    if(!valid_index(l, index))return NULL;
    while(index--)n = n->next;
    return n->data;
}

Item list_get_tail(list* l){
    return l->tail->data;
}

Item list_get_head(list* l){
    return l->head->data;
}

size_t list_size(list* l){
    return l->size;
}
