/*
 * Copyright (c) 2016 Ji Dong < ji.dong@hotmail.co.uk >
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * timer.c
 *
 *  Created on: 12 Dec 2016
 *      Author: ji.dong
 */
#include <stdlib.h>

#include <sys/alt_alarm.h>

#include <stdio.h>

#include "sched.h"


static alt_alarm alarm;

alt_u32 TimerHandler( void * context )
{
    /* Increment the kernel tick. */
    TaskContextSwitch();
    return alt_ticks_per_second();
}


void StartSchedTimer(void)
{
    alt_alarm_start(&alarm, alt_ticks_per_second(), TimerHandler, NULL);
}
