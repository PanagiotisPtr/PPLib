#ifndef HELPERS_H
#define HELPERS_H

typedef void* Item;
/* Uncomment the line below to run in debug mode */
/* #define DEBUG_ON */
/* Comment the line below to disable warnings printed on console */
#define VERBOSE

void swap_items(Item* a, Item* b);

/* Used to convert data to pointers */
int* Int(int a);
float* Float(float a);
double* Double(double a);
unsigned* Unsigned(unsigned a);
char* Char(char a);
char** String(char** a);
long int* LongInt(long int a);
long unsigned* LongUnsigned(long unsigned a);

#endif