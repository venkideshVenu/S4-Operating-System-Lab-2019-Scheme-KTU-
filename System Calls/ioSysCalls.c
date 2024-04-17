
// Implement program to read and display the contents of a file using I/O system calls

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{
    int fd,fd2;
    char wbuf[128],rbuf[128];
    fd = open("file.txt",O_RDWR);
    printf("Enter The Text to be Written : \n\n");
    scanf("%[^\n]s",wbuf);
    write(fd,wbuf,strlen(wbuf));
    close(fd);
    fd2 = open("file.txt",O_RDWR);
    printf("\n The Contents are :\n\n");
    read(fd2,rbuf,100);
    printf("%s\n",rbuf);
    close(fd2);
    return 0;
}


/*
    Output

    Enter The Text to be Written :

    Hello, Welcome to OS Lab

    The Contents are :

    Hello, Welcome to OS Lab
    
*/