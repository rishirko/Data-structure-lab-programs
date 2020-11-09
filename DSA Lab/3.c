#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack[MAX],item;
int ch,top=-1,status=0,count=0;
void push()
{
	printf("enter the element to be pushed\n");
	scanf("%d",&item);
	if(top==(MAX-1))
	{
		printf("Stack overflow\n");
	}
	else
	{
		stack[++top]=item;
		status++;
	}
}

int pop()
{
	int del;
	if(top==-1)
	{
		printf("stack is unferflow\n");
	}
	else
	{
		del=stack[top];
		top--;
		status--;
		printf("popped item = %d ",del);
	}
	return del;
}
void palindrome()
{
	int i;
	int temp=0;
	temp=status;
	for(i=0;i<temp;i++)
	{
		if(stack[i]==pop())
		{
			printf("\n");
			count++;
		}
	}
	if(count==temp)
	{
		printf("palindrome\n");
	}
	else
	{
		printf("NOT palindrome\n");
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is underflow\n ");
	}
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}
void main()
{
	do
	{
		printf("\n1.push\n2.pop\n3.palindrome\n4.display\n5.exit");
		printf("enter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:palindrome();break;
			case 4:display();break;
			case 5:exit(0);
			default:printf("Invalid choice\n");
		}
		
	}while(ch!=5);
	
}





