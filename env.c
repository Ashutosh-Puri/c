
// 9. Write a C program to display as well as resets the environment variable such as path, home, root

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    printf(" Old ROOT: %s\n", getenv("ROOT"));
    setenv("ROOT", "/root", 1);
    printf(" New ROOT: %s\n", getenv("ROOT"));       
}