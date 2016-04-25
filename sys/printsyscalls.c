#include <kernel.h>
#include <proc.h>
int syscallsummary_flag=1;
int call_pid[NPROC]={0},call_wait[NPROC]={0},call_signal[NPROC]={0},call_time[NPROC]={0},call_sleep[NPROC]={0},call_kill[NPROC]={0};
void syscallsummary_start(){
	int i=0;
	if(syscallsummary_flag==1){
		kprintf("\n\nQ5.Starting System Call Trace\n\n");
		for(;i<NPROC;i++){
			call_pid[i]=0;
			call_wait[i]=0;
			call_signal[i]=0;
			call_time[i]=0;
			call_sleep[i]=0;
			call_kill[i]=0;
		}
		syscallsummary_flag = 0;
	}
}
void syscallsummary_stop(){
	syscallsummary_flag=1;
}
void printsyscalls(){
	int i=0,pid;
	kprintf("\n\nQ5.System Call Trace Summary\n\n");
	for(;i<numproc;i++){
		pid = NPROC-i-1;
		kprintf("\n Process PID : %d\n",pid);
		kprintf("\nNo. of getpid() calls : %d\n",call_pid[pid]);
		kprintf("\nNo. of gettime(timvar) calls : %d\n",call_time[pid]);
		kprintf("\nNo. of kill(pid) calls : %d\n",call_kill[pid]);
		kprintf("\nNo. of signal(sem) calls : %d\n",call_signal[pid]);
		kprintf("\nNo. of sleep(n) calls : %d\n",call_sleep[pid]);
		kprintf("\nNo. of wait(sem) calls : %d\n",call_wait[pid]);
	}
}
