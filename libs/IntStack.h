#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodeTag
{
    int data;
    struct nodeTag *next;
};

typedef struct nodeTag NodeType;

struct stackTag
{
    NodeType *top;
};

typedef struct stackTag *Stack;

// FUNCTION PROTOTYPES
Stack CreateStack();
bool isEmptyStack(Stack S);
bool isFullStack(Stack S);
void Push(Stack S, int x); 
int Pop(Stack S); 	
int Top(Stack S); 
void DisplayStack(Stack S);

