#include <stdio.h>
static unsigned long *esp,*ebp;
void printtos(){
	asm("movl %esp,esp");
        asm("movl %ebp,ebp");
	unsigned long *sp,*fp;
	int i=0;
	asm("movl %esp,esp");
        asm("movl %ebp,ebp");
	sp=esp;
	fp=ebp;
	kprintf("\n\nQ3. Print TOP and BOTTOM of Run-Time Stack\n\n");
	kprintf("\nAddress of stack pointer before function call : %x \n",ebp+2);
	kprintf("\nAddress of stack pointer  after function call : %x \n",esp);
	for (;i <= 6; i++){
                kprintf("DATA (%08X) %08X (%d) \n", sp, *sp, *sp);
		sp++;
	}
}
