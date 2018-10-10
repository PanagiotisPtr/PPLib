#include <stdio.h>
#include <PPLib/list.h>

#include "tests.h"

void test_case_1(){
    list l;
    list_node* n;
    int i;
    PRINT_TESTCASE("SIMPLE USAGE");
    list_init(&l);

    for(i=1; i <= 10; i++){
        printf("Added %d to list\n", i);
        list_add(&l, Int(i));
    }

    DEBUG_LOG("List: ");
    n = list_get_node(&l, 0);
    while(n!=NULL){
        printf("%d ", *(int*)n->data);
        n = list_node_get_next(n);
    }
    printf("\n");
    printf("list size: %lu\n", list_size(&l));

    DEBUG_LOG("Deleting 5");
    list_delete(&l, 4);


    DEBUG_LOG("Deleting 10");
    list_delete(&l, list_size(&l)-1);

    DEBUG_LOG("Deleting 1");
    list_delete(&l, 0);
    
    DEBUG_LOG("List: ");
    n = list_get_node(&l, 0);
    while(n!=NULL){
        printf("%d ", *(int*)n->data);
        n = list_node_get_next(n);
    }
    printf("\n");
    DEBUG_LOG("Deleting all items...");
    while(list_size(&l))
        if(list_size(&l)%2)list_pop_back(&l);else list_pop_front(&l);

    printf("List size: %lu\n", list_size(&l));
    DEBUG_LOG("List: ");
    n = list_get_node(&l, 0); /* if it shows index out of range then things went fine */
    while(n!=NULL){
        printf("%d ", *(int*)n->data);
        n = list_node_get_next(n);
    }
    printf("\n");

    list_free(&l);
}

void test_case_2(){
    list v;
    PRINT_TESTCASE("ACCESSING OUT OF RANGE ITEM");
    list_init(&v);

    DEBUG_LOG("Add value 2");
    list_add(&v, Int(2));

    DEBUG_LOG("Try accessing 2nd element");
    list_get(&v, 2);

    list_free(&v);
}

int main(int argv, char** argc){
    test_case_1();
    test_case_2();
    TESTS_CLEARED("List");
    return 0;
}