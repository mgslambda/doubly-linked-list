#include <stdio.h>
#include <stdlib.h>
#include "../include/_dlist.h"
#include "../include/dlist.h"

static void _throw_error(char *msg);

DList *dl_init() {
    DList *dl = malloc(sizeof *dl);
    if (dl == NULL)
        _throw_error("Could not allocate memory for list");
    dl->header = malloc(sizeof *dl->header);
    dl->trailer = malloc(sizeof *dl->trailer);
    if (dl->header == NULL || dl->trailer == NULL)
        _throw_error("Could not allocate memory for list");
    dl->header->next = dl->trailer;
    dl->trailer->prev = dl->header;
    dl->size = 0;
    return dl;
}

size_t dl_size(DList *dl) {
    return dl->size;
}

size_t dl_is_empty(DList *dl) {
    return dl_size(dl) == 0;
}

int dl_get(DList *dl, size_t index) {  // TODO: Depending on index, start traversing from head or tail so that the number of elements traversed is at most n/2
    if (index >= dl_size(dl))
        _throw_error("dl_get: Index out of bounds");
    if (index == dl_size(dl) - 1)  // Constant time access to tail element
        return dl->trailer->prev->val;
    Node *current = dl->header->next;
    for (size_t i = 0; i < index; i++)
        current = current->next;
    return current->val;
}

void dl_insert(DList *dl, size_t index, int val) {
    if (index > dl_size(dl))
        _throw_error("Index out of bounds");
    Node *n = malloc(sizeof *n);
    if (n == NULL)
        _throw_error("Could not allocate memory for list node");
    n->val = val;
    if (dl_is_empty(dl)) {
        n->prev = dl->header;
        n->next = dl->trailer;
        dl->header->next = n;
        dl->trailer->prev = n;
    } else {
        Node *current = dl->header->next;
        for (size_t i = 0; i < index; i++)
            current = current->next;
        n->next = current;
        n->prev = current->prev;
        current->prev->next = n;
        current->prev = n;
    }
    dl->size++;
}

static void _throw_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

