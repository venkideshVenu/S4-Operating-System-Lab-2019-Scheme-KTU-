
// Implement a program to demostrate the system call stat

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
int main()
{
    char file[10];
    struct stat * node = malloc(sizeof(struct stat));
    printf("Enter the File Name : ");
    scanf("%s",file);
    stat(file,node);
    if ( node->st_ino == 0 )
       printf("File Does not Exist !!!\n");
    else
    {
        printf("\nNode : Serial Number : %ld ",node->st_ino);
        printf("\nBlock Size : %ld ",node->st_blksize);
        printf("\nAccess Time : %ld ",node->st_atime);
        printf("\nLast Modified Time : %ld ",node->st_mtime);
        printf("\nGroup ID : %d ",node->st_gid);
        printf("\nSize of File : %ld ",node->st_size);
        printf("\nPermissions : %d ",node->st_mode);
        printf("\nUser ID : %d ",node->st_uid);
    }
    return 0;
}


/*
    Output

    Enter the File Name : file.txt
    Node : Serial Number : 1584201
    Block Size : 4096
    Access Time : 1708323315
    Last Modified Time : 1708323293
    Group ID : 1000
    Size of File : 29
    Permissions : 33204
    User ID : 1000

*/