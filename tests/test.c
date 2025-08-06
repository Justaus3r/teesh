#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


void main(){
    char cmd[] = "echo -e '\033[6n'";
    int cmd_len = strlen(cmd);
    
    char cmd_out[128];
    int cmd_out_len = 128;

    struct termios save_curr, raw_mode;
    printf("TEST");
    tcgetattr(STDIN_FILENO, &save_curr);

    cfmakeraw(&raw_mode);

    tcsetattr(STDIN_FILENO, TCSANOW, &raw_mode);
    
    write(STDOUT_FILENO, cmd, cmd_len);

    read(STDIN_FILENO, cmd_out, cmd_out_len);

    tcsetattr(STDIN_FILENO, TCSANOW, &save_curr);
    

    printf("\n%c, %c", cmd_out[2], cmd_out[4]);
    return;

    for(int i=0; i<strlen(cmd_out); ++i){
        printf("%c", cmd_out[i]);
    }

}
