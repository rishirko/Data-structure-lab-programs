#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char ch,s[10],sen[100];
    scanf("%c",&ch);
    scanf("%s\n",s);
    gets(sen);
    //gets(sen);
    printf("%c\n%s\n%s",ch,s,sen);   
    return 0;
}

