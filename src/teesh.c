#include "../include/command.h"
#include "stdio.h"

void main(){
    Command cmd = {};
    cmd.cmd_len = BUFF_LEN;
    cmd.cmd_buffer = "echo 'ASD' | grep 'A'";
   // read_command_raw(&cmd);
   // printf("%s", cmd.cmd_buffer);

    //CursorPosition cp = get_cursor_position();

    //printf("line, col: %d, %d", cp.row, cp.col);
    
    PipeLocation* pl = count_pipes(&cmd);
    
    for(int i=0;i<=pl[0].count; ++i){
        printf("---- FOR # %d ----\n", i);
        printf(" start: %d\n", pl[i].start);
        printf(" end: %d\n", pl[i].end);
        printf("-----------------\n");
    }

}
