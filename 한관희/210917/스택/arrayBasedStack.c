#include <stdio.h>
#include <stdlib.h>
#include "arrayBasedStack.h"

void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}

int IsEmpty(Stack *pstack)
{
    if (pstack->topIndex <= -1)
        return TRUE;
    else
        return FALSE;
}

int IsFull(Stack *pstack)
{
    if (pstack->topIndex >= STACK_SIZE)
        return TRUE;
    else
        return FALSE;
}

void Push(Stack *pstack, Data data)
{
    if (IsFull(pstack)) {
        perror("Stack is full.\n");
        exit(-1);
    }
    pstack->stack[++pstack->topIndex] = data;
}

Data Pop(Stack *pstack)
{
    if (IsEmpty(pstack)) {
        perror("Stack is empty.\n");
        exit(-1);
    }

    return pstack->stack[pstack->topIndex--];
}

Data Peek(Stack *pstack)
{
    if (IsEmpty(pstack)) {
        perror("Stack is empty.\n");
        exit(-1);
    }

    return pstack->stack[pstack->topIndex];
}

void PrintStack(Stack *pstack)
{
    for (int i = 0; i <= pstack->topIndex; i++) {
        printf("%d ", pstack->stack[i]);
    }
    putchar('\n');
}