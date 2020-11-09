#include<stdio.h>
#include<stdlib.h>
int a[10],n,element,i,pos;


void creat()
{
	printf("enter the size of an array\n");
	scanf("%d",&n);
	printf("enter the elements of an array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}


void display()
{
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}	
}


void insert()
{
	printf("enter the position the new element\n");
	scanf("%d",&pos);
	printf("enter the new element\n");
	scanf("%d",&element);
	for(i=n-1;i>=pos;i--)
	{
		a[i+1]=a[i];
	}
	a[pos]=element;
	n=n+1;
}


void del()
{
	printf("enter the position of the element\n");
	scanf("%d",&pos);
	element=a[pos];
	for(i=pos;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n=n-1;
	printf("the deleted element is %d \n",element);
}


void main()
{
	int ch;
	do
	{
		printf("\n\n\n ---------------Menu---------------\n\n\n");
		printf("1.creat\n2.Display\n3.Insert\n4.Delete\n5.Exit\n\n");
		printf("enter your choise");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: creat();break;
			
			case 2: display();break;
		
			case 3: insert();break;
			
			case 4: del();break;
			
			case 5: exit(0);break;
			
			default : printf("invalid input");break;
			
		}
	}while(ch!=5);
	getch();
}
