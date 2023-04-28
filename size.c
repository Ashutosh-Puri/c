/*
9. To print the size of the file.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("size.c", "r"); 
    fseek(fp, 0L, SEEK_END);
    printf("File Size : %ld bytes\n", ftell(fp));
    fclose(fp);
    return 0;
}
