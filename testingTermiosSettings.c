#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void is_flag_enabled(char* flag_name, unsigned int flag, unsigned int flag_group) {
    if (flag & flag_group) {
        printf("%s is enabled\n", flag_name);
    } else {
        printf("%s is disabled\n", flag_name);
    }
}

int main(int argc, char** argv) {
    int lineMaxSize = 1024;
    int linePosition = 0;
    char* line = malloc(sizeof(char) * lineMaxSize);

    struct termios initial_terminal_settings;
    struct termios modified_terminal_settings;
    
    // is_flag_enabled();
    
    if (isatty(STDIN_FILENO)) { 
        tcgetattr(STDIN_FILENO, &initial_terminal_settings);

        modified_terminal_settings = initial_terminal_settings;

        modified_terminal_settings.c_iflag &= ~0;
        modified_terminal_settings.c_oflag &= ~0;
        modified_terminal_settings.c_lflag &= ~0;

        // modified_terminal_settings.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        // modified_terminal_settings.c_oflag &= ~(OPOST);
        // modified_terminal_settings.c_lflag &= ~(ECHO);
        // modified_terminal_settings.c_cflag |= (CS8);
        // modified_terminal_settings.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        // modified_terminal_settings.c_cc[VMIN] = 1; 
        // modified_terminal_settings.c_cc[VTIME] = 0;
        
        tcsetattr(STDIN_FILENO,TCSAFLUSH,&modified_terminal_settings);
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
                tcsetattr(STDIN_FILENO,TCSAFLUSH,&initial_terminal_settings);
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