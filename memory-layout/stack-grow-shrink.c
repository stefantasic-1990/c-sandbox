#include <stdio.h>

void print_rsp_rbp()
{
    printf("\n"); 
    void *rbp;
    __asm__("movq %%rbp, %0" : "=r"(rbp));
    printf("Base pointer address: %p\n", rbp);

    void *rsp;
    __asm__("movq %%rsp, %0" : "=r"(rsp));
    printf("Stack pointer address: %p\n", rsp);
    printf("\n");    
}

void bar()
{
    printf("Executing bar()...");
    print_rsp_rbp(); 
}

void foo()
{
    printf("Executing foo()...");
    print_rsp_rbp();

    bar();

    printf("Resuming execution of foo()...");
    print_rsp_rbp();    
}

int main(void)
{
    printf("Executing main()...");
    print_rsp_rbp();

    foo();

    printf("Resuming execution of main()...");
    print_rsp_rbp();
}