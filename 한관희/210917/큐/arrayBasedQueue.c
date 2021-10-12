#include <stdio.h>
#include <stdlib.h>
#include "arrayBasedQueue.h"

void QueueInit(Queue *pqueue)
{
    pqueue->front = 0;
    pqueue->rear = 0;
}

int IsEmpty(Queue *pqueue)
{
    if (pqueue->front == pqueue->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if (pos == QUEUE_SIZE - 1)
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pqueue, Data data)
{
    if (NextPosIdx(pqueue->rear) == pqueue->front) {
        perror("Queue is full.\n");
        exit(-1);
    }

    pqueue->rear = NextPosIdx(pqueue->rear);
    pqueue->queue[pqueue->rear] = data;
}

Data Dequeue(Queue *pqueue)
{
    if (IsEmpty(pqueue)) {
        perror("Queue is Empty.\n");
        exit(-1);
    }

    pqueue->front = NextPosIdx(pqueue->front);
    
    return pqueue->queue[pqueue->front];
}

Data Peek(Queue *pqueue)
{
    if (IsEmpty(pqueue)) {
        perror("Queue is Empty.\n");
        exit(-1);
    }

    return pqueue->queue[NextPosIdx(pqueue->front)];
}

void PrintQueue(Queue *pqueue)
{
    int pos = pqueue->front;

    while (pqueue->rear != pos) {
        pos = NextPosIdx(pos);
        printf("%d ", pqueue->queue[pos]);
    }
    putchar('\n');
}