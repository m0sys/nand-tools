/* Create abstract data type for vector */
typedef int data_t;
typedef struct {
    long len;
    data_t* data;
} vec_rec, *vec_ptr;
