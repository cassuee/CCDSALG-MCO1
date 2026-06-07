#include "LL-STACKS.h"

Stack  // (1)
CreateStack() // Create Stack Function -- which will create an empty stack
{
	Stack S;
	S = (Stack)malloc(sizeof(struct stackTag));

	if (S == NULL)
	{
		printf("Memory Allocation Failed!\n");
		exit(1); // terminates the program if malloc fails
	}
	S->top = NULL;
		
	return S;
}
	
bool // (2)
isEmptyStack(Stack S)// StackEmpty (S) -- returns true when top is 0 (empty), false otherwise (not empty)
{
	return (S->top == NULL);
}
	
bool // (3)
isFullStack(Stack S)// StackFull (S) -- returns true when stack is full, false otherwise
{
	NodeType *pTemp;
	pTemp = (NodeType *)malloc(sizeof(NodeType));

	if (pTemp == NULL)
    return 1;

	free(pTemp); // removes memory of current node if pTemp != NULL
	return 0;
}
	
void // (4)
Push(Stack S, int x) // Push(S, x) -- inserts element x into the stack (where overflow may occur)
{
	NodeType *pNew;

	if (isFullStack(S))
	{
		printf("STACK OVERFLOW\n");
	}
	else
	{
		pNew = (NodeType*)malloc(sizeof(NodeType));

		pNew->data = x;
		pNew->next = S->top;

		S->top = pNew;
	}
}
	
int // (5)
Pop(Stack S) // Pop(S) -- deletes the element from the top of the stack and returns that element (where underflow may occur)
{
	NodeType *pTemp;
	int x;

	if (isEmptyStack(S))
	{
		printf("STACK UNDERFLOW\n");
		return -1;
	}

	pTemp = S->top;
	x = pTemp->data;

	S->top = pTemp->next;

	free(pTemp); // removes memory of current node

	return x;
	}
	
int // (6)
Top(Stack S) // Top(S) -- should return the top element (not the index) of the stack
{
	if (isEmptyStack(S))
	{
		printf("STACK IS EMPTY\n");
		return -1;
	}
	return S->top->data;
} 
		
void // (7)
DisplayStack(Stack S)
{
    NodeType *pTemp;

    if (isEmptyStack(S))
    {
        printf("Stack is Empty\n");
    }
	else
	{
		pTemp = S->top;

		printf("Stack: ");
		while (pTemp != NULL)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->next;
		}
	}
   
    printf("\n\n");
}
