#include <stdio.h>
#include <stdlib.h>
#include "listBasedQueue.h"

void QueueInit(Queue *pqueue)
{
    pqueue->front = NULL;
    pqueue->rear = NULL;
}

int IsEmpty(Queue *pqueue)
{
    if (pqueue->rear == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *pqueue, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->data = data;

    if (IsEmpty(pqueue)) {
        pqueue->front = newNode;
        pqueue->rear = newNode;
    }
    else {
        pqueue->rear->next = newNode;
        pqueue->rear = newNode;
    }
}

Data Dequeue(Queue *pqueue)
{
    Node *rNode;
    Data rData;

    if (IsEmpty(pqueue)) {
        perror("Queue is Empty.\n");
        exit(-1);
    }
    
    rNode = pqueue->front;
    rData = rNode->data;
    pqueue->front = pqueue->front->next;

    free(rNode);

    return rData;
}

Data Peek(Queue *pqueue)
{
    if (IsEmpty(pqueue)) {
        perror("Queue is Empty.\n");
        exit(-1);
    }

    return pqueue->front->data;
}

void PrintQueue(Queue *pqueue)
{
    Node *ptr = pqueue->front;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}