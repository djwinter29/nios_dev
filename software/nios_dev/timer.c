/*
 * timer.c
 *
 *  Created on: 12 Dec 2016
 *      Author: ji.dong
 */
#include <stdlib.h>

#include <sys/alt_alarm.h>


#include <stdio.h>


static alt_alarm alarm;

static int timerCounter = 0;

alt_u32 TimerHandler( void * context )
{
    /* Increment the kernel tick. */
    printf("Hello from Timer  %d!\n",  timerCounter++);

    return alt_ticks_per_second();
}


void StartSchedTimer(void)
{
    alt_alarm_start(&alarm, alt_ticks_per_second(), TimerHandler, NULL);
}
