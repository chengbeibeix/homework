/* Program that shows how fork system call works 
 程序说明创建子进程，在父进程和子进程分别打印信息
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;
    /*声明新的线程号*/
    printf("--- There is only one process now. ---\n");
    printf("--- going to call fork() ... ---\n");

    if ((pid = fork()) < 0) {                   //pid<0,创建子进程失败
        perror("fork error");
        exit(1);
    }
/*
一个现有进程可以调用fork函数创建一个新进程。由fork创建的新进程被称为子进程（child process）。fork函数被调用一次但返回两次。两次返回的唯一区别是子进程中返回0值而父进程中返回子进程ID。
*/
    if (pid == 0) {
      /* 
       *  Now we are in the childs process 
         pid==0 处于子进程
       */
        printf("    This message is printed by the child process. >>>\n");
    } else {
      /* 
       * Now we are in the parent process
        pid>0处于父进程
       */
        printf("<<< PARENT PROCESS.\n");
    }
    printf("=== The End ===\n");
    return(0);
}
