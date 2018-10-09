#include <stdlib.h>

#include "helpers.h"

void swap_items(Item* a, Item* b){
    Item c;
    c = *b;
    *b = *a;
    *a = c;
}

/* Data to pointer conversions */

int* Int(int a){
    int* b = malloc(sizeof(int));
    *b = a;
    return b;
}

float* Float(float a){
    float* b = malloc(sizeof(float));
    *b = a;
    return b;
}

double* Double(double a){
    double* b = malloc(sizeof(double));
    *b = a;
    return b;
}

unsigned* Unsigned(unsigned a){
    unsigned* b = malloc(sizeof(unsigned));
    *b = a;
    return b;
}

char* Char(char a){
    char* b = malloc(sizeof(char));
    *b = a;
    return b;
}

char** String(char** a){
    return a;
}

long int* LongInt(long int a){
    long int* b = malloc(sizeof(long int));
    *b = a;
    return b;
}

long unsigned* LongUnsigned(long unsigned a){
    long unsigned* b = malloc(sizeof(long unsigned));
    *b = a;
    return b;
}