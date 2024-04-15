#ifndef _DLIST_H
#define _DLIST_H

#include <stddef.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} Node;

struct dlist {
    Node *header;
    Node *trailer;
    size_t size;
};

#endif

