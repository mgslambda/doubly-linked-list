dl_get_dl_insert_test: src/dlist.c test/dl_get_dl_insert_test.c
	mkdir -p bin
	gcc -o bin/dl_get_dl_insert_test src/dlist.c test/dl_get_dl_insert_test.c

dl_remove_test: src/dlist.c test/dl_remove_test.c
	mkdir -p bin
	gcc -o bin/dl_remove_test src/dlist.c test/dl_remove_test.c
