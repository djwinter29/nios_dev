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


/* main.c
 *
 *  Created on: 9 Dec 2016
 *      Author: ji.dong
 */

#include <stdio.h>

#include <priv/alt_busy_sleep.h>
#include <sys/alt_irq.h>
#include "sched.h"

static volatile int taskedcount1 = 0;
static volatile int taskedcount2 = 0;

int Task1(void * test)
{
    while (1)
    {
        alt_busy_sleep(1000000);
        printf("Hello from Task1  %d!\n",  taskedcount1++);
    }

    return 0;
}

int Task2(void * test)
{
    while (1)
    {
        alt_busy_sleep(1000000);
        printf("Hello from Task2  %d!\n",  taskedcount2++);
    }

    return 0;
}

int main()
{
//    printf("Hello from Main!\n");


    CreateStaticTask(0, Task1, NULL);
    CreateStaticTask(1, Task2, NULL);

    alt_irq_context status = alt_irq_disable_all ();
    StartSchedTimer();
    alt_irq_enable_all(status);

    StartScheduler();

    return 0;
}
