#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int lineMaxSize = 1024;
    int linePosition = 0;
    char* line = malloc(sizeof(char) * lineMaxSize);

    do {
        // read-in next character from the standard input stream
        char c;
        c = getchar();

        // if new line character reached then null terminate line string and print to terminal
        // else append character to line buffer
        if (c == 10) {
            if (linePosition != 0) {
                line[linePosition] = '\0';
                fputs("The program received the following input: ", stdout);
                fputs(line, stdout);
                fputs("\x0a", stdout);
                linePosition = 0;
            }
        } else {
            line[linePosition] = c;
            linePosition++;
        }

        // allocate more memory for the line buffer if reqiired
        if (linePosition >= lineMaxSize) {
        lineMaxSize += 1024;
        line = realloc(line, lineMaxSize);
        }
    } while (1);
}