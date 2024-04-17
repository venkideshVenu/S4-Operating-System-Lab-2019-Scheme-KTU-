
// Program to create a child process using system call fork() and to demonstrate the system calls getpid()


#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void main()
{
    int status, pid, child_pid;
    pid = fork();
    if ( pid == -1 )
    {
        printf("Child Process Creation Failed !!!\n");
        return 0;
    }
    else if ( pid == 0 )
    {
        printf("Inside Chlild Process with process ID : %d \n ",getpid());
        char *arg[] = {"Hello",NULL};
        execvp("./child",arg);
    }
    else
    {
        child_pid = wait(&status);
        printf("Inside the parent process with ID : %d \n ",getpid());
        printf("Child Process Created Successfully...\n");
    }
}

/*      Output

    Inside Child Process with process ID : 11967
    I'm child process
    Inside the parent process with ID : 11966
    Child process Created Successfully...
*/

