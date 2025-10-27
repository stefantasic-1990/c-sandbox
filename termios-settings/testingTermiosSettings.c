#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int lineMaxSize = 1024;
    int linePosition = 0;
    char* line = malloc(sizeof(char) * lineMaxSize);

    struct termios initial_settings;
    struct termios modified_settings;
    
    if (isatty(STDIN_FILENO)) { 
        tcgetattr(STDIN_FILENO, &initial_settings);

        modified_settings = initial_settings;

        modified_settings.c_lflag &= ~(ICANON | ECHO);
        
        tcsetattr(STDIN_FILENO,TCSAFLUSH,&modified_settings);
    } else {
        return -1;
    }

    do {
        // read-in next character from the standard input stream
        char c;
        read(STDIN_FILENO, &c, 1);

        // if new line character reached then print to terminal
        // else append character to line buffer
        if (c == 10) {
            if (linePosition != 0) {
                write(STDOUT_FILENO, "The program received the following input: ", sizeof("The program received the following input: "));
                write(STDOUT_FILENO, line, linePosition);
                write(STDOUT_FILENO, "\x0a", sizeof("\x0a"));
                linePosition = 0;
            } else {
                tcsetattr(STDIN_FILENO,TCSAFLUSH,&initial_settings);
                exit(0);
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