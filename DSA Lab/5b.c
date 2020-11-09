#include<stdio.h>
int tower(int n,char source,char temp,char destination)
{
	if(n==0)
	{
		return;
	}
	tower(n-1,source,destination,temp);
	printf("\nMove Disk %d from %c to %c\n",n,source,destination);
	tower(n-1,temp,source,destination);
}
void main()
{
	int n;
	printf("enter the no. of disk\n");
	scanf("%d",&n);
	tower(n,'A','B','C');
	printf("NO. of moves = %d ",(int)pow(2,n)-1);
}
