#include <stdio.h>
#include "../include/dlist.h"

int main() {
    // setup
    DList *dl = dl_init();

    // insert into empty list
    dl_insert(dl, 0, 'a');
    printf("The value at position 0 is '%c'\n", dl_get(dl, 0));

    // insert new head
    dl_insert(dl, 0, 'b');
    printf("The value at position 0 is '%c'\n", dl_get(dl, 0));

    // insert new tail
    dl_insert(dl, dl_size(dl), 'z');
    printf("The value at the tail of the list is '%c'\n", dl_get(dl, dl_size(dl) - 1));

    // insert at arbitrary location
    dl_insert(dl, 1, 'j');
    printf("The value at position 1 is '%c'\n", dl_get(dl, 1));
}

