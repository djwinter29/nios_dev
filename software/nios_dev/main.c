/*
 * main.c
 *
 *  Created on: 9 Dec 2016
 *      Author: ji.dong
 */

#include <stdio.h>

#include <priv/alt_busy_sleep.h>

#include "sched.h"


static int mainCounter = 0;

void * pCurrentTCB = (void *)0x7000;

void TaskContextSwitch( void )
{
    printf("switch task!\n");
}

int main()
{
//    printf("Hello from Main!\n");

    yield();
    yield();

    StartSchedTimer();

    while(1)
    {
        alt_busy_sleep(1000000);
        //
        printf("Hello from Main  %d!\n",  mainCounter++);
    }


    return 0;
}
