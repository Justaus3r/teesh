#include "../include/command.h"
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>


size_t read_command_raw(Command* cmd){
    size_t cmd_len = (size_t)cmd->cmd_len;
    cmd->cmd_buffer = (char*)malloc(cmd_len);
    size_t read_bytes = read(STDIN_FILENO, cmd->cmd_buffer, cmd_len);
}

void __get_cmd_output(Command* cmd){
    struct termios backup_current_tty, toggle_rawmode;
    
    if(!(isatty(STDIN_FILENO))){
        return;
    }

    tcgetattr(STDIN_FILENO, &backup_current_tty);
    
    cfmakeraw(&toggle_rawmode);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &toggle_rawmode);
    
    write(STDOUT_FILENO, cmd->cmd_buffer, cmd->cmd_len);
    read(STDIN_FILENO, cmd->cmd_output, cmd->cmd_output_len);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &backup_current_tty);

}

CursorPosition get_cursor_position(int check_unicode){
    char cursor_pos_cmd[] = "\033[6n";
    char cursor_pos_cmd_unicode[] = "あ\033[6n";;
    int cmd_len = strlen( (check_unicode ? cursor_pos_cmd_unicode: cursor_pos_cmd) );
    int cmd_output_len =  CMD_OUT_LEN; 
    
    Command cmd = {
        .cmd_buffer = (check_unicode ? cursor_pos_cmd_unicode: cursor_pos_cmd),
        .cmd_len = cmd_len,
        .cmd_output_len = cmd_output_len
    };
    
    __get_cmd_output(&cmd);
    
    int line = (int)cmd.cmd_output[3] - 48;
    // for Cursor Column:
    // `- 48` : ascii code to decimal
    // `- 1`: to 0-index it
    int column = (int)cmd.cmd_output[5] - 48;
    --column;
    
    CursorPosition cp = {line, column};

    return cp; 
}

int is_unicode_supported(){
    // basically a heuristic to determine whether
    // terminal-emulator supports unicode. Basically 
    // will try to print a double byte character, if unicode
    // is supported, the cursor position will be moved by 2, otherwise
    // if its unsupported, it will be moved by 1

    CursorPosition cur_pos = get_cursor_position(1);
    return  ( (cur_pos.col == 2) ? 1:0) ;
}

PipeLocation* count_pipes(Command *cmd){
    /*
     * PipeLocation* basic structure
     *     
     *     0                    1                  2
     *   |pipe count|p|q| -> |pipe count|x|y| ->  ...    
     */

    // we assume the most popular int byte size: 4 and multiply with that MAX_FDS as we expect no more pipes than that
    size_t mem_size = 4 * MAX_FDS;
    PipeLocation *pipe_loc = (PipeLocation*)malloc(mem_size); 
    
    unsigned int pipe_count = 0; 
    unsigned int main_index = 0;
    unsigned int start = 0;
    unsigned int end = 0;
    int prev_pipe_idx = -1;
    
    while(1){
        
        
        if(cmd->cmd_buffer[main_index] == PIPE || cmd->cmd_buffer[main_index] == EOL){
            start = prev_pipe_idx + 1;
            end =  main_index - 1;
            prev_pipe_idx = main_index;
            
        
            pipe_loc[pipe_count].count = 0;
            pipe_loc[pipe_count].start = start;
            pipe_loc[pipe_count].end = end; 
            
            if(cmd->cmd_buffer[main_index] == EOL){
                break;
            }

            ++pipe_count;
        }

        ++main_index;

    }

    pipe_loc[0].count = pipe_count;
    return pipe_loc;
    
} 


