1. /* signal example #1: trap an illegal address reference 
信号量范例：捕获一个非法的地址引用

*/

#include <stdio.h>	/* for printf */
#include <stdlib.h>	/* for exit */
#include <signal.h>	/* defines signals and the signal() function */

main(int argc, char **argv) {
	void catch(int);                     //声明一个函数变量
	int a;

     signal(SIGSEGV, catch);	
    /* catch SIGSEGV 
     捕捉段错误信号，调用catch函数打印信息 - segmentation violation 段错误*/

	a = *(int *)0;	   /* read address 0 读地址0x0000000h处的信息 */
}

void
catch(int snum) {
	printf("got signal %d\n", snum);
	exit(0);
}
