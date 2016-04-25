/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
extern long zfunction(long param);
void halt();
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
unsigned long *esp;
int main()
{
	syscallsummary_start();
	unsigned long *prA,*prB,*prC;
	kprintf("\n\nHello World, Xinu lives\n\n");
	getpid();
	getpid();
	getpid();
	sleep(0);
	sleep(0);
	sleep(0);
	wait(1);
	signal(1);
	kprintf("%x",zfunction(0xaabbccdd));
	printsegaddress();
	asm("movl %esp, esp");
	kprintf("le wild : %x\n",esp);
	printtos();
	kill(46);
	printprocstks(80);
	syscallsummary_stop();
	printsyscalls();
	return 0;
}
