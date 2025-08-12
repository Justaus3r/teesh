#ifndef COMMAND_H
#define COMMAND_H

#include "./constants.h"
#include <stddef.h>

typedef struct {
    char* cmd_buffer;
    unsigned long int cmd_len;
    char cmd_output[CMD_OUT_LEN];
    unsigned int cmd_output_len;
} Command;


typedef struct {
    int row;
    int col;
} CursorPosition;


typedef struct {
    unsigned int count;
    unsigned int start;
    unsigned int end;
} PipeLocation; 

typedef enum {
     NONE = 0,
     LEADING,
     TRAILING,
     BOTH,
} SpaceCheck; 

size_t read_command_raw(Command* cmd);


void __get_cmd_output(Command*);
CursorPosition get_cursor_position(int check_unicode);

int is_unicode_supported();

PipeLocation* count_pipes(Command*);

SpaceCheck __check_whitespaces(unsigned int, unsigned int, char*);
void populate_command_store(Command*, Command**, PipeLocation*);

#endif // COMMAND_H
