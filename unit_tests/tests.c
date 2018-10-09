#include <stdio.h>

#include "tests.h"

void PRINT_TESTCASE(char msg[]){
    printf("\n\t:: Running Testcase: %s ::\n\n", msg);
}

void DEBUG_LOG(char msg[]){
    printf("LOG: %s\n", msg);
}