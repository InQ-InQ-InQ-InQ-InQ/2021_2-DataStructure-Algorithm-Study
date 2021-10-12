#ifndef __ARRAY_BASED_QUEUE_H__
#define __ARRAY_BASED_QUEUE_H__

#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 100

typedef int Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void QueueInit(Queue *pqueue);
int IsEmpty(Queue *pqueue);
void Enqueue(Queue *pqueue, Data data);
Data Dequeue(Queue *pqueue);
Data Peek(Queue *pqueue);
void PrintQueue(Queue *pqueue);

#endif