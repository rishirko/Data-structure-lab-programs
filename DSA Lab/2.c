#include<stdio.h>
int c,m,j,i,k,flag=0;
char str[100],rep[100],ans[100],pat[100];

void SM()
{
	i=j=m=c=k=0;
	while(str[c]!='\0')
	{
		if(str[m]==pat[i])
		{
			m++;
			i++;
			if(pat[i]=='\0')
			{
				flag=1;
				for(k=0;rep[k]!='\0';k++,j++)
				{
					ans[j]=rep[k];
					c=m;
					i=0;
				}
			}
		}
		else
		{
			ans[j]=str[c];
			c++;
			j++;
			m=c;i=0;
		}
		ans[j]='\0';
	}
}

void main()
{
	printf("enter main string\n");
	gets(str);
	printf("enter rep. string\n");
	gets(rep);
	printf("enter pat. string\n");
	gets(pat);
	SM();
	if(flag==1)
	{
		printf("resultant string = %s ",ans);
	}
	else
	{
		printf("String NOT match");
	}
	getch();
}
