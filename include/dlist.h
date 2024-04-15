#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>

typedef struct dlist DList;
extern DList *dl_init();
extern size_t dl_size(DList *dl);
extern size_t dl_is_empty(DList *dl);
extern int dl_get(DList *dl, size_t index);
extern void dl_insert(DList *dl, size_t index, int val);  // handle getting tail quickly here, instead of separate function
extern int dl_remove(DList *dl, size_t index);  // same as above
extern void dl_print(DList *dl);
extern void dl_del(DList *dl);

#endif

