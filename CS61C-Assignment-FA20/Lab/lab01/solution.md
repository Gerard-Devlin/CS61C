## ex1
```cpp
#define V0 3
#define V1 3
#define V2 3
#define V3 3
```
## ex2
```bash
gcc -g -o hello hello.c
gdb hello
```

```text
1. set args
2. break
3. next
4. step
5. continue
6. print
7. display
8. info locals
9. quit
```

## ex3

```bash
gcc -g -o int_hello interactive_hello.c
int_hello < name.txt
```

## ex4

```bash
gcc -o segfault_ex segfault_ex.c
gcc -o no_segfault_ex no_segfault_ex.c
```

## ex5

```cpp
int ll_has_cycle(node *head) {
    node *tortoise = head;
    node *hare = head;

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (hare == tortoise)
            return 1;
    }
    return 0;
}
```

```bash
gcc -g -o test_ll_cycle test_ll_cycle.c ll_cycle.c
test_ll_cycle.exe
```