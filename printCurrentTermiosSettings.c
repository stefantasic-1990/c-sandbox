#include <termios.h>
#include <unistd.h>
#include <stdio.h>

struct termios terminal_settings;

void is_flag_enabled(char* flag_name, unsigned int flag, unsigned int flag_group) {
    if (flag & flag_group) {
        printf("%s is enabled\n", flag_name);
    } else {
        printf("%s is disabled\n", flag_name);
    }
}

int main(int argc, char** argv) {
    tcgetattr(STDIN_FILENO, &terminal_settings);
    is_flag_enabled("ECHO", ECHO, terminal_settings.c_lflag);
}