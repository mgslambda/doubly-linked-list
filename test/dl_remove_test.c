#include <stdio.h>
#include "../include/dlist.h"

int main() {
    // setup
    DList *dl = dl_init();
    dl_insert(dl, 0, 1);
    dl_insert(dl, 0, 2);
    dl_insert(dl, 0, 3);
    dl_insert(dl, 0, 4);
    dl_insert(dl, 0, 5);
    dl_print(dl);
    puts("");

    // remove from the start of the list
    puts("Removing the head of the list");
    dl_remove(dl, 0);
    dl_print(dl);
    puts("");

    // remove from the end of the list
    puts("Removing the tail of the list");
    dl_remove(dl, dl_size(dl) - 1);
    dl_print(dl);
    puts("");

    // remove from the middle of the list
    printf("Removing '%d' at index 1 from the list\n", dl_get(dl, 1));
    dl_remove(dl, 1);
    dl_print(dl);
    puts("");

    // remove the only remaining element in the list
    puts("Removing final two elements from the list");
    dl_remove(dl, 0);
    dl_print(dl);
    dl_remove(dl, 0);
    dl_print(dl);

    dl_del(&dl);
}

