/*
    Author: Edwin Ng
	***************************************************************************************
	*	FILE NAME:		queue.h
	*
	*	PURPOSE:
	*	This file contains a queue library for use in other files.
	*
	*	DEVELOPMENT HISTORY:
	*	2017/05/13		Created.
	*   2017/05/20      Modified from linked list implementation to array implementation.
    *   2017/07/22      Modified data structure to contain function pointers instead of integers.
    *   2017/07/22      Change to header file.
    *   2017/07/22      Add error-checking for enqueue and dequeue function.
	***************************************************************************************
 */

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAXQUEUESIZE 50

struct Data{
    void (*cmd)(void);
};

struct Node{
    struct Data data;
};

struct Queue{
    int currSize;
    int front;
    int rear;
    struct Node queueArray[MAXQUEUESIZE];
};

void initQueue(struct Queue ** qPtr)
{
    struct Queue * Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->currSize = 0;
    Q->front = 0;
    Q->rear = 0;
    *qPtr = Q;
}

int isEmpty(struct Queue * Q)
{
    return Q->currSize == 0;
}

int isFull(struct Queue * Q)
{
    return Q->currSize == MAXQUEUESIZE;
}

int enqueue(struct Queue * Q, struct Data d)
{
    if (!isFull(Q)){
        Q->queueArray[Q->rear].data = d;
        Q->rear = (Q->rear + 1) % MAXQUEUESIZE;
        Q->currSize++;
        return 0;
    }
    else{
        return 1;
    }
}

int dequeue(struct Queue * Q, struct Data * d)
{
    if (!isEmpty(Q)){
        *d = Q->queueArray[Q->front].data;
        Q->front = (Q->front + 1) % MAXQUEUESIZE;
        Q->currSize--;
        return 0;
    }
    else{
        return 1;
    }
}

#endif // QUEUE_H_INCLUDED
