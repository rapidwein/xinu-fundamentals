#include<conf.h>
#include<kernel.h>
#include <stdio.h>
#include <proc.h>
unsigned long *esp,*ebp;
void printprocstks(int priority){
	int i=NPROC-1,j=0,k=1;
	struct pentry	*proc = &proctab[i];
	kprintf("\n\nQ4.Print Process Table Details\n\n");
	while(j<numproc){
		if(proc->pprio<priority && proc->pstklen !=0){
			kprintf("\n%d. Process Name : %s\n",(k),proc->pname);
			kprintf("\nProcess ID       : %d\n",i);
			kprintf("\nProcess Priority : %d\n",proc->pprio);
			kprintf("\nStack base       : %x\n",proc->pbase);
			kprintf("\nStack size       : %x\n",proc->pstklen);
			kprintf("\nStack limit      : %x\n",proc->plimit);
			if(i==currpid){
				asm("movl %esp, esp");
				asm("movl %ebp, ebp");
				kprintf("\nStack pointer    : %x\n",esp);
				kprintf("\nStack size       : %x\n",(ebp-esp));
			}
			else
				kprintf("\nStack pointer    : %x\n",proc->pesp);
				kprintf("\nStack size      : %x\n",proc->pstklen);
			k++;
		}
		i--;
		j++;
		proc = &proctab[i];
	}
}
