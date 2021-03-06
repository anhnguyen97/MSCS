#ifndef _PROCESS_H
#define _PROCESS_H

#include "dllist.h"
#include "jval.h"
#include "simulator.h"
#include "mt.h"
#include "rb.h"
#include "jrb.h"

/** A queue to hold the ready processes */
Dllist readyq; 
JRB jrbTree;

#define SAVE_NONE   0
#define SAVE_QUEUED 1
#define SAVE        2

/** Process control block */
typedef struct P {
    int rgs[NumTotalRegs]; /* registers */
    char *buf;             /* write buffer */
    int buf_size;          /* write buffer size */
    int chars_written;     /* number of chars written */
    
    char *rbuf;            /* read buffer */ 
    int rbuf_size;         /* read buffer size */
    int rbuf_chars;        /* number of chars read */
 
    int sbrk;   
    
    int base;
    int limit;
 
    unsigned short pid;
    int mem_partition;
    
    struct P *parent;
    int exit;
     
    mt_sem waiter_sem;
    Dllist waiters;
   
    int save_state;        /* state of the pcb */
	JRB children;		// Step 21
} PCB;

/** The current process running */
PCB *cp;
/** The current process id */
unsigned short curpid;
/** Red black tree for storing the process ids */
Rb_node pids;

PCB *init;		// Step 22

/** memory partitions */
typedef struct partition {
    int base;
    int limit;
    int used;
} partition_t;

partition_t partitions[8];

/** Size of the console read buffer */
#define CRB_SIZE 256
/** Console read buffer, we maintain this as a cicular buffer */
int crb[CRB_SIZE];
/** I'm lazy so keep track of the no of chars, in the read buffer */
int crb_no_chars;
/** end of the circular buffer */
int crb_end;
/** the begining of the circular buffer */
int crb_begin;

mt_sem nelem;
mt_sem consoleWait;

/** The semaphore for console write synchronizarion */
mt_sem writeok;
/** The lock for preventing multiple processes writing */
mt_sem writers;
/** The lock for preventing multiple processes reading */ 
mt_sem readers;

PCB * new_pcb(); 
/** The scheduler function, it runs the next available process from 
readyq or runs noop if no process available */
void schedule();
/** Initialize the user process given by the file name */
void initialize_user_process(void *filename);
/** Save the current process registers */
void save_current_process();
/** Save the current process using the register values in the buffer */
void save_current_process_with_rgs(int buf[]);
/** Return from a syscall */
void syscall_return(PCB *p, int ret);
/** This is a thread method to collect charactors from the console */
void read_console(void *p);
/** initialize the partitions */
void init_partitions();
/** copy and create a new pcb */
PCB *copy_pcb(PCB *p);
/** get a new partition number */
int get_partition();
int get_new_pid();

/***** Sytem Calls *******/
/** Performs a console write */
void do_write(void *pv);
/** Performs a console read */
void do_read(void *pv);
/** This is a thread method to perform ioctl sys call */
void do_ioctl(void *p);
/** This is a thread method to perform fstat sys call */
void do_fstat(void *p);
/** This is a thread method to perform getpagesize sys call */
void do_getpagesize(void *p);
/** This is a thread method to perform getpagesize sys call */
void do_sbrk(void *p);
void do_execve(void *p);
void do_getpid(void *p);
void do_fork(void *p);
void do_exit(void *p);
void do_getdtablesize(void *p);
void do_getppid(void *pv);
void do_close(void *pv);
void do_wait(void *pv);

#endif
