#define _GNU_SOURCE
#include <sys/mman.h>
#include <unistd.h>
#include "myalloc.h" 

void* arena_start = NULL;
size_t arena_size = 0;

int myinit(size_t size) {
    if (arena_start != NULL) {
        return ERR_CALL_FAILED; // Already initialized
    }

    // Adjust the arena size to be a multiple of the page size
    size_t page_size = getpagesize();
    
    size = (size + page_size - 1) / page_size * page_size;

    // Use mmap to request a large memory area from the OS
    arena_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (arena_start == MAP_FAILED) {
        return ERR_BAD_ARGUMENTS;

    }

    arena_size = size;

    return arena_size;
}

int mydestroy() {
    if (arena_start == NULL) {
        return ERR_UNINITIALIZED;
    }

    // Use munmap to deallocate the memory allocated by mmap
    int tmp = munmap(arena_start, arena_size);

    // Reset state variables
    arena_start = NULL;
    arena_size = 0;

    return tmp;
}

void* myalloc(size_t size) {
    //  myalloc implementation goes here
}

void myfree(void *ptr) {
    //  myfree implementation goes here
}
