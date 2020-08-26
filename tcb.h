#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <string.h>

typedef struct tcb_q{
	int thread_id;
	ucontext_t ucontext;
	struct tcb_q *next;
	struct tcb_q *prev;
}tcb_q;

void init_TCB(tcb_q *tcb, void *function, void *stackP, int stack_size)
{
	static int counter = 1;
	 memset(tcb, 0, sizeof(tcb_q));       
	 getcontext(&tcb->ucontext);
	 tcb->ucontext.uc_stack.ss_sp = stackP;
	 tcb->ucontext.uc_stack.ss_size = (size_t) stack_size;
	 makecontext(&tcb->ucontext, function, tcb->thread_id);
}
