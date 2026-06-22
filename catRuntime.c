#include "header.h"
#include <time.h>

#define MAX_EXPR_LEN 300000
#define MAX_TESTS 96
typedef char String[MAX_EXPR_LEN];

int countTokens(String eq)
{
    int count = 0;
    int i;

    for(i=0;i<strlen(eq)-1;i++)
    {
        if(eq[i] != ' ')
            count += 1;
    }
    return count;
}

double timer(String eq)
{
    double runtime;
    int n = 1000;   // number of iterations for average time
    int i;
    String post;
    clock_t start;
    clock_t end;
    start = clock();
    for(i=0;i<n;i++)
    {
        infixToPostfix(eq,post);
        evaluate(post);
    }
    end = clock();
    runtime = ((double)(end-start)/ CLOCKS_PER_SEC) / n;
    return runtime;
}

int main()
{
    FILE *fp;
    int cat;
    scanf("%d",&cat);
    if(cat == 1)
        fp = fopen("runtime-cat1.csv", "w");
    else if(cat == 2)
        fp = fopen("runtime-cat2.csv", "w");
    else if(cat == 3)
        fp = fopen("runtime-cat3.csv", "w");
    else if(cat == 4)
        fp = fopen("runtime-cat4.csv", "w");
    fprintf(fp, "Tokens,Cat%d\n",cat);
    String eq;
    int i;
    int tokens = 0;
    double cat1=67;
    for(i=0;i<MAX_TESTS;i++){
        fgets(eq, sizeof(eq), stdin); 
        //printf("Equation: %s\n",eq);
        tokens = countTokens(eq);
        printf("Checking runtimes for [%d] tokens\n",tokens);
        cat1 = timer(eq);
        fprintf(fp, "%d,%f\n", tokens, cat1);
    }
    printf("Successfully printed runtimes.\n");
    fclose(fp);
}