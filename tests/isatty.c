#include <termios.h>
#include <unistd.h>
#include <stdio.h>

void main(){

    int res = isatty(STDIN_FILENO);


    printf("%d", res);

}
