/*
    A little program to print the integer values of the bytes received through terminal input in canonical mode.
    When you run this program, the line discipline will buffer the input until you press enter.
    This program will then print out the integer values of each byte received in order including the newline.
*/

#include <unistd.h>
#include <stdio.h>

int main() {

    do {
        char c;
        ssize_t bytes_read;

        // read a single byte from standard input
        bytes_read = read(STDIN_FILENO, &c, 1);

        // print the int value of the received character
        printf("Received byte int value: %d\n", c);
    } while (1);
}