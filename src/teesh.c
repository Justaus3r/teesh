#include "../include/command.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

void main(){
    Command cmd = {
    .cmd_buffer = " echo 'ASD' | grep 'A' | grep 'B'",
    .cmd_len = strlen(cmd.cmd_buffer), 
    .cmd_output_len = 0
    };
    strcpy(cmd.cmd_output, "");
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
     
    unsigned int cmd_count = pl[0].count;
    Command **command_store = (Command**)malloc(sizeof(Command*) * 3);
    
    populate_command_store(&cmd, command_store, pl);
    
    Command *c = command_store[2];

    printf("\n-----\n%s\n", c->cmd_buffer); 

    /*
    printf("%d\n", strlen(command_store[0]->cmd_buffer));
    for(int i=0; i<strlen(command_store[0]->cmd_buffer); ++i){
       printf("%c", command_store[0]->cmd_buffer[i]);
    }
    */
    /* 
    for(int i=0;i<cmd_count;++i){
        Command *c = command_store[i]; 
        printf("%s\n", c->cmd_buffer);
    }
    */
    free(command_store);
}
