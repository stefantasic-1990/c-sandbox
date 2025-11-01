#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_break(void)
{
    void *brk = sbrk(0);
    printf("The program break address is: %p\n", brk);
}

void *allocate(int bytes)
{
    void *ptr = malloc(bytes);
    printf("\nAllocated %i bytes of memory starting at address: %p\n", bytes, ptr);
    print_break();

    return ptr;
}

void *release(void *ptr)
{
    free(ptr);
    printf("\nFreed memory starting at address: %p\n", ptr);
    print_break();
}

int main(void)
{
    print_break();
    void *a = allocate(1);
    void *b = allocate(25);
    void *c = allocate(24);
    void *d = allocate(8);
    release(a);
    void *e = allocate(12);
}