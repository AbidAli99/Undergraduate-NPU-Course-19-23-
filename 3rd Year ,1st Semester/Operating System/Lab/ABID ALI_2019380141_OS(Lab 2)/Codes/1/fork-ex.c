#include   <unistd.h> // need this for fork
#include   <sys/types.h>
#include   <stdio.h> // need this for printf and fflush

int i = 10;
double x =3.14159;
//double x = 6.8;
int pid;
int main (int argc, char* argv[])
{

    int j = 2;
    double y = 0.12345;
    //double y = 4.4;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    if (pid > 0)
    {
        // parent code
        double x = 6.8;
        double y = 4.4;
        int i =6;
        printf("parent process -- pid= %d\n", getpid());
        fflush(stdout);
        printf("parent sees: i= %d, x= %lf\n", i, x);
        fflush(stdout);
        printf("parent sees: j= %d, y= %lf\n", j, y);
        fflush(stdout);
    }
    else
    {
        // child code
        printf("child process -- pid= %d\n", getpid());
        fflush(stdout);
        printf("child sees: i= %d, x= %lf\n", i, x);
        fflush(stdout);
        printf("child sees: j= %d, y= %lf\n", j, y);
        fflush(stdout);
    }

    return(0);
}

