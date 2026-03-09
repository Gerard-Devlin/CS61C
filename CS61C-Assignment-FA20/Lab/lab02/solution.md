## ex1

```cpp
unsigned get_bit(unsigned x, unsigned n) {
    return (x >> n) & 1;
}

void set_bit(unsigned *x, unsigned n, unsigned v) {
    *x = (*x & ~(1 << n)) | (v << n);
}
void flip_bit(unsigned *x, unsigned n) {
    *x = *x ^ (1 << n);
}
```

```bash
D:\mingw64\bin\mingw32-make.exe bit_ops
bit_ops.exe
```

---

## ex2

```cpp
void lfsr_calculate(uint16_t *reg) {
    // pick out all the digits
    int bit0 = (*reg) & 1;
    int bit2 = (*reg >> 2) & 1;
    int bit3 = (*reg >> 3) & 1;
    int bit5 = (*reg >> 5) & 1;

    int newBit = bit0 ^ bit2 ^ bit3 ^ bit5;

    // right shit one digit and add newbit to msb
    *reg = *reg >> 1 | newBit << 15;
}
```

```bash
D:\mingw64\bin\mingw32-make.exe lfsr
lfsr.exe
```

---

## ex3

`vector.h`

```cpp
/* Create a new vector */
vector_t *vector_new();

/* Free up the memory allocated for the passed vector */
void vector_delete(vector_t *v);

/* Return the value in the vector */
int vector_get(vector_t *v, size_t loc);

/* Set a value in the vector */
void vector_set(vector_t *v, size_t loc, int value);
```

`vector.c`

```cpp
/* Create a new vector with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval = malloc(sizeof(vector_t));

    /* Check our return value to make sure we got memory */
    if (retval == NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size = 1;
    retval->data = malloc(sizeof(int)); // pointer needs to be malloc

    /* Check the data attribute of our vector to make sure we got memory */
    if (retval->data == NULL) {
        free(retval); // Why is this line necessary?
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */
    retval->data[0] = 0;

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc < v->size) {
        return v->data[loc];
    } else {
        return 0;
    }
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    if (v == NULL)
        return;
    free(v->data);
    free(v);
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

    if (v == NULL) {
        abort();
    }

    if (loc >= v->size) {
        size_t old = v->size;
        size_t new = loc + 1;

        int *new_data = realloc(v->data, new * sizeof(int)); // must be new times size of int

        if (new_data == NULL) {
            allocation_failed();
        }
        v->data = new_data;

        for (size_t i = old; i < new; i++) {
            v->data[i] = 0;
        }

        v->size = new;
    }
    v->data[loc] = value;
}
```

```bash
D:\mingw64\bin\gcc.exe -ggdb -Wall -std=c99 -o vector-test vector.c vector-test.c
```
