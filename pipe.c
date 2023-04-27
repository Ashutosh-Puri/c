// 2. To generate parent process to write unnamed pipe and will read from it.
#include <stdio.h>
#include <unistd.h>
int main()
{
    int pipefds[2];
    
    char w[] ="Hello";
    char r[20];
    if (pipe(pipefds) == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }
    write(pipefds[1], w, sizeof(w));
    read(pipefds[0], r, sizeof(r));
    printf("Reading from pipe Message is %s\n", r);
    
    return 0;
}
