/*Write a C program to create ‘n’ children. When the children will terminate,
display total cumulative time children spent in user and kernel mode*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, status;
    pid_t pid;
    time_t currentTime;
    struct tms cpuTime;
    if ((pid = fork()) == -1)
    {
        perror("\nfork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        time(&currentTime);
        printf("\nChild process started at %s", ctime(&currentTime));
        for (i = 0; i < 5; i++)
        {
            printf("\nCounting= %d \n", i);
            sleep(1);
        }
        time(&currentTime);
        printf("\nChild process ended at %s", ctime(&currentTime));
        exit(EXIT_SUCCESS);
    }
    else
    {
        time(&currentTime);
        printf("\nParent process started at %s ", ctime(&currentTime));
        if (wait(&status) == -1)
            perror("\n wait error");
        if (WIFEXITED(status))
            printf("\nChild process ended normally");
        else
            printf("\nChild process did not end normally");
        if (times(&cpuTime) < 0)
            perror("\nTimes error");
        else
        {
            printf("\nParent process user time= %fn", ((double)cpuTime.tms_utime));
            printf("\nParent process system time = %fn", ((double)cpuTime.tms_stime));
            printf("\nChild process user time = %fn", ((double)cpuTime.tms_cutime));
            printf("\nChild process system time = %fn", ((double)cpuTime.tms_cstime));
        }
        time(&currentTime);
        printf("\nParent process ended at %s", ctime(&currentTime));
        exit(EXIT_SUCCESS);
    }
}
