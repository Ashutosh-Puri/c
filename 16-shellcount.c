/*
16. Write a C program that behaves like a shell (command interpreter). It has its own
prompt say “NewShell$”. Any normal shell command is executed from your shell by
starting a child process to execute the system program corresponding to the command. 
It should additionally interpret the following command. 
i) count c - print number of characters in file 
ii) count w - print number of words in file 
iii) count l - print number of lines in file
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char ss[40], tok1[10], tok2[10], tok3[10], tok4[10];
pid_t pid;
int fp;
char ch[1], ch1[100];
void sep()
{
    strcpy(tok1, "\0");
    strcpy(tok2, "\0");
    strcpy(tok3, "\0");
    strcpy(tok4, "\0");
    sscanf(ss, "%s%s%s%s", tok1, tok2, tok3, tok4);
}
void count()
{
    int cc = 0, wc = 0, lc = 0, j;
    fp = open(tok3, O_RDONLY);
    if (fp == -1)
        printf("error");
    else
    {
        while (read(fp, ch, 1) != 0)
        {
            printf("%c", ch[0]);
            if (ch[0] == ' ' || ch[0] == '\n' || ch[0] == '\t')
                wc++;
            else
                cc++;
            if (ch[0] == '\n')
                lc++;
        } 
        wc++;
        lc++;
        close(fp);
        if (strcmp(tok2, "c") == 0)
            printf("total number of characters= %d\n", cc);
        else if (strcmp(tok2, "w") == 0)
            printf("total number of words= %d\n", wc);
        else if (strcmp(tok2, "l") == 0)
            printf("total number of lines= %d\n", lc);
    }
}

int main()
{
    while(1)
    {
        printf("\nMyShell $");
        gets(ss);
        sep();
        pid = fork();
        if (pid == 0)
        {
            if (strcmp(tok1, "count") == 0)
                count();
            else
                printf("BAD COMMAND");
        } 
        else if (pid != 0)
        {
            waitpid(pid, NULL, 0);
            printf("parent process completed");
            exit(0);
        }
    }
}
