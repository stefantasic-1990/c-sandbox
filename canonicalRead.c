#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int lineMaxSize = 1024;
    int linePosition = 0;
    char* line = malloc(sizeof(char) * lineMaxSize);

    do {
        // read-in next character from the standard input stream
        int c;
        // c = getchar();
        read(STDIN_FILENO, &c, 1);

        // write(STDOUT_FILENO, "\x0a", sizeof("\x0a"));
        // write(STDOUT_FILENO, &c, sizeof(char));

        // if new line character reached then null terminate line string and print to terminal
        // else append character to line
        if (c == EOF || c == 13) {
            line[linePosition] = '\0';
            write(STDOUT_FILENO, "\x0a", sizeof("\x0a"));
            write(STDOUT_FILENO, "c", 1);
            // write(STDOUT_FILENO, line, sizeof(line));
            // write(STDOUT_FILENO, "\x0a", sizeof("\x0a"));
            linePosition = 0;
        } else {
            line[linePosition] = c;
            // write(STDOUT_FILENO, "c", 1);
            // write(STDOUT_FILENO, "\x0a", sizeof("\x0a"));
        }
        linePosition++;

        // allocate more memory for the line if reqiired
        if (linePosition >= lineMaxSize) {
        lineMaxSize += 1024;
        line = realloc(line, lineMaxSize);
        }
    } while (true);
}