#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libs/Queue.h"
#include "libs/IntStack.h"
#include "libs/CharStack.h"

#define MAX_LIMIT 200

typedef char Str[50];

void infixToPostfix(char expr[], char* res);
bool isOperator(char c);
int precedence(char ope);
int compute(int n1, int n2,char operator);
int evaluate(Str equation);
