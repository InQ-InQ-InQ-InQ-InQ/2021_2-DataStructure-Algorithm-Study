#ifndef __ARRAY_BASED_QUEUE_H__
#define __ARRAY_BASED_QUEUE_H__

#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 100

typedef int Data;

typedef struct
{
    int front;
    int rear;
    Data queue[QUEUE_SIZE];
} Queue;

void QueueInit(Queue *pqueue);
int IsEmpty(Queue *pqueue);
int NextPosIdx(int pos);
void Enqueue(Queue *pqueue, Data data);
Data Dequeue(Queue *pqueue);
Data Peek(Queue *pqueue);
void PrintQueue(Queue *pqueue);

#endif