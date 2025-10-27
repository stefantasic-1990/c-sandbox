#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void foobar(int *main_int, double *main_double, int main_arr[])
{
    int foobar_int = 5;
    char foobar_char_arr[20];

    void *rsp;
    __asm__("movq %%rsp, %0" : "=r"(rsp));
    printf("Foobar() stack pointer: %p\n", rsp);

    void *rbp;
    __asm__("movq %%rbp, %0" : "=r"(rbp));
    printf("Foobar() base pointer: %p\n", rbp);
    printf("\n");

    printf("Foobar() stack addresses:\n");
    printf("  foobar_int         : %p\n", (void*)&foobar_int);
    printf("  foobar_char_arr[0] : %p\n", (void*)&foobar_char_arr[0]);
    printf("  foobar_char_arr[1] : %p\n", (void*)&foobar_char_arr[1]);
    printf("\n");

    printf("Main() stack values in Foobar():\n");
    printf("  main_int         : %i\n", *main_int);
    printf("  main_double      : %f\n", *main_double);
    printf("  main_arr[0]      : %i\n", main_arr[0]);
    printf("  main_arr[1]      : %i\n", main_arr[1]);
    printf("\n");
}

int main(void)
{
    int main_int = 10;
    double main_double = 2.3;
    int main_int_arr[10];
    main_int_arr[0] = 7;
    main_int_arr[1] = 3;

    void *rsp;
    __asm__("movq %%rsp, %0" : "=r"(rsp));
    printf("Main() stack pointer: %p\n", rsp);

    void *rbp;
    __asm__("movq %%rbp, %0" : "=r"(rbp));
    printf("Main() base pointer: %p\n", rbp);
    printf("\n");


    printf("Main() stack addresses:\n");
    printf("  main_int           : %p\n", (void*)&main_int);
    printf("  main_double        : %p\n", (void*)&main_double);
    printf("  main_int_arr[0]    : %p\n", (void*)&main_int_arr[0]);
    printf("  main_int_arr[1]    : %p\n", (void*)&main_int_arr[1]);
    printf("\n");

    foobar(&main_int, &main_double, main_int_arr);
    pause();
}