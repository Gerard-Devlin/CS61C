#include "ll_cycle.h"
#include <stddef.h>

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