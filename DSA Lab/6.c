#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=0,rear=-1,count=0;
char q[MAX],item;

void insert()
{
	printf("enter item");
	scanf(" %c",&item);
	if(count==MAX)
	{
		printf("Queue is full");
	}
	else
	{
		rear=(rear+1)%MAX;
		q[rear]=item;
		count++;
	}
}
void del()
{
	if(count==0)
	{
		printf("\nQueue is empty");
	}
	else
	{
		item=q[front];
		printf("Deleted item = %c \n",item);
		
		if(front==rear)
		{
			front=0;
			rear=-1;
			count=0;
		}
		else
		{
			
			front=(front+1)%MAX;
			count--;
		}
	}
}
void display()
{
	int i;
	if(count==0)
	{
		printf("Queue is Empty");
	}
	for(i=front;i<=rear;i++)
	{
		printf("%c\t",q[i]);
		front=(front+1)%MAX;
	}
}
void main()
{
	int ch;
	do
	{
		printf("MENU\n");
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("enter ur choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();break;
			case 2:del();break;
			case 3:display();break;
			case 4:exit(0);
			
			
		}
	}while(ch!=4);
}
