//prog 7
#include<stdio.h>
#include<stdlib.h>

struct student{
	char usn[10],name[20],sem[10],branch[10];
	struct student *link;
};

typedef struct student NODE;
NODE *first=NULL,*newnode=NULL,*cur,*prev,*temp=NULL;
int count;

NODE *getnode()
{
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter usn , name, sem ,branch");
	scanf("%s",newnode->usn);
	scanf("%s",newnode->name);
	scanf("%s",newnode->sem);
	scanf("%s",newnode->branch);
	newnode->link=NULL;
	return newnode;
}

NODE *insert_front()
{
	temp=getnode();
	temp->link=first;
	first=temp;
}

NODE *insert_rear()
{
	temp=getnode();
	if(first==NULL)
	{
		first=temp;
		first->link=NULL;
		return;
	}
	else
	{
		cur=first;
		while(cur->link!=NULL)
		{
			cur=cur->link;
		}
		cur->link=temp;
		temp->link=NULL;
	}	
}

NODE *delete_front()
{
	if(first==NULL)
	{
		printf("\nlist is empty");
		return;
	}
	if(first->link==NULL)
	{
		free(first);
		first=NULL;
		return;
	}
	cur=first;
	first=first->link;
	free(cur);
}

NODE *delete_rear()
{
	if(first==NULL)
	{
		printf("\nList is empty");
		return;
	}
	if(first->link==NULL)
	{
		free(first);
		first=NULL;
		return;
	}
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	free(cur);
	prev->link=NULL;
}

NODE *display()
{
	count=0;
	if(first==NULL)
	{
		printf("\nlist is empty");
		return;
	}
	cur=first;
	printf("\n");
	while(cur!=NULL)
	{
		printf("\n%s\t%s\t%s\t%s\t",cur->usn,cur->name,cur->sem,cur->branch);
		cur=cur->link;
		count++;
	}
	printf("\n No. of student = %d ",count);
}

void stack()
{
	int ch;
	do
	{
		printf("STACK implimentation\n");
		printf("\n1.PUCH \n2.POP\n3.DISPLAY\n4.Back to MENU");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_front();break;
			case 2:delete_front();break;
			case 3:display();break;
			case 4:break;
		}
	}while(ch!=4);
}

void queue()
{
	int ch;
	do
	{
		printf("QUEUE implimentation\n");
		printf("\n1.Insert \n2.Delete\n3.DISPLAY\n4.Back to MENU");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_rear();break;
			case 2:delete_front();break;
			case 3:display();break;
			case 4:break;
		}
	}while(ch!=4);
}

void main()
{
	
	
	while(1)
	{
		int ch,i,j,n;
		printf("\n___MENU___\n");
		printf("\n1.creat\n2.display\n3.insert at rear\n4.delete from rear\n5insert at front\n6.delete at front\n7.STACK operation\n8.QUEUE operation\n9.exit\n");
		printf("----------------");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the no. of student\n");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						insert_rear();
					}
					break;
			case 2:display();break;
			case 3:insert_rear();break;
			case 4:delete_rear();break;
			case 5:insert_front();break;
			case 6:delete_front();break;
			case 7:stack();break;
			case 8:queue();break;
			case 9:exit(0);
			default:printf("Invalid choice");
		}
	}
	
}
