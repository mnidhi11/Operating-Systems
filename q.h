#include "tcb.h"

void newQueue(tcb_q** Q){
   
   (*Q) = NULL;
}


void AddQueue(tcb_q **Q, tcb_q *temp){

  //tcb_q *p;
  //int c = 0;
	tcb_q *initial_q = *Q;
	
	if(*Q == NULL){
		newQueue(&initial_q);
       *Q = temp;
       (*Q)->prev = temp;
       (*Q)->next = temp;
	}
	else{
      // tcb_q *p = (*Q)->prev;
      //  p->next = temp;
      //  temp->prev = p;
      //  temp->next = (*Q);
      //  (*Q)->prev = temp;
		tcb_q *last = (*Q)->prev;
		(*Q)->prev = temp;
		temp->prev = last;
		last->next = temp;
		temp->next = *Q;
	}
	//c++;
	//printf("added to the queue%d\n",c);
	sleep(1);

}


tcb_q *DeleteQueue(tcb_q **Q){
	tcb_q *cur = '\0';
   // int c = 0;
	if(*Q == NULL){
		printf("Queue is empty...Nothing to delete\n");
		return cur;
	}
	else {
		cur = (*Q);
        
		if((*Q)->next == (*Q)){
		(*Q) = '\0';
		//p->next = '\0';
		//p->prev = '\0';
		//return Q;
	   }
	   else{
        tcb_q *last = (*Q)->prev;
        *Q = (*Q)->next;
        (*Q)->prev = last;
        last->next = (*Q);
    // (*Q) = (*Q)->next;
    // (*Q)->prev = p->prev;
    // p->prev->next = *Q;

	   }
     cur->prev = '\0';
	 cur->next = '\0';

	
	//printf("delete from the queue%d\n",c);
    return cur;
	}

  }
 


void RotateQ(tcb_q **Q){
	printf("Rotating the rotate Q\n");
	sleep(1);
	//  if(*Q == NULL)
	//  	return;
	// else{
		(*Q) =(*Q)->next;
	//}
}
