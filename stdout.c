/*10.Write a C program that redirects standard output to a file output.txt. (use of dup and open
system call).*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
 
    int fd = open("stdout.c", O_WRONLY | O_APPEND);
    if (fd < 0)
        printf("Error opening the file\n");
    int cd = dup(fd);
    write(cd, " copy dup.txt  \n", 46);
    write(fd, " dup.txt   \n", 51);
    return 0;
}
