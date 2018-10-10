#include <stdio.h>

#include "tests.h"

void PRINT_TESTCASE(char msg[]){
    printf("\n\t:: Running Testcase: %s ::\n\n", &msg[0]);
}

void DEBUG_LOG(char msg[]){
    printf("LOG: %s\n", &msg[0]);
}

void PRINT_LINE(){
    printf("============================================================\n");
}

void TESTS_CLEARED(char msg[]){
    PRINT_LINE();
    printf("\n\t:: %s :: UNIT TESTS CLEARED :: \n\n", &msg[0]);
    PRINT_LINE();
}