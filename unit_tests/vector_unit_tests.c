#include <stdio.h>
#include <stdlib.h>
#include <PPLib/vector.h>

#include "tests.h"

void test_case_1(){
    vector v;
    int i;
    PRINT_TESTCASE("SIMPLE USAGE");
    vector_init(&v);

    for(i=1; i <= 5; i++){
        printf("Added %d to vector\n", i);
        vector_add(&v, Int(i));
    }

    DEBUG_LOG("Vector: ");
    for(i=0; i < vector_size(&v); i++)
        printf("%d ", *(int*)vector_get(&v, i));
    printf("\n");

    DEBUG_LOG("Deleting 3");
    vector_delete(&v, 2);

    DEBUG_LOG("Deleting 1");
    vector_delete(&v, vector_size(&v)-1);

    DEBUG_LOG("Deleting 5");
    vector_delete(&v, 0);

    DEBUG_LOG("Vector: ");
    for(i=0; i < vector_size(&v); i++)
        printf("%d ", *(int*)vector_get(&v, i));
    printf("\n");

    DEBUG_LOG("Deleting all items...");
    while(vector_size(&v))vector_pop_back(&v);

    DEBUG_LOG("Vector: ");
    for(i=0; i < vector_size(&v); i++)
        printf("%d ", *(int*)vector_get(&v, i));
    printf("\n");

    vector_free(&v);
}

void test_case_2(){
    vector v;
    PRINT_TESTCASE("ACCESSING OUT OF RANGE ITEM");
    vector_init(&v);

    DEBUG_LOG("Add value 2");
    vector_add(&v, Int(2));

    DEBUG_LOG("Try accessing 2nd element");
    vector_get(&v, 2);

    vector_free(&v);
}

void test_case_3(){
    vector v;
    PRINT_TESTCASE("SIZE OPTIMIZATIONS");
    vector_init(&v);

    DEBUG_LOG("Setting first item to 99.99 and the rest to 1");
    vector_add(&v, Double(99.99));
    vector_add(&v, Double(1));
    vector_add(&v, Double(1));
    vector_add(&v, Double(1));
    /* vector resizes capacity to 8*/
    vector_add(&v, Double(1));
    vector_add(&v, Double(1));
    vector_add(&v, Double(1));
    vector_add(&v, Double(1));
    vector_add(&v, Double(1));
    /*vector resizes capacity to 16*/
    while(vector_size(&v)>1)vector_pop_back(&v);
    printf("First element was: %f\n", *(double*)vector_get(&v, 0));
    
    vector_free(&v);
}

int main(int argv, char **argc){
    test_case_1();
    test_case_2();
    test_case_3();
    TESTS_CLEARED("Vector");
    return 0;
}