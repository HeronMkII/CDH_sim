/*
    Author: Edwin Ng
	***************************************************************************************
	*	FILE NAME:		software_ISR.h
	*
	*	PURPOSE:
	*	This file contains an example of using keyboard interrupts.
	*
	*	DEVELOPMENT HISTORY:
	*	2017/06/24		Created.
	*   2017/07/22      Simplify code.
	*   2017/07/22      Change to header file.
	*   2017/07/29      Add command functions.
	***************************************************************************************
 */

#ifndef ISR_H_INCLUDED
#define ISR_H_INCLUDED
#include <windows.h>

void command1 (void)
{
    printf("Performed command1!\n");
}

void command2 (void)
{
    printf("Performed command2!\n");
}

void command3 (void)
{
    printf("Performed command3!\n");
}

void ISR1(struct Queue * Q)
{
    printf("Inserting command1 into command queue...\n");
    struct Data d;
    d.cmd = &command1;
    enqueue(Q, d);
}

void ISR2(struct Queue * Q)
{
    printf("Inserting command2 into command queue...\n");
    struct Data d;
    d.cmd = &command2;
    enqueue(Q, d);
}

void ISR3(struct Queue * Q)
{
    printf("Inserting command3 into command queue...\n");
    struct Data d;
    d.cmd = &command3;
    enqueue(Q, d);
}

#endif // ISR_H_INCLUDED
