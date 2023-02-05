#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    pid_t chpid = fork();
    if(chpid == -1){
        printf("Error\n");
        return 0;
    }
    if(chpid == 0){
        int n;
        pid_t pid, ppid;
        pid = getpid();
        ppid = getppid();
        sscanf(argv[1], "%d", &n);
        if(n < 0 || n > 15){
            printf("I am a child, my pid = %d, my ppid = %d, my chpid = %d, n can't be less than 0 or greater than 15\n", (int)pid, (int)ppid, (int)chpid);
            return 0;
        }
        long long ans = 1;
        for(long long i = 2; i <= n; i++){
            ans*=i; 
        }
        printf("I am a child, my pid = %d, my ppid = %d, my chpid = %d, n = %d, n! = %lld\n", (int)pid, (int)ppid, (int)chpid, n, ans);
        return 0;
    }
        int n;
        pid_t pid, ppid;
        pid = getpid();
        ppid = getppid();
        sscanf(argv[1], "%d", &n);
        if(n < 1 || n > 60){
            printf("I am a parent, my pid = %d, my ppid = %d, my chpid = %d, n can't be less than 0 or greater than 60\n", (int)pid, (int)ppid, (int)chpid);
            return 0;
        }
        long long f_0 = 0;
        long long f_1 = 1;
        for(long long i = 2; i <= n; i++){
            long long cur = f_0 + f_1;
            f_0 = f_1;
            f_1 = cur; 
        }
        if(n == 1){
            f_1 = 0;
        }
        printf("I am a parent, my pid = %d, my ppid = %d, my chpid = %d, n = %d, f_n = %lld\n", (int)pid, (int)ppid, (int)chpid, n, f_1);
        return 0;
}
