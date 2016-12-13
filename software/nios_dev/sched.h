/*
 * sched.h
 *
 *  Created on: 12 Dec 2016
 *      Author: ji.dong
 */

#ifndef SCHED_H_
#define SCHED_H_


/***************************************
 *  Special
 ****************************************/
/* Include the port_asm.S file where the Context saving/restoring is defined. */
//__asm__( "\n\t.globl    save_context" );

#define yield()         asm volatile ( "trap" );


/***************************************
 *  Timer Prototype
 ****************************************/
void StartSchedTimer(void);




#endif /* SCHED_H_ */
