#include <stdio.h>
#include "header.h"

#define MAX_LIMIT 200

int
main()
{
	char expression[MAX_LIMIT];
	char result[MAX_LIMIT];
	
	/* To get the user input */
	printf("Enter Infix Expression: ");
	fgets(expression, MAX_LIMIT, stdin);

	
	printf("\nConverting expression...\n");
	infixToPostfix(expression, result);
	printf("\nPostfix Expression: %s\n",result);

	printf("Result: %d\n",evaluate(result));
	return 0;
}

int
precedence(char ope)
{
	int lvl;
	
	lvl = 0; // default if (
	
	if(ope == '+' || ope == '-')
		lvl = 1;
	else if(ope == '*' || ope == '/' || ope == '%')
		lvl = 2;
	else if(ope == '^')
		lvl = 3;
		
	return lvl;
}

void
infixToPostfix(char expr[], char* res)
{
	int i, j;
	char ope;
	int length;
	
	j = 0;
	
	cStack stack;
	
	stack = CreateCStack();
	
	length = strlen(expr);
	
	for(i = 0; i < length; i++)
	{
		if(expr[i] >= '0' && expr[i] <= '9')
		{
			while(i < length && expr[i] >= '0' && expr[i] <= '9')
			{
				res[j++] = expr[i++];
			}
			
			res[j++] = ' ';
			i--;
		}
		else if(isOperator(expr[i]))
		{
			/* >= if not ^ , and if ^ then just > */
			while(!isEmptyCStack(stack) &&  TopC(stack) != '(' &&
			(precedence(TopC(stack)) > precedence(expr[i]) || 
			(precedence(TopC(stack)) == precedence(expr[i]) && expr[i] != '^')))
			{				
				ope = PopC(stack);
				
				res[j++] = ope;
				res[j++] = ' ';
			}
			
			PushC(stack, expr[i]);
		}
		else if(expr[i] == '(')
		{
			PushC(stack, '(');
		}
		else if(expr[i] == ')')
		{
			while(TopC(stack) != '(')
			{
				ope = PopC(stack);
				res[j++] = ope;
				res[j++] = ' ';
			}
			
			PopC(stack); // pop the (
		}
	}
	
	while(!isEmptyCStack(stack))
	{
		ope = PopC(stack);
		
		res[j++] = ope;
		res[j++] = ' ';
	}
	
	res[j] = '\0';
}

