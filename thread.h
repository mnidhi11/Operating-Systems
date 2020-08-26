#include "q.h"
#define STACKSIZE 8192

tcb_q *head = NULL;  //pointer to ready queue
static int tid = 1; 

void start_thread(void (*function)(void))
{
   //printf("entering start thread\n");
	void *stackP = (void *)malloc(sizeof(STACKSIZE));
	tcb_q *tcb = (tcb_q *)malloc(sizeof(tcb_q));
    init_TCB(tcb, function, stackP, STACKSIZE);
    //tcb->thread_id = tid++;
    tid++;
    AddQueue(&head,tcb);
}

void run()

{   // real code

   // Curr_Thread = DelQueue(ReadyQ)
  printf("entering run");

    ucontext_t parent;     // get a place to store the main context, for faking

    getcontext(&parent);   // magic sauce
   // printf("swapping the context in run\n");
    swapcontext(&parent, &(head->ucontext)); 
     // start the first thread
}

void yield() // similar to run
{ 
  // printf("entering yeild"); 
   ucontext_t *cur_context = &head->ucontext;
   printf("\ni am yielding\n");
   RotateQ(&head);
   swapcontext(cur_context,&(head->ucontext));
} 

// int print_id(){
//  return head->thread_id;
// }