#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int forkChildren(const char *whoami,int i)
{
        printf("I'm a %s %d PID is:%d  my parent id : is %d\n",
                        whoami, i,getpid(), getppid() );
        return 0;
}
int i=0;

int main(void)
{
        int n= 5;
        
        int status=0;


        printf("Creating %d children\n", n);
        int i=0;
        while(i<n)
        {
                pid_t pid=fork();

                if (pid==0) /* only execute this if child */
                {
                        forkChildren("child",i);
                        
                        exit(0);

                }
                wait(&status);  /* only the parent waits */
                i++;
        }



        return 0;
}
