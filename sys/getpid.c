/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	if(syscallsummary_flag==0)
		call_pid[currpid]++;
	return(currpid);
}
