#include "header.h"

int
main()
{
	char expression[MAX_LIMIT];
	char result[MAX_LIMIT];
	int invalid_expression = 1;
	
	/* To get the user input */
	printf("Enter Infix Expression: ");
	fgets(expression, MAX_LIMIT, stdin);
	
	if(!validateExpression(expression))
    {
        printf("Conversion stopped.\n");
        invalid_expression = 0;
    } 									

	if(invalid_expression)
	{
		printf("\nConverting expression...\n");
		infixToPostfix(expression, result);
		printf("\nPostfix Expression: %s\n",result);

		printf("Result: %d\n",evaluate(result));
	}
	
	return 0;
}
