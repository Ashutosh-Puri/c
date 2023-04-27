/*
3. To create a file with hole in it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main() {
    int fd;
    char buf[10] = "ashu"; 

    fd = open("ashu.txt", O_WRONLY | O_CREAT , 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (write(fd, buf, sizeof(buf)) == -1) {
        perror("write");
        exit(1);
    }

    if (lseek(fd, 100/ 2, SEEK_SET) == -1) {
        perror("lseek");
        exit(1);
    }

    if (write(fd, buf, sizeof(buf)) == -1) {
        perror("write");
        exit(1);
    }

    close(fd);

    return 0;
}
