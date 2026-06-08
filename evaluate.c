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