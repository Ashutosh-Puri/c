// Write a C program to display the given message ‘n’ times. (make a use of setjmp and longjmp
// system call)

#include <stdio.h>
#include <setjmp.h>
jmp_buf buf;

int main()
{

    if (setjmp(buf))
    {
         printf("Set Jump\n");
    }
    else
    {
        printf("Before Long\n");
    longjmp(buf,1);
    printf("After Long\n");
    }
    
    return 0;
}