#include <stddef.h>

#include <sys/mman.h>

#include "myalloc.h" // This include should appear last


extern int myinit(size_t size) {
    return 1;
}


extern int mydestroy() {
    return 1;
}

extern void* myalloc(size_t size){
    _arena_start = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    return;
}

extern void myfree(void *ptr) {
    return;
}