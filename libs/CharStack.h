#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cNodeTag
{
    char data;
    struct cNodeTag *next;
};

typedef struct cNodeTag cNodeType;

struct cStackTag
{
    cNodeType *top;
};

typedef struct cStackTag *cStack;

// FUNCTION PROTOTYPES
cStack CreateCStack();
bool isEmptyCStack(cStack S);
bool isFullCStack(cStack S);
void PushC(cStack S, char x); 
char PopC(cStack S); 	
char TopC(cStack S); 
void DisplayCStack(cStack S);

