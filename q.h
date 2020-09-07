#include "tcb.h"

void newQueue(tcb_q** Q){
   
   (*Q) = NULL;
}


void AddQueue(tcb_q **Q, tcb_q *temp){


	tcb_q *initial_q = *Q;
	
	if(*Q == NULL)
	{
	newQueue(&initial_q);
       *Q = temp;
       (*Q)->prev = temp;
       (*Q)->next = temp;
	}
	else
	{
	tcb_q *last = (*Q)->prev;
	(*Q)->prev = temp;
	temp->prev = last;
	last->next = temp;
	temp->next = *Q;
	}
	
	sleep(1);

}


tcb_q *DeleteQueue(tcb_q **Q)
{
	tcb_q *cur = '\0';

	if(*Q == NULL)
	{
		printf("Queue is empty...\n");
		return cur;
	}
	else 
	{
	cur = (*Q);
       
	if((*Q)->next == (*Q))
	{
	(*Q) = '\0';	
	}
	else
	{
        tcb_q *last = (*Q)->prev;
        *Q = (*Q)->next;
        (*Q)->prev = last;
        last->next = (*Q);
 	}
     cur->prev = '\0';
     cur->next = '\0';
  
    return cur;
	}

  }
 


void RotateQ(tcb_q **Q){
	printf("Rotating the rotate Q\n");
	sleep(1);
	
		(*Q) =(*Q)->next;
}
