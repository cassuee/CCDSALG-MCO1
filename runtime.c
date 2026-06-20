#include "header.h"
#include <time.h>

#define MAX_EXPR_LEN 300000
typedef char String[MAX_EXPR_LEN];

double timer(int tokens, String eq)
{
    double runtime;
    String post;
    clock_t start;
    clock_t end;
    start = clock();
    infixToPostfix(eq,post);
    evaluate(post);
    end = clock();
    runtime = ((double)(end-start)/ CLOCKS_PER_SEC);
    return runtime;
}

double category1(int tokens)
{
    int i,j;
    
    String eq = "1 + ";

    j=1;
    for(i=1;i<=tokens;i++){
        switch(j){
            case 1: 
                strcat(eq,"2 ");
                if(i < tokens)
                    strcat(eq,"* ");  
            break;
            case 2: 
                strcat(eq,"3 ");
                if(i < tokens)
                    strcat(eq,"- ");  
            break;
            case 3: 
                strcat(eq,"4 "); 
                if(i < tokens)
                    strcat(eq,"/ "); 
            break;
            case 4: 
                strcat(eq,"5 "); 
                if(i < tokens)
                    strcat(eq,"+ "); 
            break;
            case 5: 
                strcat(eq,"6 "); 
                if(i < tokens)
                    strcat(eq,"^ "); 
            break;
        }
        if(j == 5) j=1; else j++;
    }
    //printf("Token[%d] | %s\n",tokens,eq);
    return timer(tokens,eq);
}

double category2(int tokens)
{
    String eq = "";
    int bracket = (tokens - 3) / 3; 
    int i;
    
    for (i = 0; i < bracket; i++) {
        strcat(eq, "( ");
    }
    strcat(eq, "1 + 1");
    for (i = 0; i < bracket; i++) {
        strcat(eq, " ) + 1");
    }
    
    return timer(tokens,eq);
}

double category3(int tokens)
{
    String eq;
    return timer(tokens,eq);
}

double category4(int tokens)
{
    String eq;
    return timer(tokens,eq);
}
int main()
{
    FILE *fp;
    fp = fopen("runtime.csv", "w");
    fprintf(fp, "Tokens,Cat1,Cat2,Cat3,Cat4\n");
    int tokens = 5;
    double cat1=67,cat2=67,cat3=67,cat4=67;
    while(tokens <= 10000){
        printf("Checking runtimes for [%d] tokens\n",tokens);
        cat1 = category1(tokens); 
        cat2 = category2(tokens);
        //cat3 = category3(tokens);
        //cat4 = category4(tokens);
        fprintf(fp, "%d,%f,%f,%f,%f\n", tokens, cat1, cat2, cat3, cat4);
        if(tokens == 5) tokens *= 2;
        else if (tokens < 50) tokens += 10;
        else tokens += 50;
    }
    printf("Successfully printed runtimes.\n");
    fclose(fp);
}