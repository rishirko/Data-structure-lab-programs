#include<stdio.h>
#include<stdlib.h>
int a[10],elem,del,i,n,pos;

void creat()
{
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void display()
{
	printf("Array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}

void insert()
{
	printf("Enter the position of the element\n");
	scanf("%d",&pos);
	printf("Enter the element to be inserted\n");
	scanf("%d",&elem);
	for(i=n-1;i>=pos;i--)
	{
		a[i+1]=a[i];
	}
	a[pos]=elem;
	n=n+1;
}

void delete()
{
	int temp=0;
	printf("Enter the position of the element to be deleted\n");
	scanf("%d",&pos);
	temp=a[pos];
	for(i=pos;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n=n-1;
	printf("Deleted element is %d \n",temp);
}

void main()
{
	int ch;
	do
	{
		printf("\n---Menu---\n");
		printf("\n1.Creat\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:creat();break;
			case 2:display();break;
			case 3:insert();break;
			case 4:delete();break;
			case 5:exit(0);
			default : printf("\n Invalid input");
			
		}
	}while(ch!=5);
}
