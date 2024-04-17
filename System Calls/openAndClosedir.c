
// Implement program to demonstrate the system calls opendir and closedir

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *ptr2;
    char dir_name[50];
    printf("Enter the Directory :");
    scanf("%s",dir_name);
    dir = opendir(dir_name);
    while( (ptr2 = readdir(dir))!=NULL)
        printf("%ld \t %s \n",ptr2->d_ino,ptr2->d_name);
    closedir(dir);
    return 0;
}


/*
        Output

    Enter the Directory : test
    0        .
    0        ..
    0        empty.txt
*/