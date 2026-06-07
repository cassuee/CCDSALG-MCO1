#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SERVO_Queue.h"
#include "LL-STACKS.h"
#include "Char-STACKS.h"

#define MAX_LIMIT 200

typedef char Str[50];

void infixToPostfix(char expr[], char* res);
bool isOperand(char c);
int precedence(char ope);
int compute(int n1, int n2,char operand);
int evaluate(Str equation);
