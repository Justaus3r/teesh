#include "../include/command.h"
#include "stdio.h"
#include <string.h>

void main(){
    Command cmd = {};
    cmd.cmd_buffer = " echo 'ASD' | grep 'A' | grep 'B'";
    cmd.cmd_len = strlen(cmd.cmd_buffer);
   // read_command_raw(&cmd);
   // printf("%s", cmd.cmd_buffer);

    //CursorPosition cp = get_cursor_position();

    //printf("line, col: %d, %d", cp.row, cp.col);
    
    PipeLocation* pl = count_pipes(&cmd);
    
    /* 
    for(int i=0;i<=pl[0].count; ++i){
        printf("---- FOR # %d ----\n", i);
        printf(" start: %d\n", pl[i].start);
        printf(" end: %d\n", pl[i].end);
        printf("-----------------\n");
    }
    */

    populate_command_store(&cmd, pl);
    
    unsigned int cmd_count = pl[0].count;
    
    //for(int i=0;i<cmd_count;++i){
        //Command* c = COMMAND_STORE[0]; 
        //printf("%s\n", c->cmd_buffer);
    //}
}
