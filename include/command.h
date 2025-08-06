#ifndef COMMAND_H
#define COMMAND_H

#include "./constants.h"
#include <stddef.h>

typedef struct {
    char* cmd_buffer;
    unsigned long int cmd_len;
    char cmd_output[CMD_OUT_LEN];
    int cmd_output_len;
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

size_t read_command_raw(Command* cmd);

static Command* COMMAND_STORE[MAX_FDS];

CursorPosition get_cursor_position(int check_unicode);

int is_unicode_supported();

PipeLocation* count_pipes(Command*);

void populate_command_store(Command*);

#endif // COMMAND_H
