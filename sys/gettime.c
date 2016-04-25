/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <date.h>
#include <lab0.h>
extern int getutim(unsigned long *);
/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
    if(syscallsummary_flag==0)
    	call_time[currpid]++;
    return OK;
}
