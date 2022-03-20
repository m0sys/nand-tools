#include "vec.h"
#include <stdlib.h>

/* Create vector of specified length */
vec_ptr new_vec(long len)
{
    /* Alloc header structure */
    vec_ptr res = (vec_ptr)malloc(sizeof(vec_rec));
    data_t* data = NULL;
    if (!res)
        return NULL; /* couldn't alloc storage */

    res->len = len;

    /* Alloc arr */
    if (len > 0) {
        data = (data_t*)calloc(len, sizeof(data_t));
        if (!data) {
            free((void*)res);
            return NULL; /* couldn't alloc storage */
        }
    }

    /* Data will either be NULL or alloc arr */
    res->data = data;
    return res;
}

/*
 * Retrieve vector elem and store at dest.
 * Return 0 (out of bounds) or 1 (successful)
 */
int get_vec_elem(vec_ptr v, long index, data_t* dest)
{
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}

/* Return length of vector */
long vec_length(vec_ptr v) { return v->len; }

// Implements product.
#define IDENT 1
#define OP *

/* Impl with max use of data abstraction */
void combine1(vec_ptr v, data_t* dest)
{
    long i;
    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        get_vec_elem(v, i, &val);
        *dest = *dest OP val;
    }
}

/* Motion code: move call to vec_length out of loop */
void combine2(vec_ptr v, data_t* dest)
{
    long i;
    long length = vec_length(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        data_t val;
        get_vec_elem(v, i, &val);
        *dest = *dest OP val;
    }
}
