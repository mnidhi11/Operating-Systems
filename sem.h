// (c) Partha Dasgupta 2009
// permission to use and distribute granted.

#include "thread.h"

typedef struct semaphore_t {
     tcb_q *start;
     int count;
} sem_t;

sem_t *CreateSem(int InputValue){

  sem_t *sem = (sem_t *)malloc(sizeof(sem_t));
 // sem->start =  NULL;
  sem->count = InputValue;  
  return sem; 
}


// void init_sem(semaphore_t *s, int i)
// {   
//     s->count = i;
//     pthread_mutex_init(&(s->mutex), NULL);
//     pthread_cond_init(&(s->cond), NULL);
// }


/*
 * The P routine decrements the semaphore, and if the value is less than
 * zero then blocks the process 
 */
void P(sem_t *semp)
{   
    printf("Entered P mutex\n");
    tcb_q *temp; 
    semp->count--;
    if (semp->count < 0)
    {
    //printf("Delete queue calling in P mutex\n");
    //sleep(1);
    temp = DeleteQueue(&head);
    ucontext_t *cur_context = &head->ucontext;
    //printf("Swap queue calling in P mutex\n");
    //sleep(1);
    //swapcontext(&(temp->ucontext),&(head->ucontext));
    swapcontext(cur_context,&(head->ucontext));
    //printf("Add queue calling in P mutex\n");
    //sleep(1);
    AddQueue(&(semp->start),temp);
    } 

}


/*
 * The V routine increments the semaphore, and if the value is 0 or
 * negative, wakes up a process and yields
 */

void V(sem_t * semp)
{    
    //printf("entering V mutex\n");
    semp->count++;
    if (semp->count <= 0)
     {
        tcb_q *temp = DeleteQueue(&(semp->start));
	    AddQueue(&head,temp);
        
     }
    yield();
   // printf("Exiting V mutex\n");
}
