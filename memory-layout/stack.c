#include <stdio.h>

#define PRINT_RSP_RBP                                      \
    do {                                                   \
        void *rbp, *rsp;                                   \
        __asm__("movq %%rbp, %0" : "=r"(rbp));             \
        __asm__("movq %%rsp, %0" : "=r"(rsp));             \
        printf("\nBase pointer address: %p\n", rbp);       \
        printf("Stack pointer address: %p\n\n", rsp);      \
    } while (0)

void bar(void)
{
    printf("Executing bar()...");
    PRINT_RSP_RBP;
}

void foo(void)
{
    printf("Executing foo()...");
    PRINT_RSP_RBP;

    bar();

    printf("Resuming execution of foo()...");
    PRINT_RSP_RBP;
}

int main(void)
{
    printf("\nExecuting main()...");
    PRINT_RSP_RBP;

    foo();

    printf("Resuming execution of main()...");
    PRINT_RSP_RBP;
}