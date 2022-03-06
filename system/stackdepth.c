#include <xinu.h>

int stackdepth(void) {
//  struct procent	*proc = &proctab[currpid];
//  unsigned long	*esp, *ebp;
//
//  asm("movl %%esp, %0\n" :"=r"(esp));
//  asm("movl %%ebp, %0\n" :"=r"(ebp));
//  kprintf("[ebp 0x%08X] -> [esp 0x%08X]\n", ebp, esp);
//  kprintf("%10d bytes in stack segment\n", (uint32)&esp - (uint32)&ebp);
//  kprintf("%10d total bytes of stack\n", (uint32)&esp - (uint32)&proc->prstkbase);
//  kprintf("%10d total bytes of stack\n", (uint32)&proc->prstklen);
//  return 1;
		unsigned long *topsp, *topbp;
		asm ("movl %%esp, %0;movl %%ebp, %1;"
					:"=r"(topsp)	/* y is output operand */
					,"=r"(topbp));
		struct	procent *prptr;		/* Ptr to process' table entry	*/
		prptr = &proctab[(getpid())];
		unsigned long * processBase = (unsigned long *) prptr->prstkbase;
		int depth = 0;

		kprintf("\n ---------------------------------- \n");
		while(topbp!=processBase){
			kprintf("%10d bytes is size of stack frame at depth %d.\n",
					(uint32)topbp - (uint32)topsp, depth);
			kprintf("\n 0x%x ebp at depth %d ", topbp, depth );
			kprintf("\n ");
			topsp = topbp;
			topbp = *topbp;
			++depth;
		}
		if(depth > 0)
			depth = depth -1;
		return depth;
}
