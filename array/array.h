#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *array;
    int size;
} Array;
Array array_create(int size);
void array_init(Array *a, int size);
void array_free(Array *a);
int array_size(Array *a);
int* array_at(Array *a, int index);
void array_set(Array *a, int index, int value);
int array_get(const Array *a, int index);
void array_inflate(Array *a, int more_size);
bool array_insert(Array *a, int index, int value);
bool array_delete(Array *a, int index);
int Lookup(Array *a, int value);
#endif