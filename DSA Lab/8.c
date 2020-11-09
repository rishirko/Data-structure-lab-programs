#include<stdio.h>
#include<stdlib.h>

struct emp{
	int ssn,sal;
	char name[20],dept[20],desig[20],phno[10];
	struct emp *llink;
	struct emp *rlink;
};

typedef struct emp NODE;
NODE *first=NULL,*temp=NULL,*cur=NULL,*prev=NULL;
int ch,i,j;

NODE *getnode()
{
	temp=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter ssn, name, dept, desig, phno. , salary \n");
	scanf("%d",&temp->ssn);
	scanf("%s",temp->name);
	scanf("%s",temp->dept);
	scanf("%s",temp->desig);
	scanf("%s",temp->phno);
	scanf("%d",&temp->sal);
	temp->rlink=temp->llink=NULL;
	return temp;
}

NODE *insert_front()
{
	temp=getnode();
	temp->rlink=first;
	first->llink=temp;
	first=temp;
}

NODE *delete_front()
{
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	if(first->rlink==NULL)
	{
		free(first);
		first=NULL;
		return;
	}
	cur=first;
	first=first->rlink;
	first->llink=NULL;
	free(cur);
	first->llink=NULL;
}

NODE *insert_rear()
{
	temp=getnode();
	if(first==NULL)
	{
		first=temp;
		return;
	}
	cur=first;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;	
	}	
	cur->rlink=temp;
	temp->llink=cur;
}

NODE *delete_rear()
{
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	if(first->rlink==NULL)
	{
		free(first);
		first=NULL;
		return;
	}
	cur=first;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;	
	}	
	prev=cur->llink;
	prev->rlink=NULL;
	free(cur);
}

void display()
{
	int count=0;
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	temp=first;
	printf("\n__EMPLOYEE DATA__\n");
	printf("\nSSN\tNAME\tDEPT\tDESIG\tPhNO\tSALARY\n");
	while(temp!=NULL)
	{
		printf("\n%d\t%s\t%s\t%s\t%s\t%d\n",temp->ssn,temp->name,temp->dept,temp->desig,temp->phno,temp->sal);	
		temp=temp->rlink;
		count++;
	}	
	printf("No. of students = %d\n",count);
}
void main()
{
	int n;
	while(1)
	{
		printf("___MENU___");
		printf("\n1.Creat\n2.Display\n3.Insert at rear\n4.Delete from rear\n5.Insert from front\n6.Delete form front\n7.Exit\n");
		printf("--------------------------");
		printf("\n Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n Enter no. of Employee\n");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					insert_rear();
					break;
			case 2:display();break;
			case 3:insert_rear();break;
			case 4:delete_rear();break;
			case 5:insert_front();break;
			case 6:delete_front();break;
			case 7:exit(0);
			default:printf("\nInvalid Choice");
		}
	}
}
