#include<stdio.h>
#include<string.h>
#include<math.h>
double R(char symbol,char op1,char op2)
{
	switch(symbol)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '^': 
		case '$': return pow(op1,op2);
		default : return 0;
	}
}

void main()
{
	int i,top=-1;
	double op1,op2,res=0;
	char postfix[10],s[10],symbol;
	gets(postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		if(isdigit(symbol))
		{
			s[++top]=symbol-'0';
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			res=R(symbol,op1,op2);
			s[++top]=res;
		}
	}
	res=s[top--];
	printf("RES = %lf ",res);
}
