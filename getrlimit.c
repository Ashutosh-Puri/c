#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;

    getrlimit(RLIMIT_NOFILE, &rlim);

    printf("Current soft limit: %ld\n", rlim.rlim_cur);
    printf("Current hard limit: %ld\n", rlim.rlim_max);

    rlim.rlim_cur = 1024;
    setrlimit(RLIMIT_NOFILE, &rlim);

    getrlimit(RLIMIT_NOFILE, &rlim);
    
    printf("New soft limit: %ld\n", rlim.rlim_cur);
    printf("New hard limit: %ld\n", rlim.rlim_max);

    return 0;
}
