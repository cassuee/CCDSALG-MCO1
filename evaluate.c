/* 
Evalutating a postfix expression. 
    Clarence Talampas
*/
#include "header.h"

/**
 * Computes the total of the two numbers given the operator.
 * @param n1 1st number
 * @param n2 2nd number
 * @param operator the operation to be done
 * @return the computed value
 */
int compute(int n1, int n2,char operator)
{
    if(operator == '+')
        n1 += n2;
    else if(operator == '-')
        n1 -= n2;
    else if(operator == '*')
        n1 *= n2;
    else if(operator == '/')
        n1 /= n2;
    else if(operator == '%')
        n1 %= n2;
    else if(operator == '^')
        n1 = pow(n1,n2);
    else
        printf("ERROR!");
    return n1;
}

/**
 * Checks whether the character is an operator
 * @param c the character to be checked
 * @return true if the character is an operator, false otherwise.
 */
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

/**
 * Checks whether the expression is valid or not
 * @param exp[] contains each character in the expression entered
 * @returns true if the whole expression is valid, false otherwise.
 */
bool validateExpression(char exp[]) // Error-Handling Function ----> (1-4) is only for conditional statement matching, (1) statement matches with other (1) statements, (2-4) matches with inner conditional statements
{
    int i; // indexing variable
    int parenCount = 0; // for parenthesis checking
    bool expectOperand = true; // for operand checking

    for(i = 0; exp[i] != '\0' && exp[i] != '\n'; i++)
    {
        char ch = exp[i];
 
		if(ch == ' ') // (1) if statement to ignore whitespaces
		{
		
		}
		// This checks if the next character is either a valid operand or operator
        else if(!((ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' 
			|| ch == '^' || ch == '(' || ch == ')')) // (1)
        {
            printf("ERROR: Invalid character '%c'\n", ch);
            return false;
        }
		
		else if(ch == '/') // (1) this automatically flags the expression as invalid if it sees a 0 after '/' 
		{                  // so it also flags expressions such as 1/011 or 12+1/02 as invalid
            int j;
			j = i + 1;

            while(exp[j] == ' ')
                j++;
            if(exp[j] == '0') // (2)
            {
				printf("WARNING: Possible division by zero detected near index %d\n", i);
				return false;
            }
        }
            
        else // (1)
		{
			if(expectOperand) // (2) expects a number or '('
			{
				if(ch >= '0' && ch <= '9') // (3) 0-9
				{    
					while(exp[i + 1] >= '0' && exp[i + 1] <= '9') // skips the number and the digits next to it (if applicable)
						i++;
					expectOperand = false; // numbers are already validated and the next char is an operator
				}
				else if(ch == '(') // (2)
				{
					parenCount++; // for valid parenthesis pair checking
				}
				else //  (2) stops the conversion if the first char entered is an operator
				{
					printf("ERROR: Malformed expression.\n");
					return false;
				}
			}
			
			else // (2) expects a valid operator
			{
				if(isOperator(ch)) // (3) from helper function --> checks the validity of an operator
				{
					expectOperand = true; // signifies that the next char after an operator is an operand
				}
				else if(ch == ')') // (3)
				{
					parenCount--; // will become >= 0 if there one or more '(' is identified
					if(parenCount < 0) // (4) means that ')' came before '('
					{
						printf("ERROR: Mismatched parentheses.\n");
						return false;
					}
				}
				else if(ch == '(') // (3)
				{
					printf("ERROR: Missing operator before '('.\n");
					return false; // there should be an operator right before a parenthesis (tama ba itu?????)
				}
				else if(ch >= '0' && ch <= '9') // (3) stops conversion if there is a space between two digits
				{
					printf("ERROR: Missing operator between operands.\n");
					return false;
				}
			}
		}
    }

    if(parenCount != 0) // (0)
    {
        printf("ERROR: Mismatched parentheses.\n");
        return false; // there is an unmatched parenthesis '('
    }

    if(expectOperand) // (0)
    {
        printf("ERROR: Expression ends with an operator.\n");
        return false; // invalid if the last expression is not an operand
    }
    return true;
}

/**
 * Evaluates a given postfix expression
 * @param equation the postfix expression
 * @return the computed value of the equation
 */
int evaluate(Str equation)
{
    if(equation[strlen(equation)-1] != ' ')
        strcat(equation," ");
    Stack stk = CreateStack();  // equation

    int n1,n2;
    int i,j=0;

    for(i=0;i<strlen(equation);i++)
    {
        Str substring;
        if(!(equation[i] == ' '))
        {
                substring[j] = equation[i];
                j++;
        } 
        else
        {
            if(!isOperator(equation[i-1])){
                Push(stk,atoi(substring));
            }
            else{
                char operator = equation[i-1];
                
                n2 = Pop(stk);
                n1 = Pop(stk);
                //perform operation
                Push(stk,compute(n1,n2,operator));
            }
            j=0;    // reset
        }
    }
    
    return Pop(stk);
}
