#ifndef CONSTANTS_H
#define CONSTANTS_H


#define UTIL_VERSION "0.1.0"

// cap it to 128k | 32 pages, hardcorded linux value: https://unix.stackexchange.com/questions/120642/what-defines-the-maximum-size-for-a-command-single-argument
#define BUFF_LEN 128*1024 

// 'https://stackoverflow.com/a/34480326/14734918' suggests that 
// /proc/sys/fs/file-max gives the maximum number of file descriptors
// that can be opened . But we won't follow that, we assign an arbitrary number, 
// that can later be changed , if needed
#define MAX_FDS 2048 


// max cmd output len for ansi codepoint commands execution
// we arite these ansi codepoints to stdout and read the output
// to get various terminal related traits like cursor position , etc
#define CMD_OUT_LEN 1024

#define PIPE '|'

#define EOL '\0'

#endif // CONSTANTS_H
       
