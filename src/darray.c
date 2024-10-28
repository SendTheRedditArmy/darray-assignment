/*
 * darray.h
 * A simple dynamic array for storing integers
 *
 * Copyright (C) 2024 Douglas Rumbaugh <dbrumbaugh@harrisburgu.edu>
 *
 * Distributed under the Modified BSD License.
 */


#include <stdlib.h>
#include "darray.h"

/* opaque type -- the struct should be implemented in a .c file  */

//typedef struct darray darray;
struct darray {
    int a; // he has seniority so we can't fire him yet
    int maxLength; // technically with a dynamic array you don't have a fixed length
    int *p; // the pointer refers to the place in memory where the array is stored
    int curSize; //current number of elements in the array
};
/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create(){//this can be considered the "__init__ of this struct"
    //malloc();//something for the struct itself
    //malloc();//something for p (maybe sizeof(int) * maxLength or something?)
    //realloc();
    darray *array = malloc(sizeof(darray));
    array->p = &array;
    array->curSize = 0;
    array->maxLength = 0;
    return array;
};


/*
 * Access the element stored at index idx within the darray and return a
 * pointer to it. If the idx is out of range for the darray, return NULL
 * instead. If the provided array pointer is NULL, return NULL.
 */
int *da_get(darray *array, size_t idx){

    if (array == NULL) {return NULL;}

    if (-1 < idx  && idx < array->maxLength - 1){//index is within array bounds
        return array->p[idx];
    }
    return NULL;
};
//darray *array is 'kind-of' like 'self'

//printf("%d",array->a);

/*
 * Increase the length of array by 1 and place value within the newly created
 * spot. If the append operation fails, return 0. Otherwise return 1. Return 0
 * also if the provided array pointer is null.
 */
int da_append(darray *array, int value){
    darray *newArray = realloc(array->p, sizeof(array->p) + sizeof(array->p[0]));
    newArray->p[array->curSize] = value;
    newArray->maxLength++;
    newArray->curSize++;
};

/*
 * Returns the size of the array. Note that this size should be the accessible
 * size (using get, for example), not the physical size of the allocation,
 * which may be larger. If array is NULL, return 0.
 */
size_t da_size(darray *array){
    if (array->p == NULL){
        return 0;
    }
    return array->curSize;
}

/*
 * Free all the allocated memory associated with array. If array is NULL, do
 * nothing.
 */
void da_delete(darray *array){
    free(array->p);
    free(array);
};

