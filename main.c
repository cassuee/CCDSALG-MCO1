#include "header.h"

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