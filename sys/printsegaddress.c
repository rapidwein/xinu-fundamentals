#include <stdlib.h>
extern int _end,_etext,_edata,end,etext,edata;
void printsegaddress(){
	kprintf("\n\nQ2. Print End of Different Segmemts\n\n");
	kprintf("    program text (_etext)   :    %x\n", &_etext);
	kprintf("    content before etext at %x : %x\n", (&_etext-1),*(&_etext-1));
	kprintf("    content after etext at %x : %x\n", (&_etext),*(&_etext));
	kprintf("    initialized data (_edata)  : %x\n", &_edata);
	kprintf("    content before edata at %x : %x\n", (&_edata-1),*(&_edata-1));
	kprintf("    content after edata at %x : %x\n", (&_edata),*(&_edata));
	kprintf("    uninitialized data (_end):  %x\n", &_end);
	kprintf("    content before end at %x : %x\n", (&_end-1),*(&_end-1));
	kprintf("    content after end at %x : %x\n", (&_end),*(&_end));
}
