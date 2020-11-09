#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node{
	int co,ex,ey,ez;
	int flag;
	struct node *link;
};
typedef struct node *poly;

poly attach(int c, int x, int y, int z, poly head)
{
	poly temp,cur;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->co=c;
	temp->ex=x;
	temp->ey=y;
	temp->ez=z;
	cur=head;
	while(cur->link!=head)
	{
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=head;
	return head;
}

poly read(poly head)
{
	int ch=1;
	int cf,x,y,z;
	while(ch!=0)
	{
		printf("\nEnter the coeff. and 3 exponent of poly: ");
		scanf("%d%d%d%d",&cf,&x,&y,&z);
		head=attach(cf,x,y,z,head);
		printf("If you wish to continue press 1 otherwise 0 \n ");
		scanf("%d",&ch);
	}
	return head;	
}

void display(poly head)
{
	poly temp;
	if(head->link==head)
	{
		printf("\nPoly does not exist\n");
		return;
	}
	temp=head->link;
	while(temp!=head)
	{
		if(temp->co<0)
			printf("-%d x^%d y^%d z^%d",temp->co,temp->ex,temp->ey,temp->ez);
		else
			printf("+%d x^%d y^%d z^%d",temp->co,temp->ex,temp->ey,temp->ez);
		temp=temp->link;
	}
}

poly add(poly first , poly sec,poly res)
{
	poly a,b;
	int x1,x2,y1,y2,z1,z2,cf1,cf2,cf;
	a=first->link;
	while(a!=first)	
	{
		x1=a->ex;
		y1=a->ey;
		z1=a->ez;
		cf1=a->co;
		b=sec->link;
		while(b!=sec)
		{
			x2=b->ex;
			y2=b->ey;
			z2=b->ez;
			cf2=b->co;
			if(x1==x2 && y1==y2 && z1==z2)
				break;
			b=b->link;
		}
		if(b!=sec)
		{
			cf=cf1+cf2;
			b->flag=1;
			if(cf!=0)
				res=attach(cf,x1,y1,z1,res);
			a=a->link;
		}
		else
		{
			res=attach(cf1,x1,y1,z1,res);
			a=a->link;
		}
		
	}
	b=sec->link;
	while(b!=sec)
	{
		if(b->flag==0)
			res=attach(b->co,b->ex,b->ey,b->ez,res);
		b=b->link;
	}
	return res;
}

void evaluate(poly head)
{
	poly h1;
	int x,y,z;
	int result=0;
	h1=head->link;
	printf("\nEnter value of X Y Z to evaluate: ");
	scanf("%d%d%d",&x,&y,&z);
	while(h1!=head)
	{
		result=result+h1->co*pow(x,h1->ex)*pow(y,h1->ey)*pow(z,h1->ez);
		h1=h1->link;
	}
	printf("\n Poly res. is %d ",result);
}

void main()
{
	int ch;
	poly eval,first,sec,res;
	
	first=(struct node*)malloc(sizeof(struct node));
	sec=(struct node*)malloc(sizeof(struct node));
	eval=(struct node*)malloc(sizeof(struct node));
	res=(struct node*)malloc(sizeof(struct node));
	
	first->link=first;
	sec->link=sec;
	eval->link=eval;
	res->link=res;
	
	printf("\n1Evaluate poly\n2.Add two polynomials\n3.exit\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\nEnter the poly\n");
				eval=read(eval);
				evaluate(eval);
				break;
		case 2:	printf("\nEnter the first poly\n");
				first=read(first);
				printf("\nEnter the sec poly\n");
				sec=read(sec);
				res=add(first,sec,res);
				printf("First poly eq.\n");
				display(first);
				printf("\nSec poly eq.\n");
				display(sec);
				printf("\nresult poly eq.\n");
				display(res);
				break;
		case 3: exit(0);
	}
}
