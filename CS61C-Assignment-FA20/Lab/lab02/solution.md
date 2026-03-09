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

