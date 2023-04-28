// 4. Write a C Program that demonstrates redirection of standard output to a file.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int out = open("cout.log", O_RDWR | O_CREAT | O_APPEND, 0644);
    int save_out = dup(fileno(stdout));
    dup2(out, fileno(stdout));
    puts("doing an ls or something now");
    fflush(stdout);
    close(out);
    dup2(save_out, fileno(stdout));
    close(save_out);
    puts("back to normal output");
    return 0;
}
