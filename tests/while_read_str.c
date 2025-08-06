#include <stdio.h>
#include <stdlib.h>


void main(){
    
    char* sample_str = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
    
    int count = 0;

    while(1){
        if(sample_str[count] == '\0'){
            break;
        }
        printf("%c", sample_str[count]);
        ++count;
    }

}
