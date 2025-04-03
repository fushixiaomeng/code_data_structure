#include "array.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    Array a = array_create(10);
    for (int i = 0; i < array_size(&a); i++) {
        array_set(&a, i, i);
    }
    for (int i = 0; i < array_size(&a); i++) {
        printf("%d\n", array_get(&a, i));
    }
    array_inflate(&a, 5);
    printf("size=%d\n", array_size(&a));
    array_insert(&a, 2, 100);
    for (int i = 0; i < array_size(&a); i++) {
        printf("%d\n", array_get(&a, i));
    }
    printf("size=%d\n", array_size(&a));
    array_delete(&a, 2);
    for (int i = 0; i < array_size(&a); i++) {
        printf("%d\n", array_get(&a, i));
    }
    int value;
    printf("Enter a value to search: ");
    scanf("%d", &value);
    int index = Lookup(&a, value);
    printf("Value %d found at index %d\n", value, index);
    array_free(&a);
    return 0;
}

Array array_create(int size) {
    Array a;
    a.array = (int *)malloc(size * sizeof(int));
    a.size = size;
    return a;
}

void array_init(Array *a, int size) {
    a->array = (int *)malloc(size * sizeof(int));
    a->size = size;
}

void array_free(Array *a) {
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

int array_size(Array *a) {     //封装的好处，可以在这里加入一些判断，比如a是否为空
    return a->size;
}


int* array_at(Array *a, int index) {
    return &(a->array[index]);
}

// array_at的另一种实现
void array_set(Array *a, int index, int value) {
    a->array[index] = value;
}

//按位址访问数组元素
int array_get(const Array *a, int index) {
    return a->array[index];
}

void array_inflate(Array *a, int more_size) {
    // a->array = (int *)realloc(a->array, (a->size + more_size) * sizeof(int));
    // a->size += more_size;
    int *p = a->array;
    a->array = (int *)malloc((a->size + more_size) * sizeof(int));
    for (int i = 0; i < a->size; i++) {
        a->array[i] = p[i];
    }
    free(p);
    a->size += more_size;

}

bool array_insert(Array *a, int index, int value){
    if (index < 0 || index > a->size) {
        printf("Index out of bounds\n");
        return false;
    }
    // array_inflate(a, 1); // Increase size by 1
    for (int i = a->size; i >= index; i--) {
        a->array[i] = a->array[i - 1];
    }
    a->array[index-1] = value;
    // a->size++;
    return true;
}

bool array_delete(Array *a, int index) {
    if (index < 0 || index >= a->size) {
        printf("Index out of bounds\n");
        return false;
    }
    for (int i = index; i < a->size - 1; i++) {
        a->array[i-1] = a->array[i];
    }
    // a->size--;
    return true;
}

int Lookup(Array *a, int value) {
    for (int i = 0; i < a->size; i++) {
        if (a->array[i] == value) {
            return i+1;
        }
    }
    return -1; // Not found
}