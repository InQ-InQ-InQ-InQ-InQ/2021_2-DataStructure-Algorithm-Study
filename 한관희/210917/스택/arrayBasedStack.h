#ifndef __ARRAY_BASED_STACK_H__
#define __ARRAY_BASED_STACK_H__

#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct
{
    Data stack[STACK_SIZE];
    int topIndex;
} Stack;

void StackInit(Stack *pstack);
int IsEmpty(Stack *pstack);
int IsFull(Stack *pstack);
void Push(Stack *pstack, Data data);
Data Pop(Stack *pstack);
Data Peek(Stack *pstack);
void PrintStack(Stack *pstack);

#endif