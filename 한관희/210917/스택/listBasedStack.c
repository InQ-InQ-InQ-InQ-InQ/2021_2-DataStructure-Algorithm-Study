#include <stdio.h>
#include <stdlib.h>
#include "listBasedStack.h"

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int IsEmpty(Stack *pstack)
{
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void Push(Stack *pstack, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data Pop(Stack *pstack)
{
    Node* rNode;
    Data rData;

    if (IsEmpty(pstack)) {
        perror("Stack is empty.\n");
        exit(-1);
    }

    rNode = pstack->head;
    rData = rNode->data;

    pstack->head = pstack->head->next;
    free(rNode);

    return rData;
}

Data Peek(Stack *pstack)
{
    if (IsEmpty(pstack)) {
        perror("Stack is empty.\n");
        exit(-1);
    }

    return pstack->head->data;
}

void PrintStack(Stack *pstack)
{
    Node* node = pstack->head;

    while (1) {
        printf("%d ", node->data);
        if (node->next == NULL) break;
        node = node->next;
    }
    putchar('\n');
}