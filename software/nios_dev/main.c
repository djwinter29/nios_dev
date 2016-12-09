/*
 * main.c
 *
 *  Created on: 9 Dec 2016
 *      Author: ji.dong
 */

#include <stdio.h>

#include <sys/alt_alarm.h>
#include <priv/alt_busy_sleep.h>

static alt_alarm alarm;
static int mainCounter = 0;
static int timerCounter = 0;

alt_u32 TimerHandler( void * context )
{
    /* Increment the kernel tick. */
    printf("Hello from Timer  %d!\n",  timerCounter++);

    return alt_ticks_per_second();
}


int main()
{
    printf("Hello from Main!\n");

    alt_alarm_start(&alarm, alt_ticks_per_second(), TimerHandler, NULL);

    while(1)
    {
        alt_busy_sleep(1000000);
        printf("Hello from Main  %d!\n",  mainCounter++);
    }


    return 0;
}
