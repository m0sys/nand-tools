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

data_t* get_vec_start(vec_ptr v) { return v->data; }

/* Elim Func Call: Direct access to vector data */
void combine3(vec_ptr v, data_t* dest)
{
    long i;
    long length = vec_length(v);
    data_t* data = get_vec_start(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        *dest = *dest OP data[i];
    }
}

/* Elim Mem Ref: Accum res in local var */
void combine4(vec_ptr v, data_t* dest)
{
    long i;
    long length = vec_length(v);
    data_t* data = get_vec_start(v);
    data_t acc = IDENT;
    for (i = 0; i < length; i++) {
        acc = acc OP data[i];
    }
    *dest = acc;
}

/* Loop Unrolling (2x1 loop unrolling) */
void combine5(vec_ptr v, data_t* dest)
{
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t* data = get_vec_start(v);
    data_t acc = IDENT;

    /* Combine 2 elems at a time */
    for (i = 0; i < limit; i += 2) {
        acc = (acc OP data[i])OP data[i + 1];
    }

    /* Finish any remaining elems */
    // This is code that is not good taste.
    for (; i < length; i++)
        acc = acc OP data[i];

    *dest = acc;
}

/* Loop Unrolling (5x1 loop unrolling) */
void combine5_5(vec_ptr v, data_t* dest)
{
    long i;
    long length = vec_length(v);
    long limit = length - 4; // n - k + 1 where k = 5
    data_t* data = get_vec_start(v);
    data_t acc = IDENT;

    /* Combine 5 elems at a time */
    for (i = 0; i < limit; i += 5) {
        acc = (acc OP data[i])OP data[i + 1] OP data[i + 2] OP data[i + 3] OP data[i + 4];
    }

    /* Finish any remaining elems */
    // This is code that is not good taste.
    for (; i < length; i++)
        acc = acc OP data[i];

    *dest = acc;
}

/* 2 x 2 loop unrolling */
void combine6(vec_ptr v, data_t* dest)
{
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t* data = get_vec_start(v);
    data_t acc0 = IDENT;
    data_t acc1 = IDENT;

    /* Combine 2 elements at a time */
    for (i = 0; i < limit; i += 2) {
        acc0 = acc0 OP data[i];
        acc1 = acc1 OP data[i + 1];
    }

    /* Finish any remaining elems */
    // TODO: figure out how to get rid of this special case to make good taste
    //       code.
    for (; i < length; i++)
        acc0 = acc0 OP data[i];

    *dest = acc0 OP acc1;
}
