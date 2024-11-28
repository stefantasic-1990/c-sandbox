#include <termios.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int lineMaxSize = 1024;
    int linePosition = 0;
    char* line = malloc(sizeof(char) * lineMaxSize);

    struct termios initial_terminal_settings;
    struct termios modified_terminal_settings;
    
    if (isatty(STDIN_FILENO)) { 
        tcgetattr(STDIN_FILENO, &initial_terminal_settings);

        modified_terminal_settings = initial_terminal_settings;
        modified_terminal_settings.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        modified_terminal_settings.c_oflag &= ~(OPOST);
        modified_terminal_settings.c_cflag |= (CS8);
        modified_terminal_settings.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        modified_terminal_settings.c_cc[VMIN] = 1; 
        modified_terminal_settings.c_cc[VTIME] = 0;
        
        tcsetattr(STDIN_FILENO,TCSAFLUSH,&modified_terminal_settings);
    } else {
        return -1;
    }

    do {
        // read-in next character from the standard input stream
        char c;
        c = getchar();

        // if new line character reached then null terminate line string and print to terminal
        // else append character to line
        if (c == 10) {
            if (linePosition != 0) {
                line[linePosition] = '\0';
                fputs("The program received the following input: ", stdout);
                fputs(line, stdout);
                fputs("\x0a", stdout);
                linePosition = 0;
            } else {
                tcsetattr(STDIN_FILENO,TCSAFLUSH,&initial_terminal_settings);
                exit();
            }
        } else {
            line[linePosition] = c;
            linePosition++;
        }

        // allocate more memory for the line if reqiired
        if (linePosition >= lineMaxSize) {
        lineMaxSize += 1024;
        line = realloc(line, lineMaxSize);
        }
    } while (1);

}