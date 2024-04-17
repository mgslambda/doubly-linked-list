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

int dl_get(DList *dl, size_t index) {
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
    Node *current = dl->header->next;
    for (size_t i = 0; i < index; i++)
        current = current->next;
    n->next = current;
    n->prev = current->prev;
    current->prev->next = n;
    current->prev = n;
    dl->size++;
}

int dl_remove(DList *dl, size_t index) {
    if (index >= dl_size(dl))
        _throw_error("Index out of bounds");
    Node *current = dl->header->next;
    for (size_t i = 0; i < index; i++)
        current = current->next;
    int val = current->val;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    dl->size--;
    return val;
}

void dl_print(DList *dl) {
    if (dl_is_empty(dl)) {
        puts("NULL");
    } else {
        Node *current = dl->header->next;
        printf("%s", "NULL<-");
        while (current != dl->trailer->prev) {
            printf("|%d|<->", current->val);
            current = current->next;
        }
        printf("|%d|->NULL\n", current->val);
    }
}

void dl_del(DList **dl) {
    while((*dl)->header->next != (*dl)->trailer) {
        Node *current = (*dl)->header->next;
        (*dl)->header->next = (*dl)->header->next->next;
        free(current);
    }
    free((*dl)->header);
    free((*dl)->trailer);
    free(*dl);
    *dl = NULL;
}

static void _throw_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

