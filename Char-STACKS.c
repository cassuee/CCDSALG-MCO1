#include "Char-STACKS.h"

cStack  // (1)
CreateCStack() // Create Stack Function -- which will create an empty stack
{
	cStack S;
	S = (cStack)malloc(sizeof(struct cStackTag));

	if (S == NULL)
	{
		printf("Memory Allocation Failed!\n");
		exit(1); // terminates the program if malloc fails
	}
	S->top = NULL;
		
	return S;
}
	
bool // (2)
isEmptyCStack(cStack S)// StackEmpty (S) -- returns true when top is 0 (empty), false otherwise (not empty)
{
	return (S->top == NULL);
}
	
bool // (3)
isFullCStack(cStack S)// StackFull (S) -- returns true when stack is full, false otherwise
{
	cNodeType *pTemp;
	pTemp = (cNodeType *)malloc(sizeof(cNodeType));

	if (pTemp == NULL)
    return 1;

	free(pTemp); // removes memory of current node if pTemp != NULL
	return 0;
}
	
void // (4)
PushC(cStack S, char x) // Push(S, x) -- inserts element x into the stack (where overflow may occur)
{
	cNodeType *pNew;

	if (isFullCStack(S))
	{
		printf("STACK OVERFLOW\n");
	}
	else
	{
		pNew = (cNodeType*)malloc(sizeof(cNodeType));

		pNew->data = x;
		pNew->next = S->top;

		S->top = pNew;
	}
}
	
char // (5)
PopC(cStack S) // Pop(S) -- deletes the element from the top of the stack and returns that element (where underflow may occur)
{
	cNodeType *pTemp;
	char x;

	if (isEmptyCStack(S))
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
	
char // (6)
TopC(cStack S) // Top(S) -- should return the top element (not the index) of the stack
{
	if (isEmptyCStack(S))
	{
		printf("STACK IS EMPTY\n");
		return -1;
	}
	return S->top->data;
} 
		
void // (7)
DisplayCStack(cStack S)
{
    cNodeType *pTemp;

    if (isEmptyCStack(S))
    {
        printf("Stack is Empty\n");
    }
	else
	{
		pTemp = S->top;

		printf("Stack: ");
		while (pTemp != NULL)
		{
			printf("%c ", pTemp->data);
			pTemp = pTemp->next;
		}
	}
   
    printf("\n\n");
}
