#include <stddef.h>
#include "myalloc.h" // This include should appear last


extern int myinit(size_t size) {
    return 1;
}


extern int mydestroy() {
    return 1;
}

extern void* myalloc(size_t size){
    return;
}

extern void myfree(void *ptr) {
    return;
}