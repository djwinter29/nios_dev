/*
 * main.c
 *
 *  Created on: 9 Dec 2016
 *      Author: ji.dong
 */

#include <stdio.h>

#include <priv/alt_busy_sleep.h>
#include <sys/alt_irq.h>
#include "sched.h"


static int mainCounter = 0;


void * pCurrentTCB = (void *)0x7000;

static volatile int taskedcount = 0;

void TaskContextSwitch( void )
{
    //printf("switch task!\n");
    taskedcount ++;
}

int main()
{
//    printf("Hello from Main!\n");
    alt_irq_context status = alt_irq_disable_all ();

    yield();
    yield();

   // StartSchedTimer();
    alt_irq_enable_all(status);
    while(1)
    {
        alt_busy_sleep(1000000);
        yield();
        //
        printf("Hello from Main  %d!\n",  mainCounter++);
    }


    return 0;
}
