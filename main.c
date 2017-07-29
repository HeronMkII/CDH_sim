/*
    Author: Edwin Ng
	***************************************************************************************
	*	FILE NAME:		obc_sw_sim.c
	*
	*	PURPOSE:
	*	This file simulates the On-Board Computer (OBC) architecture using software.
	*   The main while loop dequeues the command queue every second and runs the dequeued command.
	*   The background thread enqueues HK_REQ into the command queue every 5 seconds.
	*   The F1, F2, F3 keys enqueues command1, command2, and command3 into the command queue.
	*
	*	DEVELOPMENT HISTORY:
	*	2017/07/22		Created.
	***************************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include "queue.h"
#include "isr.h"

void HK_REQ(void)
{
    printf("Performed HK_REQ!\n");
}

void repetitive_task(struct Queue * Q)
{
    while(1){
        Sleep(5000);
        printf("Inserting HK_REQ into command queue...\n");
        struct Data d;
        d.cmd = &HK_REQ;
        enqueue(Q, d);
    }
}

int main()
{
    struct Queue * commandQ;
    struct Data c;
//    struct Queue * dataQ;
//    struct Data * d;
    initQueue(&commandQ);
//    initQueue(&dataQ);

    int err;
    pthread_t tid;
    err = pthread_create(&tid, NULL, &repetitive_task, commandQ);
    if (err != 0)
        printf("Can't create thread :[%s]", strerror(err));
    else
        printf("Thread created successfully\n");

    while(1){
        printf("Dequeuing...\n");
        err = dequeue(commandQ, &c);
        if (err == 0){
            c.cmd();
        }
        if (GetAsyncKeyState(VK_F1))
            ISR1(commandQ);
        if (GetAsyncKeyState(VK_F2))
            ISR2(commandQ);
        if (GetAsyncKeyState(VK_F3))
            ISR3(commandQ);
        Sleep(1000);
    }

    pthread_join(tid, NULL);
    free(commandQ);
    return 0;
}
