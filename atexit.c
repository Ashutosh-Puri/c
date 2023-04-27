/*
7. To demonstrate the use of atexit() function.
*/
#include <stdio.h>
#include <stdlib.h>

void A() 
{
   printf("This is function A\n");
}

int main () {
   
   atexit(A);
   
   printf("Exiting main program...\n");

   return 0;
}